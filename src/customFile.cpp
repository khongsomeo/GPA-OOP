/**
 * Implementation of functions defined in customFile.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "customFile.h"

/**
 * This function check if a file exist.
 *
 * @param  std::string
 * @return bool
 */
bool isFileExist(std::string fileName) {
  std::ifstream fileTest(fileName);
  return fileTest.good();
}

/**
 * This function check if a file is a valid .csv file.
 *
 *
 * @param  std::string
 * @return bool
 */
bool isFileCSV(std::string fileName) {
  std::string extension = fileName.substr(fileName.length() - 4);

  return !extension.compare(".csv");
}
