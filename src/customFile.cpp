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
