#include "Operations.hpp"

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

    void MatrixOperation::doOperation() const{
        
    }
}