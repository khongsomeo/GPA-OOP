/**
 * Utility functions.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef UTILITY_H
#define UTILITY_H

/**
 * Utility class.
 *
 */
class Utility {
public:
  /**
   * This function check if a file exist.
   *
   * @param  std::string
   * @return bool
   */
  static bool isFileExist(std::string fileName) {
    std::ifstream fileTest(fileName);
    return fileTest.good();
  }

  /**
   * This function check if a string is a prefix of another string.
   *
   * @param  std::string
   * @param  std::string
   *
   * @return bool
   */
  static bool isPrefix(std::string haystack, std::string needle) {
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
  static double percent(int x, int y) {
    return x * 100.0 / y;
  }
};

#endif
