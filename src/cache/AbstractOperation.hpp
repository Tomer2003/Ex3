#pragma once
#include "CacheManager.hpp"
#include <string>




namespace AbstractOperation{
    class AbstractOperation{
    private:
        std::string m_operation;
        std::string m_inPutFiles;
        std::string m_outPutFile; 


    public:
        CacheManager::CacheManager& m_cacheManager;
            /**
             * @brief Construct a new Abstract Operation object
             * 
             * @param m_operation - operation
             * @param m_inputFiles - input files of operation
             * @param m_outputFile - output file 
             * @param m_cacheManager - cache manager object
             */
            AbstractOperation(const std::string& operation, const std::string& inPutFiles, const std::string& outPutFile, CacheManager::CacheManager& cacheManager);

            /**
             * @brief The function check if the parameters are appopriate
             * 
             * @return true - parameters are appopriate
             * @return false - parameters are not appopriate
             */
            virtual void checkParameters() const = 0;

            /**
             * @brief The function do the operation of the user
             * 
             */
            virtual void doOperation() = 0;

            /**
             * @brief The functoin return hash of operation
             * 
             * @return const std::string 
             */
            const virtual std::string getHash() const = 0;

            /**
             * @brief The function write to output file the result of operation
             * 
             */
            virtual void writeToOutPutFileTheResultOperation() const = 0; 

            /**
             * @brief The function return operation string
             * 
             * @return const std::string - operation to return
             */
            const std::string getOperation() const;

            /**
             * @brief The function return input files string
             * 
             * @return const std::string - input files to return 
             */
            const std::string getInPutFiles() const;

            /**
             * @brief The function return output files
             * 
             * @return const std::string - output files to return 
             */
            const std::string getOutPutFile() const;

            /**
             * @brief The function return cache manager object
             * 
             * @return CacheManager::CacheManager& - cache manager object 
             */
            CacheManager::CacheManager& getCacheManager();

            
    };
}