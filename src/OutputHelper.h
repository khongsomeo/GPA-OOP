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

namespace OutputConstants {
  const std::string TEXTART_FILE = "data/textart.txt";
  const std::vector<std::string> COLUMNS = {
    "class code",
    "credits",
    "grade (10 - scale)",
    "grade (4 - scale)",
    "grade (A - scale)"
  };
  enum {
    FORMAT_TABLE = 1 << 0,
    FORMAT_CSV = 1 << 1
  };
}

class OutputHelper {
private:
  int outputType = 0;

  OutputHelper() {
    // Do nothing
  }

public:
  ~OutputHelper() {
    // Do nothing
  }

  /**
   * Get instance of OutputHelper
   *
   * @return std::shared_ptr<OutputHelper>
   */
  static std::shared_ptr<OutputHelper> instance() {
    static std::shared_ptr<OutputHelper> instance(
      new OutputHelper()
    );

    return instance;
  }

public:
  /**
   * Check if outputing in CSV format.
   *
   * @return bool
   */
  bool isCSVOutput() {
    return outputType & OutputConstants::FORMAT_CSV;
  }

  /**
   * Set output format
   *
   * @param  int
   */
  void setOutputFormat(int flag) {
    outputType |= flag;
  }

  /**
   * Print the textart
   *
   */
  void printTextart() {
    std::ifstream textartFile(OutputConstants::TEXTART_FILE);

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
  void printSeparator() {
    std::cout << std::setfill('-');

    // Print first n - 1 column
    for (int i = 0; i < OutputConstants::COLUMNS.size() - 1; ++i) {
      std::cout << "+"
                << std::setw(
                    OutputConstants::COLUMNS[i].length() + 3);
    }

    // Print last column.
    std::cout << "+"
              << std::setw(
                  OutputConstants::COLUMNS.back().length() + 3)
              << "+" << '\n';
  }

  /**
   * Print a table row.
   *
   * @param  const std::vector<std::string>&
   */
  void printTableRow(
    const std::vector<std::string>& lineData) {
    std::cout << std::setfill(' ');

    for (int i = 0; i < OutputConstants::COLUMNS.size() - 1; ++i) {
      std::cout << "|"
                << std::setw(
                    OutputConstants::COLUMNS[i].length() + 1)
                << lineData[i]
                << " ";
    }

    std::cout << "|"
              << std::setw(
                  OutputConstants::COLUMNS.back().length() + 1)
              << lineData[OutputConstants::COLUMNS.size() - 1]
              << " |" << '\n';
  }

  /**
   * Print a CSV Line, given a vector of string.
   *
   * @param  const std::vector<std::string>
   */
  void printCSVLine(
    const std::vector<std::string>& tableLine) {
    for (int i = 0; i < (int)tableLine.size() - 1; ++i) {
      std::cout << tableLine[i] << ',';
    }

    std::cout << tableLine.back() << '\n';
  }

  /**
   * Print the full table.
   *
   * @param  const std::vector<std::vector<std::string>>>&
   * @param  bool (default = true)
   */
  void printTable(
    const std::vector<std::vector<std::string>>& tableData,
    bool hasConclusion = true) {

    /**
     * If no data, don't print!
     *
     */
    if (tableData.size() == 0) {
      return;
    }

    /**
     * Output in table format
     *
     */
    if (outputType & OutputConstants::FORMAT_TABLE) {
      // Print table line (separator).
      printSeparator();

      // Print table title.
      printTableRow(OutputConstants::COLUMNS);

      // Print table line (separator).
      printSeparator();

      // Print table content.
      for (int i = 0; i < tableData.size() - 1; ++i) {
        printTableRow(tableData[i]);
      }

      // Print conclusion row.
      if (hasConclusion) {
        printSeparator();
      }

      // Print last row.
      printTableRow(tableData[tableData.size() - 1]);

      // Print table line (separator).
      printSeparator();
    }

    /**
     * Output in CSV format
     *
     */
    if (outputType & OutputConstants::FORMAT_CSV) {
      // Print head
      printCSVLine(OutputConstants::COLUMNS);

      // Print data
      for (const std::vector<std::string>& s : tableData) {
        printCSVLine(s);
      }
    }
  }
};
#endif
