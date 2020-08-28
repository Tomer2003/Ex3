#include "Operations.hpp"

namespace Operation{
  
    MatrixOperation::MatrixOperation(std::string operation, std::string inputFiles, std::string outputFile, CacheManager cacheManager)
    : AbstractOperation(operation, inputFiles, outputFile, cacheManager){};

    void MatrixOperation::checkParameters() const{
        std::string operation("add");
        if(getOperation != operation || getOperation != "multiply"){
            //trow operation invalid exception
        }
        if()
    }





    






}