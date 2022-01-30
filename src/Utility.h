/**
 * Utility functions.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <algorithm>
#include <fstream>
#include <string>

/**
 * Utility class.
 *
 */
class Utility {
 public:
  /**
   * This function check if a file exist.
   *
   * @param  const std::string&
   * @return bool
   */
  static bool isFileExist(const std::string &);

  /**
   * This function check if a string is a prefix of another string.
   *
   * @param  const std::string&
   * @param  const std::string&
   *
   * @return bool
   */
  static bool isPrefix(const std::string &, const std::string &);

  /**
   * This function calculate percentage.
   *
   * @param  int
   * @param  int
   *
   * @return double
   */
  static double percent(int, int);
};

#endif  // UTILITY_H
