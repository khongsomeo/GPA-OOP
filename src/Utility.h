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

#define TEXTART_FILE "data/textart.txt"

class Utility {
public:
  static bool isFileExist(std::string);
  static double percent(int, int);
  static void printTextart();
};

#endif
