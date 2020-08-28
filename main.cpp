#include <string.h>
#include <iostream>
#include <getopt.h>
#include <string>
int main(int argc, char **argv){
    if(!strcmp(argv[1], "matrix")){
        std::cout << "matrix";
    }
    else if(!strcmp(argv[1], "image")){
        std::cout << "image";
    }
    else if(!strcmp(argv[1], "hash")){
        std::cout << "hash";
    }
    else if(!strcmp(argv[1], "cache")){
        std::cout << "cache";
    }
    else{
        std::cerr << "Error: The option does not exist!" << std::endl;
    }
    return 0;







    return 0;
}