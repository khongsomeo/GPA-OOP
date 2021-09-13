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
   * @param  const std::string&
   * @return bool
   */
  static bool isFileExist(const std::string& fileName) {
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
  static bool isPrefix(
    const std::string& haystack,
    const std::string& needle) {
    auto check = std::mismatch(
      needle.begin(),
      needle.end(),
      haystack.begin()
    );

    return check.first == needle.end();
  }

  /**
   * Check if a parameter exist in list of parameters parsed.
   *
   * @param  const std::vector<std::string>&
   * @param  const std::string&
   *
   * @return bool
   */
  static bool hasParameter(
    const std::vector<std::string>& args,
    const std::string& param) {
    for (auto it = args.begin(); it != args.end(); ++it) {
      if (*it == param) return 1;
    }
    return 0;
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
