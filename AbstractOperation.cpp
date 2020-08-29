
#include "AbstractOperation.hpp"

namespace AbstractOperation{
    AbstractOperation::AbstractOperation(const std::string& operation, const std::string& inPutFiles, const std::string& outPutFile, const CacheManager::CacheManager& cacheManager)
    : m_operation(operation), m_inPutFiles(inPutFiles), m_outPutFile(outPutFile), m_cacheManager(cacheManager){};

    const std::string AbstractOperation::getOperation() const{
        return m_operation;
    }

    const std::string AbstractOperation::getInPutFiles() const{
        return m_inPutFiles;
    }

    const std::string AbstractOperation::getOutPutFile() const{
        return m_outPutFile;
    }

    CacheManager::CacheManager& AbstractOperation::getCacheManager(){
        return m_cacheManager;
    }
}