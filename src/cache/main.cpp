
#include "Operations.hpp"
#include <stdint.h>
#include <iostream>
#include <memory>
#define MAX_NUMBER_OF_CACHE_DATA 5

int main(int argc, char** argv){
    
    CacheManager::CacheManager cacheManager(MAX_NUMBER_OF_CACHE_DATA);
    if(argc < 3){
      std::cerr << "Error: Wrong arguments!" << std::endl;
      exit(1);
    }
    std::string option = std::string{argv[1]}, operation, inPutFiles, outPutFile;
    if(option == "cache"){
      if(std::string{argv[2]} == "clear"){
        cacheManager.clearCache();
        cacheManager.setDataToFileFromMap();
      }
      else if(std::string{argv[2]} == "search"){
        if(std::string{argv[3]} == "matrix"){
          if(argc != 7){
            std::cerr << "Error: Wrong arguments!" << std::endl;
            exit(1);
          }
          Operation::MatrixOperation matrixOperation(std::string{argv[4]}, std::string{argv[5]} + " " + std::string{argv[6]}, "", cacheManager);
          cacheManager.searchCache(matrixOperation.getHash(), true);
        }
        else{
          if(argc != 6){
            std::cerr << "Error: Wrong arguments!" << std::endl;
            exit(1);
          }
          std::shared_ptr<AbstractOperation::AbstractOperation> operationPtr = Operation::operationFactory(std::string{argv[3]}, std::string{argv[4]}, std::string{argv[5]}, "", cacheManager);
          cacheManager.searchCache(operationPtr->getHash(), true);
        }
      }
    }
    else{
      operation = std::string{argv[2]};
      if(std::string{argv[1]} == "matrix"){
        if(argc != 6){
          std::cerr << "Error: Wrong arguments!" << std::endl;
          exit(1);
        }
        inPutFiles = std::string{argv[3]} + " " + std::string{argv[4]};
        outPutFile = std::string{argv[5]};
      }
      else{
        if(argc != 5){
          std::cerr << "Error: Wrong arguments!" << std::endl;
          exit(1);
        }
        inPutFiles = std::string{argv[3]};
        outPutFile = std::string{argv[4]};
      }
      std::shared_ptr<AbstractOperation::AbstractOperation> operationPtr = Operation::operationFactory(option, operation, inPutFiles, outPutFile, cacheManager);
      operationPtr->doOperation();
      cacheManager.setDataToFileFromMap();
    }
    return 0;
}
