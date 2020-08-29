#include "ClassMatrix.hpp"
#include "Operations.hpp"
#include "CacheManager.hpp"
#include <fstream>
#include <iostream>
#define OPERATION_NOT_FOUND -1
namespace Operation{
  
    MatrixOperation::MatrixOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, const CacheManager::CacheManager& cacheManager)
    : AbstractOperation::AbstractOperation(operation, inputFiles, outputFile, cacheManager){
        checkParameters();
        m_firstInPutFile = inputFiles.substr(0, inputFiles.find(' '));
        m_secondInPutFile = inputFiles.substr(inputFiles.find(' ') + 1, inputFiles.size() - inputFiles.find(' ') - 1);
    };

    void MatrixOperation::checkParameters() const{
        if(getOperation() != "add" || getOperation() != "multiply"){
            //trow operation invalid exception
        }
        if (getInPutFiles().find(' ') == std::string::npos) {
		    //throw error not enogh input files
	    }
    }

    const std::string MatrixOperation::getHash() const{
        std::hash<std::string> stringHashFunction;
        std::string hashOfOperation = std::to_string(stringHashFunction(m_firstInPutFile + getOperation() + m_secondInPutFile));
        return hashOfOperation;
    }


    const std::string MatrixOperation::getStringOfTheResultOperation() const{
        matrix::Matrix* result;
        matrix::Matrix firstMatrix = matrix::Matrix::getMatrixFromFile(m_firstInPutFile);
        matrix::Matrix secondMatrix = matrix::Matrix::getMatrixFromFile(m_secondInPutFile);
        if(getOperation() == "add"){
            *result = firstMatrix + secondMatrix;
        }
        else{
            *result = firstMatrix * secondMatrix;
        }
        std::string matrixStr = result->getStringOfMatrix();
        delete result;
        return matrixStr;
    }

    void MatrixOperation::writeToOutPutFileTheResultOperation() const{
        std::ofstream outFile(getOutPutFile(), std::ios::out);
        if(!outFile.is_open()){
            outFile.close();
            //throw exception!
        }
        outFile << getStringOfTheResultOperation();
        outFile.close();
    }


    void MatrixOperation::doOperation(){
        auto keyOfOperation = getCacheManager().searchCache(*this);
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
            getCacheManager().addOperation(*this);
        }       
    }
}