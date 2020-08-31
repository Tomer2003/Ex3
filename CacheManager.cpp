#include "CacheManager.hpp"
#include "file_reading.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#define OPERATION_NOT_FOUND -1
#define CACHE_FILE_NAME "cacheFile.txt"


namespace CacheManager{
    
    CacheManager::CacheManager(const unsigned int cacheSize)
    : m_cacheFile(CACHE_FILE_NAME), m_cacheSize(cacheSize){
        setDataToMapFromFile();
    }

 

    void CacheManager::setDataToMapFromFile(){
        std::ifstream inFile(m_cacheFile);
        if(inFile.is_open()){
            auto lineNumber = 0;
            std::string line;
            while (std::getline(inFile, line))
            {
            m_cache.insert({lineNumber, line});
            ++lineNumber;
            }
            inFile.close();
        }
    }

    const std::string CacheManager::getOutPutFileOfKey(unsigned int key){
        return m_cache[key].substr( 0, m_cache[key].find(' '));
    }


    void CacheManager::setDataToFileFromMap(){
        std::ofstream outFile(m_cacheFile, std::ios::out | std::ios::trunc);
        if(!outFile.is_open()){
            std::cerr << "Error: Fail to open cache file for writing!" << std::endl;
            exit(1);
        }
        for (auto const& pair : m_cache){
           outFile << pair.second << std::endl;
        }
        outFile.close();
    }


    void CacheManager::clearCache(){
        m_cache.clear();
    }


    int CacheManager::searchCache(std::string hash, bool printResult) {
        bool valueFound = false;
        unsigned int keyOfValue = OPERATION_NOT_FOUND;
        for (auto const& pair : m_cache){
            auto splitIndex = pair.second.find(' ');
            if(pair.second.substr(splitIndex + 1, pair.second.size() - splitIndex - 1) == hash){
                valueFound = true;
                keyOfValue = pair.first;
            }
        }
        if(valueFound && printResult){
            std::cout << "result found in cache!" << std::endl;
        }
        else if(printResult){
            std::cout << "result not found in cache!" << std::endl;
        }
        return keyOfValue;
    } 


    bool CacheManager::addOperation(std::string hash, std::string outPutFile){
            auto operationInCache = false;
            std::ofstream outFile(outPutFile, std::ios::out | std::ios::trunc);
            if(!outFile.is_open()){
                std::cerr << "Error: Fail to open output file for writing!" << std::endl;
                exit(1);
            }
            auto keyOfValue = searchCache(hash, false);
            //the value in cache
            if(keyOfValue != OPERATION_NOT_FOUND){
                operationInCache = true;
                std::string dataFileName = m_cache[keyOfValue].substr(0, m_cache[keyOfValue].find(' '));
                if(dataFileName != outPutFile){
                    std::ifstream inFile(dataFileName, std::ios::in);
                    if(!inFile.is_open()){
                        outFile.close();
                        std::cerr << "Error: Fail to open data file of operation for reading!" << std::endl;
                        exit(1);
                    }
                    auto content = std::string{std::istreambuf_iterator<char>{inFile},
                                    std::istreambuf_iterator<char>{}};
                    inFile.close();
                    outFile << content;
                    outFile.close();

                    //change order of cache
                    auto valueOfKey = m_cache[keyOfValue];
                    m_cache.erase(keyOfValue);
                    if(m_cache.empty()){
                        m_cache.insert({0, outPutFile + " " +  hash});
                    }
                    else{
                        m_cache.insert({(--m_cache.end())->first + 1, valueOfKey});
                    }
                }
            }
            //the value not in cache
            else{
                //over values(need to remove a value)
                if(m_cache.size() > m_cacheSize - 1){
                    m_cache.erase(m_cache.begin()->first);
                }

                if(m_cache.empty()){
                    m_cache.insert({0, outPutFile + " " +  hash});
                }
                else{
                    m_cache.insert({(--m_cache.end())->first + 1, outPutFile + " " +  hash});
                }
                outFile.close();
            }
            return operationInCache;
    }
}
