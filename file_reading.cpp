#include <fstream>
#include <iterator>
#include <string>
#include "file_reading.hpp"

std::string readFileContent(const std::string& filePath) {
  // Opens input-only file (ifstream) in binary mode.
  std::ifstream inFile(filePath, std::ios::in | std::ios::binary);

  // The file is in a bad state. The error can be retrieved
  //	using the global `errno` in linux (#include <cerrno>).
  if (!inFile.is_open()) {
    // exception
  }

  // Read the file to a vector. This is not the most effecient
  //	method to read a file.
  auto content = std::string{std::istreambuf_iterator<char>{inFile},
                             std::istreambuf_iterator<char>{}};

  return content;
}

