#pragma once
#include "CacheManager.hpp"
#include "AbstractOperation.hpp"
#include <string>

namespace Operation{
    class MatrixOperation : public AbstractOperation::AbstractOperation{
    private:
        std::string m_firstInPutFile;
        std::string m_secondInPutFile;    
    public:
        /**
         * @brief Construct a new Matrix Operation object
         * 
        * @param m_operation - operation
        * @param m_inputFiles - input files of operation
        * @param m_outputFile - output file 
        * @param m_cacheManager - cache manager object
         */
        MatrixOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager);

        /**
        * @brief The function check if the parameters are appopriate
        * 
        * @return true - parameters are appopriate
        * @return false - parameters are not appopriate
        */
        virtual void checkParameters() const;
        
        /**
         * @brief The functoin return hash of operation
         * 
         * @return const std::string 
         */
        const virtual std::string getHash() const;

        /**
         * @brief The function do the operation of the user
         * 
         */
        virtual void doOperation();

        /**
         * @brief The function write to output file the result of operation
         * 
         */
        virtual void writeToOutPutFileTheResultOperation() const; 

        /**
         * @brief The function return the string result of operation
         * 
         * @return const std::string - string result of operation
         */
        const std::string getStringOfTheResultOperation() const;
    };

    class ImageOperation : public AbstractOperation::AbstractOperation{
    public:
       /**
        * @brief Construct a new Image Operation object
        * 
        * @param m_operation - operation
        * @param m_inputFiles - input files of operation
        * @param m_outputFile - output file 
        * @param m_cacheManager - cache manager object
        */
        ImageOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager);

         /**
        * @brief The function check if the parameters are appopriate
        * 
        * @return true - parameters are appopriate
        * @return false - parameters are not appopriate
        */
        virtual void checkParameters() const;

        /**
         * @brief The functoin return hash of operation
         * 
         * @return const std::string 
         */
        const virtual std::string getHash() const;

        /**
         * @brief The function do the operation of the user
         * 
         */
        virtual void doOperation();

        /**
         * @brief The function write to output file the result of operation
         * 
         */
        virtual void writeToOutPutFileTheResultOperation() const; 
    };



    class HashOperation : public AbstractOperation::AbstractOperation{
    public:    
        /**
        * @brief Construct a new Hash Operation object
        * 
        * @param m_operation - operation
        * @param m_inputFiles - input files of operation
        * @param m_outputFile - output file 
        * @param m_cacheManager - cache manager object
        */
        HashOperation(const std::string& operation, const std::string inputFiles, const std::string outputFile, CacheManager::CacheManager& cacheManager);

         /**
        * @brief The function check if the parameters are appopriate
        * 
        * @return true - parameters are appopriate
        * @return false - parameters are not appopriate
        */
        virtual void checkParameters() const;

        /**
         * @brief The functoin return hash of operation
         * 
         * @return const std::string 
         */
        const virtual std::string getHash() const;

        /**
         * @brief The function do the operation of the user
         * 
         */
        virtual void doOperation();

        /**
         * @brief The function write to output file the result of operation
         * 
         */
        virtual void writeToOutPutFileTheResultOperation() const; 
    };




















}