#include "CacheManager.hpp"
#include "file_reading.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#define OPERATION_NOT_FOUND -1
namespace CacheManager{
    CacheManager::CacheManager(const unsigned int cacheSize)
    : m_cacheFile("cacheFile.txt"), m_cacheSize(cacheSize){
        setDataToMapFromFile();
    }


    void CacheManager::setDataToMapFromFile(){
        std::ifstream inFile(m_cacheFile);
        if(!inFile.is_open()){
            inFile.close();
            //throw error!
        }
        auto lineNumber = 0;
        std::string line;
        while (std::getline(inFile, line))
        {
           m_cache.insert({lineNumber, line});
           ++lineNumber;
        }
        inFile.close();
    }

    const std::string CacheManager::getOutPutFileOfKey(unsigned int key){
        return m_cache[key].substr( m_cache[key].find(' ') + 1, m_cache[key].size() -  m_cache[key].find(' ') - 1);
    }


    void CacheManager::setDataToFileFromMap(){
        std::ofstream outFile(m_cacheFile, std::ios::out | std::ios::trunc);
        if(!outFile.is_open()){
            outFile.close();
            //throw exception!
        }
        for (auto const& pair : m_cache){
           outFile << pair.second << std::endl;
        }
        outFile.close();
    }


    void CacheManager::clearCache(){
        m_cache.clear();
    }


    unsigned int CacheManager::searchCache(const AbstractOperation::AbstractOperation& operation) const{
        bool valueFound = false;
        unsigned int keyOfValue = OPERATION_NOT_FOUND;
        std::string valueToSearch = operation.getHash();
        for (auto const& pair : m_cache){
            auto splitIndex = pair.second.find(' ');
            if(pair.second.substr(splitIndex + 1, pair.second.size() - splitIndex - 1) == valueToSearch){
                valueFound = true;
                keyOfValue = pair.first;
            }
        }
        if(valueFound){
            std::cout << "result found in cache!" << std::endl;
        }
        else{
            std::cout << "result not found in cache!" << std::endl;
        }
        return keyOfValue;
    } 


    void CacheManager::addOperation(const AbstractOperation::AbstractOperation& operation){
            std::ofstream outFile(operation.getOutPutFile(), std::ios::out | std::ios::trunc);
            if(!outFile.is_open()){
                outFile.close();
                //trow exception!
            }
            auto keyOfValue = searchCache(operation);
            //the value in cache
            if(keyOfValue != OPERATION_NOT_FOUND){
                std::string dataFileName = m_cache[keyOfValue].substr(0, m_cache[keyOfValue].find(' '));
                std::ifstream inFile(dataFileName, std::ios::in);
                if(!inFile.is_open()){
                    inFile.close();
                    //trow exception!
                }
                auto content = std::string{std::istreambuf_iterator<char>{inFile},
                                std::istreambuf_iterator<char>{}};
                inFile.close();
                outFile << content;
                outFile.close();

                //change order of cache
                auto valueOfKey = m_cache[keyOfValue];
                m_cache.erase(keyOfValue);
                m_cache.insert({(--m_cache.end())->first + 1, valueOfKey});
            }
            //the value not in cache
            else{
                //over values(need to remove a value)
                if(m_cache.size() + 1 > m_cacheSize){
                    m_cache.erase(m_cache.begin()->first);
                }

                m_cache.insert({(--m_cache.end())->first + 1, operation.getOutPutFile() + " " +  operation.getHash()});
                operation.writeToOutPutFileTheResultOperation();
                outFile.close();
            }
    }
}
