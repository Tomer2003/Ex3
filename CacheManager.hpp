#pragma once
#include "AbstractOperation.hpp"
#include <string>
#include <map> 
namespace CacheManager{

    //immutable CacheManager class
    class CacheManager{
    private:
        const std::string m_cacheFile;
        const unsigned int m_cacheSize;
        std::map<unsigned int, std::string> m_cache;
    public:
        /**
         * @brief Construct a new Cache Manager object.
         * 
         * @param cacheSize - cache size.
         */
        CacheManager(const unsigned int cacheSize);
        
        /**
         * @brief The function clear all pairs in the cache.
         * 
         */
        void clearCache();

        /**
         * @brief The function add operation to cache and create out put file with data operation.
         * 
         * @param operation - operation to add to cache.
         */
        void addOperation(const AbstractOperation::AbstractOperation& operation);

        /**
         * @brief The function check if the operation exist in the cache.
         * 
         * @param operation - operation to check if exist in the cache.
         * @return int - return -1 if does not exist and return the key if exist.
         */
        unsigned int searchCache(const AbstractOperation::AbstractOperation& operation) const;

        /**
         * @brief The function set data to map from cache file.
         * 
         */
        void setDataToMapFromFile();

        /**
         * @brief The function write data to cache file from map.
         * 
         */
        void setDataToFileFromMap();

        /**
         * @brief The function return outputfile of key
         * 
         * @param key - key to get output file
         * @return std::string - output file
         */
        const std::string getOutPutFileOfKey(unsigned int key);
    }; 
}