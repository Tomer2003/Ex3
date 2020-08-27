#include "CacheManager.hpp"
#include <fstream>
#define NUMBER_OF_BLANCKED_CHARACTERS 5
namespace CacheManager{
    CacheManager::CacheManager(std::string cacheFile, unsigned int cacheSize)
    : cacheFile(cacheFile), cacheSize(cacheSize){}

    void CacheManager::clearCache(){
        cache.clear();
    }
/*
    bool CacheManager::addOperation(AbstractOperation operation){
          for (std::map<unsigned int, AbstractOperation>::iterator it=cache.begin(); it != cache.end(); ++it){


          }
    }
}*/
   /* CacheManager::CacheManager(std::string cachePath) : cachePath(cachePath) {}

    CacheManager* CacheManager::getSingletonCacheManager(std::string cachePath){
       if(!CacheManager::singeltonCacheManager){
           singeltonCacheManager = new CacheManager(cachePath);
       }
       return singeltonCacheManager;
   }

   void CacheManager::clearCache() const{
       std::ofstream out(cachePath,  std::ios::trunc);
       if(!out.is_open()){
           //throw exception
       }
   }

   void CacheManager::addOperation(const AbsractOperation& operationToAdd) const{
        std::ofstream out(cachePath,  std::ios::out);
        if(!out.is_open()){
           //throw exception
        }
        out.write(operationToAdd.getOperation() + " " + operationToAdd.getInputFilesForOperation() + " " + operationToAdd.getoutputPath() + " " + operationToAdd.getDate() + " \n", 
               operationToAdd.getOperation().size() + operationToAdd.getInputFilesForOperation().size() + operationToAdd.getoutputPath().size() + operationToAdd.getDate().size() + NUMBER_OF_BLANCKED_CHARACTERS);
        out.close();       
   }



    bool CacheManager::searchOperation(std::string operationToSearch) const{
        std::ifstream in(cachePath,  std::ios::in);
        if(!in.is_open()){
           //throw exception
        }
        
     }
*/



























}