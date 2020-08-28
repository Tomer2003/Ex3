#include "AbstractOperation.hpp"

namespace AbstractOperation{
    AbstractOperation::AbstractOperation(std::string operation, std::string inputFiles, std::string outputFile, CacheManager cacheManager)
    : m_operation(operation), m_inputFiles(inputFiles), m_outputFile(outputFile), m_cacheManager(cacheManager){};
}