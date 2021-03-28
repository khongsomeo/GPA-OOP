/**
 * Output helper.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef OUTPUT_HELPER_H
#define OUTPUT_HELPER_H

#define TEXTART_FILE "data/textart.txt"

class OutputHelper {
public:
  static int                      columnCount;
  static std::vector<std::string> columnTitle;
  static std::vector<int>         columnWidth;
public:
  static void printTextart();

  // Print table element
  static void printTableLine();
  static void printTableRow();
  static void printTableRow(const std::vector<std::string>&);
  static void printTableRow(Subject);
  static void printTableRow(Personal*);

  // Print a full table
  static void printGPATable(Personal*);
  static void printFailedTable(Personal*);
};

#endif
