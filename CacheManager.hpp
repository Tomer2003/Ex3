#pragma once
#include <string>
#include <map> 
namespace CacheManager{

    //immutable CacheManager class
    class CacheManager{
    private:
        std::string cacheFile;
        unsigned int cacheSize;
        std::map<unsigned int, AbstractOperation> cache;
    public:
        CacheManager(std::string cacheFile, unsigned int cacheSize);

        void clearCache();

        bool addOperation(AbstractOperation operation);

        void searchCache() const;
    }; 
}