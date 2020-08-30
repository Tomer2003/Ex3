cmake_minimum_required(VERSION 3.0.0)
project(tester VERSION 0.1.0)

include(CTest)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)
enable_testing()

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
add_library(
    ClassMatrix
    ClassMatrix.cpp
    ClassMatrix.hpp
)

add_library(
    Exceptions
    MatrixExceptions.cpp
    MatrixExceptions.hpp
)

add_library(
    AbstractOperation
    AbstractOperation.cpp
    AbstractOperation.hpp
)

add_library(
    Operations
    Operations.cpp
    Operations.hpp
)

add_library(
    CacheManager
    CacheManager.cpp
    CacheManager.hpp
)

add_library(
    fileReader
    file_reading.cpp
    file_reading.hpp
)



# Add the libmatrix file to the include path - so that
#   we can include it as without explicitly specifying 
#   the files directory.
include_directories(${CMAKE_SOURCE_DIR}/matrix)
# Link directories - tells the linker to look for .so files
#   in these directories. We want libmatrix.so which is under 
#the matrix directory. Note that a full path is required.
link_directories(${CMAKE_SOURCE_DIR}/matrix)
add_executable(tester main.cpp MatrixExceptions.cpp ClassMatrix.cpp CacheManager.cpp AbstractOperation.cpp Operations.cpp file_reading.cpp crc32.c bmp/BitMap.cpp bmp/BitMapFactory.cpp bmp/BitMapHelpFunctions.cpp bmp/bmp_tester.cpp bmp/Headers.cpp bmp/Exceptions.cpp) 
# Links out executable with matrix. ld (the linker) will automatically
#   add the 'lib' prefix and 'so' suffix, which will result in libmatrix.so
target_link_libraries(tester matrix Exceptions ClassMatrix AbstractOperation CacheManager Operations fileReader)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)