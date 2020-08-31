#include "../matrix/ClassMatrix.hpp"
#include "Operations.hpp"
#include "CacheManager.hpp"
#include "../file_reading.hpp"
#include "../bmp/bmp_tester.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
extern "C" {
#include "../crc32/crc32.h"
}
#define OPERATION_NOT_FOUND -1

namespace Operation{
  
    MatrixOperation::MatrixOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager)
    : AbstractOperation::AbstractOperation(operation, inputFiles, outputFile, cacheManager){
        checkParameters();
        m_firstInPutFile = inputFiles.substr(0, inputFiles.find(' '));
        m_secondInPutFile = inputFiles.substr(inputFiles.find(' ') + 1, inputFiles.size() - inputFiles.find(' ') - 1);
    }

    void MatrixOperation::checkParameters() const{
        if(getOperation() != "add" && getOperation() != "multiply"){
            std::cerr << "Error: Wrong Operation!" << std::endl;
            exit(1);
        }
        if (getInPutFiles().find(' ') == std::string::npos) {
		    std::cerr << "Error: Wrong arguments!" << std::endl;
            exit(1);
	    }
    }

    const std::string MatrixOperation::getHash() const{
        std::string stringOperation = matrix::Matrix::getMatrixFromFile(m_firstInPutFile).getStringOfMatrix() + getOperation() + matrix::Matrix::getMatrixFromFile(m_secondInPutFile).getStringOfMatrix();
        const unsigned char* unsignedStringOperation = reinterpret_cast<const unsigned char *>(stringOperation.c_str());
        std::string hashOfOperation = std::to_string(calculate_crc32c(0, unsignedStringOperation, stringOperation.size()));
        return hashOfOperation;
    }


    const std::string MatrixOperation::getStringOfTheResultOperation() const{
        matrix::Matrix result(1, 1);
        matrix::Matrix firstMatrix = matrix::Matrix::getMatrixFromFile(m_firstInPutFile);
        matrix::Matrix secondMatrix = matrix::Matrix::getMatrixFromFile(m_secondInPutFile);
        if(getOperation() == "add"){
            result = firstMatrix + secondMatrix;
        }
        else{
            result = firstMatrix * secondMatrix;
        }
        std::string matrixStr = result.getStringOfMatrix();
        return matrixStr;
    }

    void MatrixOperation::writeToOutPutFileTheResultOperation() const{
        std::ofstream outFile(getOutPutFile(), std::ios::out);
        if(!outFile.is_open()){
            std::cerr << "Error: Fail to open output file for writing!" << std::endl;
            exit(1);
        }
        outFile << getStringOfTheResultOperation();
        outFile.close();
    }


    void MatrixOperation::doOperation(){
        auto keyOfOperation = getCacheManager().searchCache(getHash(), false);
        //print the reult operation
        if(getOutPutFile() == "stdout"){
            //operation found in cache
            if(keyOfOperation != OPERATION_NOT_FOUND){
                std::string outPutFileOperation = getCacheManager().getOutPutFileOfKey(keyOfOperation);
                matrix::Matrix outPutFileMatrix = matrix::Matrix::getMatrixFromFile(outPutFileOperation);
                outPutFileMatrix.printMatrix();
            }
            //operation not found in cache
            else{
                std::cout << getStringOfTheResultOperation();
            }
        }
        //save result in cache
        else{
            auto operationAlreadyInCache = getCacheManager().addOperation(getHash(), getOutPutFile());
             if(!operationAlreadyInCache){
                writeToOutPutFileTheResultOperation();
            }
        }       
    }

    ImageOperation::ImageOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager)
    : AbstractOperation::AbstractOperation(operation, inputFiles, outputFile, cacheManager){
        checkParameters();
    }


    void ImageOperation::checkParameters() const{
        if(getOperation() != "convert" && getOperation() != "rotate"){
            std::cerr << "Error: Wrong Operation!" << std::endl;
            exit(1);
        }
    }

    const std::string ImageOperation::getHash() const{
        std::string stringOperation = readFileContent(getInPutFiles()) + getOperation();
        const unsigned char* unsignedStringOperation = reinterpret_cast<const unsigned char *>(stringOperation.c_str());
        std::string hashOfOperation = std::to_string(calculate_crc32c(0, unsignedStringOperation, stringOperation.size()));
        return hashOfOperation;
    }

    void ImageOperation::writeToOutPutFileTheResultOperation() const{
        if(getOperation() == "convert"){
            bmpOperations::convert_to_grayscale(getInPutFiles(), getOutPutFile());
        }
        else{
            bmpOperations::rotate_image(getInPutFiles(), getOutPutFile());
        }
    }

    void ImageOperation::doOperation(){
        auto operationAlreadyInCache = getCacheManager().addOperation(getHash(), getOutPutFile());
        if(!operationAlreadyInCache){
                writeToOutPutFileTheResultOperation();
        }
    }

    HashOperation::HashOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager)
    : AbstractOperation::AbstractOperation(operation, inputFiles, outputFile, cacheManager){
        checkParameters();
    }

    void HashOperation::checkParameters() const{
        if(getOperation() != "crc32"){
            std::cerr << "Error: Wrong Operation!" << std::endl;
            exit(1);
        }
    }

    const std::string HashOperation::getHash() const{
        std::string stringOperation = readFileContent(getInPutFiles()) + getOperation();
        const unsigned char* unsignedStringOperation = reinterpret_cast<const unsigned char *>(stringOperation.c_str());
        std::string hashOfOperation = std::to_string(calculate_crc32c(0, unsignedStringOperation, stringOperation.size()));
        return hashOfOperation;
    }

    const std::string HashOperation::getStringOfTheResultOperation() const{
        std::string stringToDoHash = readFileContent(getInPutFiles());
        const unsigned char* charsOfHash = reinterpret_cast<const unsigned char *>(stringToDoHash.c_str());
        uint32_t hash = calculate_crc32c(0, charsOfHash, stringToDoHash.size());
        return std::to_string(hash);
    }

    void HashOperation::doOperation(){
         auto keyOfOperation = getCacheManager().searchCache(getHash(), false);
        //print the reult operation
        if(getOutPutFile() == "stdout"){
            //operation found in cache
            if(keyOfOperation != OPERATION_NOT_FOUND){
                std::string outPutFileOperation = getCacheManager().getOutPutFileOfKey(keyOfOperation);
                std::cout << outPutFileOperation << std::endl;
            }
            //operation not found in cache
            else{
                std::cout << getStringOfTheResultOperation() << std::endl;
            }
        }
        //save result in cache
        else{
            auto operationAlreadyInCache = getCacheManager().addOperation(getHash(), getOutPutFile());
             if(!operationAlreadyInCache){
                writeToOutPutFileTheResultOperation();
            }
        }       
    }

    void HashOperation::writeToOutPutFileTheResultOperation() const{
         std::ofstream outFile(getOutPutFile(), std::ios::out);
        if(!outFile.is_open()){
            std::cerr << "Error: Fail to open output file for writing!" << std::endl;
            exit(1);
        }
        outFile << getStringOfTheResultOperation();
        outFile.close();
    }

    std::shared_ptr<AbstractOperation::AbstractOperation> operationFactory(const std::string& option, const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager){
        std::shared_ptr<AbstractOperation::AbstractOperation> abstractOperationPtr;
        if(option == "matrix"){
            abstractOperationPtr = std::make_shared<Operation::MatrixOperation>(Operation::MatrixOperation(operation, inputFiles, outputFile, cacheManager));
        }
        else if(option == "image"){
            abstractOperationPtr = std::make_shared<Operation::ImageOperation>(Operation::ImageOperation(operation, inputFiles, outputFile, cacheManager));
        }
        else if(option == "hash"){
            abstractOperationPtr = std::make_shared<Operation::HashOperation>(Operation::HashOperation(operation, inputFiles, outputFile, cacheManager));
        }
        else{
            std::cerr << "Error: The option does not exist!" << std::endl;
            exit(1);
        }
        return abstractOperationPtr;
    }
}