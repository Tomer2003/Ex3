#include "CacheManager.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#define NUMBER_OF_BLANCKED_CHARACTERS 5
#define VALUE_NOT_FOUND -1
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


    int CacheManager::searchCache(const AbstractOperation& operation) const{
        bool valueFound = false;
        int keyOfValue = VALUE_NOT_FOUND;
        std::string valueToSearch = operation.getOutPutFile() + " " +  operation.getHash();
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


    void CacheManager::addOperation(const AbstractOperation& operation){
        std::ofstream outFile(operation.getOutPutFile(), std::ios::out | std::ios::trunc);
        if(!outFile.is_open()){
            outFile.close();
            //trow exception!
        }
        auto keyOfValue = searchCache(operation);
         //the value in cache
        if(keyOfValue != VALUE_NOT_FOUND){
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
        }
        //the value not in cache
        else{
            //over values(need to remove a value)
            if(m_cache.size() + 1 > m_cacheSize){
                m_cache.erase(m_cache.begin()->first);
            }
            m_cache.insert({(--m_cache.end())->first + 1, operation.getOutPutFile() + " " +  operation.getHash()});
            outFile << operation.getDataOfOperationToFile();
            outFile.close();
        }
    }
}