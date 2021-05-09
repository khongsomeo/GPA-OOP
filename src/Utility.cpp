/**
 * Implementation of functions defined in Utility.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "Utility.h"

/**
 * This function check if a file exist.
 *
 * @param  std::string
 * @return bool
 */
bool Utility::isFileExist(std::string fileName) {
  std::ifstream fileTest(fileName);
  return fileTest.good();
}

/**
 * This function check if a string is prefix of another string.
 *
 * @param  std::string
 * @param  std::string
 *
 * @return bool
 */
bool Utility::isPrefix(std::string haystack, std::string needle) {
  auto check =  std::mismatch(needle.begin(), needle.end(), haystack.begin());

  return check.first == needle.end();
}

/**
 * This function calculate percentage.
 *
 * @param  int
 * @param  int
 * @return double
 */
double Utility::percent(int x, int y) {
  return x * 100.0 / y;
}
