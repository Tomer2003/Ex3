#include <iostream>
//#include "Operations.hpp"
extern "C" {
#include "crc32.h"
}
#include <stdint.h>
#include "file_reading.hpp"

int main(){
  // unsigned char arr[10] = {'1', '2', '3', '4','5' ,'6', '7', '8', '9'};
 // std::cout << arr << std::endl;

  //const char* a = readFileContent("data/hash.bin").c_str();
   
   // const char* a = "123456789";
  const unsigned char* t = reinterpret_cast<const unsigned char *>(readFileContent("data/hash.bin").c_str());
    
    uint32_t hash = calculate_crc32c(0, t, 9);
    std::cout << hash << std::endl;

    return 0;
}
