#pragma once
#include <string>
#include <map> 


namespace CacheManager{
    class CacheManager{
    private:
        const std::string m_cacheFile;
        const unsigned int m_cacheSize;
    public:
        std::map<unsigned int, std::string> m_cache;
        /**
         * @brief Construct of a new Cache Manager object
         * 
         * @param cacheSize - size of cache
         */
        CacheManager(const unsigned int cacheSize);

        /**
         * @brief Copy Constructor of a new Cache Manager object
         * 
         * @param cacheManager - cacheManager to copy
         */
       // CacheManager(const CacheManager& cacheManager);

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
        void addOperation( std::string hash, std::string outPutFile);

        /**
         * @brief The function check if the operation exist in the cache.
         * 
         * @param operation - operation to check if exist in the cache.
         * @return int - return -1 if does not exist and return the key if exist.
         */
        int searchCache(std::string hash, bool printResult);

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

