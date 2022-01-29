/**
 * Utility.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "Utility.h"

/**
 * This function check if a file exist.
 *
 * @param  const std::string&
 * @return bool
 */
bool Utility::isFileExist(const std::string &fileName) {
  std::ifstream fileTest(fileName);
  return fileTest.good();
}

/**
 * This function check if a string is a prefix of another string.
 *
 * @param  const std::string&
 * @param  const std::string&
 *
 * @return bool
 */
bool Utility::isPrefix(const std::string &haystack, const std::string &needle) {
  auto check = std::mismatch(needle.begin(), needle.end(), haystack.begin());

  return check.first == needle.end();
}

/**
 * This function calculate percentage.
 *
 * @param  int
 * @param  int
 *
 * @return double
 */
double Utility::percent(int x, int y) { return x * 100.0 / y; }
