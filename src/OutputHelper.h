/**
 * OutputHelper.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#pragma once

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef OUTPUT_HELPER_H
#define OUTPUT_HELPER_H

const std::string TEXTART_FILE = "data/textart.txt";
const int         COLUMN_COUNT = 5;
const std::vector<int> COLUMN_WIDTH = {12, 9, 20, 19, 19};
const std::vector<std::string> COLUMN_TITLE = {
  "class code",
  "credits",
  "grade (10 - scale)",
  "grade (4 - scale)",
  "grade (A - scale)"
};

class OutputHelper {
public:
  /**
   * Print the textart
   *
   */
  static void printTextart() {
    std::ifstream textartFile(TEXTART_FILE);

    std::string buffer;
    while (std::getline(textartFile, buffer)) {
      std::cout << buffer << '\n';
    }

    std::cout << '\n';

    textartFile.close(); 
  }

  /**
   * Print a separator line.
   *
   */
  static void printSeparator() {
    std::cout << std::setfill('-');

    // Print first n - 1 column
    for (int i = 0; i < COLUMN_COUNT - 1; ++i) {
      std::cout << "+"
                << std::setw(COLUMN_WIDTH[i] + 1);
    }

    // Print last column.
    std::cout << "+"
              << std::setw(COLUMN_WIDTH[COLUMN_COUNT - 1] + 2)
              << "+" << '\n';
  }

  /**
   * Print a table row.
   *
   * @param  const std::vector<std::string>&
   */
  static void printTableRow(const std::vector<std::string>& lineData) {
    std::cout << std::setfill(' ');

    for (int i = 0; i < COLUMN_COUNT - 1; ++i) {
      std::cout << "|"
                << std::setw(COLUMN_WIDTH[i] - 1)
                << lineData[i]
                << " ";
    }

    std::cout << "|"
              << std::setw(COLUMN_WIDTH[COLUMN_COUNT - 1])
              << lineData[COLUMN_COUNT - 1]
              << " |" << '\n';
  }

  /**
   * Print the full table.
   *
   * @param  const std::vector<std::vector<std::string>>>&
   * @param  bool (default = true)
   */
  static void printTable(const std::vector<std::vector<std::string>>& tableData, bool hasConclusion = true) {
    printSeparator();
  
    // Print table title.
    printTableRow(COLUMN_TITLE);
  
    printSeparator();

    // Print table content.
    for (int i = 0; i < tableData.size() - 1; ++i) {
      printTableRow(tableData[i]);
    }

    if (hasConclusion)
      printSeparator();

    // Print last row.
    printTableRow(tableData[tableData.size() - 1]);

    printSeparator();
  }
};
#endif
