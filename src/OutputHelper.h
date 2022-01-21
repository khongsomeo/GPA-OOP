/**
 * OutputHelper.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef OUTPUT_HELPER_H
#define OUTPUT_HELPER_H

#include<vector>
#include<string>
#include<fstream>
#include<memory>
#include<iomanip>
#include<iostream>

/**
 * Constants for output
 *
 */
namespace OutputConstants {
  // Default path for the textart file.
  const std::string TEXTART_FILE = "data/textart.txt";

  // Default column name
  const std::vector<std::string> COLUMNS = {
    "class code",
    "credits",
    "grade (10 - scale)",
    "grade (4 - scale)",
    "grade (A - scale)"
  };

  // Flags for input.
  enum {
    FORMAT_TABLE = 1 << 0,
    FORMAT_CSV = 1 << 1
  };
}

class OutputHelper {
private:
  int _outputFlag = 0;

  OutputHelper();

private:
  /**
   * Print a separator line.
   *
   */
  void printSeparator();

  /**
   * Print a table row.
   *
   * @param  const std::vector<std::string>&
   */
  void printTableRow(const std::vector<std::string>&);

  /**
   * Print a CSV Line, given a vector of string.
   *
   * @param  const std::vector<std::string>
   */
  void printCSVLine(const std::vector<std::string>&);

  /**
   * Print ta table in CSV format.
   *
   * @param  const std::vector<std::vector<std::string>>&
   */
  void printTableCSV(const std::vector<std::vector<std::string>>&);

  /**
   * Print table in format.
   *
   * @param  const std::vector<std::vector<std::string>>&
   */
  void printTableFormat(const std::vector<std::vector<std::string>>&);

public:
  ~OutputHelper();

  /**
   * Get instance of OutputHelper
   *
   * @return std::shared_ptr<OutputHelper>
   */
  static std::shared_ptr<OutputHelper> instance();

public:
  /**
   * Check if outputing in CSV format.
   *
   * @return bool
   */
  bool isCSVOutput();

  /**
   * Set output flag
   *
   * @param  int
   */
  void setOutputFlag(int);
  
  /**
   * Print the textart
   *
   */
  void printTextart();
  
  /**
   * Print the full table.
   *
   * @param  const std::vector<std::vector<std::string>>>&
   */
  void printTable(const std::vector<std::vector<std::string>>&);
};
#endif
