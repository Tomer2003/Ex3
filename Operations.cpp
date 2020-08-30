#include "ClassMatrix.hpp"
#include "Operations.hpp"
#include "CacheManager.hpp"
#include "file_reading.hpp"
#include "bmp/bmp_tester.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
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
            //trow operation invalid exception
            std::cout << "not appopriate operatoin1" << std::endl;
        }
        if (getInPutFiles().find(' ') == std::string::npos) {
		    //throw error not enogh input files
            std::cout << "not 2 files" << std::endl;
	    }
    }

    const std::string MatrixOperation::getHash() const{
        std::hash<std::string> stringHashFunction;
        std::string hashOfOperation = std::to_string(stringHashFunction(matrix::Matrix::getMatrixFromFile(m_firstInPutFile).getStringOfMatrix() + getOperation() + matrix::Matrix::getMatrixFromFile(m_secondInPutFile).getStringOfMatrix()));
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
            outFile.close();
            //throw exception!
            std::cout << "cant open file for writing result!" << std::endl;
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
    };


    void ImageOperation::checkParameters() const{
        if(getOperation() != "convert" && getOperation() != "rotate"){
            //throw exception false operation name
        }
    }

    const std::string ImageOperation::getHash() const{
        std::hash<std::string> stringHashFunction;
        std::string hashOfOperation = std::to_string(stringHashFunction(readFileContent(getInPutFiles())));
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
        auto keyOfOperation = getCacheManager().searchCache(getHash(), false);
        auto operationAlreadyInCache = getCacheManager().addOperation(getHash(), getOutPutFile());
        if(!operationAlreadyInCache){
                writeToOutPutFileTheResultOperation();
        }
    }
}