/**
 * OutputHelper.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef OUTPUT_HELPER_H
#define OUTPUT_HELPER_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/**
 * Constants for output
 *
 */
namespace OutputConstants {
// Default path for the textart file.
const std::string TEXTART_FILE = "data/textart.txt";

// Default column name
const std::vector<std::string> COLUMNS = {
    "course code",       "credits",           "grade (10 - scale)",
    "grade (4 - scale)", "grade (A - scale)", "course type"};

// Flags for input.
enum {
  FORMAT_TABLE = 1 << 0,
  FORMAT_CSV = 1 << 1,
  ALLOW_TEXTART = 1 << 2,
  NO_TEXTART = 1 << 3
};
}  // namespace OutputConstants

/**
 * OutputHelper class
 *
 */
class OutputHelper {
 private:
  int _outputFlag = 0;

  /**
   * OutputHelper default constructor
   *
   * @return void
   */
  OutputHelper();

 private:
  /**
   * Print a separator line.
   *
   * @return void
   */
  void printSeparator();

  /**
   * Print a table row.
   *
   * @param  const std::vector<std::string>&
   */
  void printTableRow(const std::vector<std::string> &);

  /**
   * Print a CSV Line, given a vector of string.
   *
   * @param  const std::vector<std::string>
   */
  void printCSVLine(const std::vector<std::string> &);

  /**
   * Print ta table in CSV format.
   *
   * @param  const std::vector<std::vector<std::string>>&
   */
  void printTableCSV(const std::vector<std::vector<std::string>> &);

  /**
   * Print table in format.
   *
   * @param  const std::vector<std::vector<std::string>>&
   */
  void printTableFormat(const std::vector<std::vector<std::string>> &);

 public:
  /**
   * OutputHelper destructor
   *
   * @return void
   */
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
   * Check if user want textart?
   *
   * @return bool
   */
  bool isAllowTextart();

  /**
   * Set output flag
   *
   * @param  int
   */
  void setOutputFlag(int);

  /**
   * Print the textart
   *
   * @return void
   */
  void printTextart();

  /**
   * Print the full table.
   *
   * @param  const std::vector<std::vector<std::string>>>&
   */
  void printTable(const std::vector<std::vector<std::string>> &);
};
#endif  // OUTPUT_HELPER_H
