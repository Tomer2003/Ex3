cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0)

include(CTest)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)
enable_testing()

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
# Add the libmatrix file to the include path - so that
#   we can include it as without explicitly specifying 
#   the files directory.
include_directories(${PARENT_DIR}/matrix)
# Link directories - tells the linker to look for .so files
#   in these directories. We want libmatrix.so which is under 
#the matrix directory. Note that a full path is required.
link_directories(${PARENT_DIR}/matrix)
add_executable(ex3.out main.cpp ${PARENT_DIR}/matrix/MatrixExceptions.cpp ${PARENT_DIR}/matrix/ClassMatrix.cpp CacheManager.cpp AbstractOperation.cpp Operations.cpp ${PARENT_DIR}/file_reading.cpp ${PARENT_DIR}/crc32/crc32.c ${PARENT_DIR}/bmp/BitMap.cpp ${PARENT_DIR}/bmp/BitMapFactory.cpp ${PARENT_DIR}/bmp/BitMapHelpFunctions.cpp ${PARENT_DIR}/bmp/bmp_tester.cpp ${PARENT_DIR}/bmp/Headers.cpp ${PARENT_DIR}/bmp/Exceptions.cpp) 
# Links out executable with matrix. ld (the linker) will automatically
#   add the 'lib' prefix and 'so' suffix, which will result in libmatrix.so
target_link_libraries(ex3.out matrix)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)