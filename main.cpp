#include <iostream>
#include "Operations.hpp"




int main(){
    CacheManager::CacheManager chacheManager(100);
    chacheManager.setDataToMapFromFile();
    Operation::MatrixOperation matrixOperation("add", "data/matrix1.txt data/m3.txt", "data/samem4.txt", chacheManager);
    matrixOperation.doOperation();
    chacheManager.setDataToFileFromMap();


    return 0;
}
