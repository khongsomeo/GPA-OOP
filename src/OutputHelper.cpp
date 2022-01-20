/**
 * OutputHelper implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"OutputHelper.h"

OutputHelper::OutputHelper() {
  // Do nothing
}

OutputHelper::~OutputHelper() {
  // Do nothing
}

/**
 * Get instance of OutputHelper
 *
 * @return std::shared_ptr<OutputHelper>
 */
std::shared_ptr<OutputHelper> OutputHelper::instance() {
  static std::shared_ptr<OutputHelper> instance(new OutputHelper());

  return instance;
}

/**
 * Check if outputing in CSV format.
 *
 * @return bool
 */
bool OutputHelper::isCSVOutput() {
  return _outputType & OutputConstants::FORMAT_CSV;
}

/**
 * Set output format
 *
 * @param  int
 */
void OutputHelper::setOutputFormat(int flag) {
  _outputType |= flag;
}

/**
 * Print the textart
 *
 */
void OutputHelper::printTextart() {
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
void OutputHelper::printSeparator() {
  std::cout << std::setfill('-');

  // Print first n - 1 column
  for (int i = 0; i < (int)OutputConstants::COLUMNS.size() - 1; ++i) {
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
void OutputHelper::printTableRow(
    const std::vector<std::string>& lineData) {
  std::cout << std::setfill(' ');

  for (int i = 0; i < (int)OutputConstants::COLUMNS.size() - 1; ++i) {
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
void OutputHelper::printCSVLine(
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
 */
void OutputHelper::printTable(
    const std::vector<std::vector<std::string>>& tableData) {
  /**
   * If no data, don't print!
   *
   */
  if (tableData.size() == 0) {
    return;
  }

  /**
   * Output in table format
   * (without last conclusion row)
   *
   */
  if (_outputType & OutputConstants::FORMAT_TABLE) {
    printTableFormat(tableData, true);
  }

  /**
   * Output in CSV format
   *
   */
  if (_outputType & OutputConstants::FORMAT_CSV) {
    printTableCSV(tableData);
  }
}

/**
 * Print table, with conclusion
 *
 * @param  const std::vector<std::vector<std::string>>&
 * @param  bool
 */
void OutputHelper::printTable(
    const std::vector<std::vector<std::string>>& tableData,
    bool conclusionIgnored) {
  /**
   * If no data, don't print!
   *
   */
  if (tableData.size() == 0) {
    return;
  }

  /**
   * Output in table format
   * (without last conclusion row)
   *
   */
  if (_outputType & OutputConstants::FORMAT_TABLE) {
    printTableFormat(tableData, false);
  }


  /**
   * Output in CSV format
   *
   */
  if (_outputType & OutputConstants::FORMAT_CSV) {
    printTableCSV(tableData);
  }
}

/**
 * Print a table, with format.
 *
 * @param  const std::vector<std::vector<std::string>>&
 * @param  bool
 */
void OutputHelper::printTableFormat(
    const std::vector<std::vector<std::string>>& tableData,
    bool hasConclusion) {
  // Print table line (separator).
  printSeparator();

  // Print table title.
  printTableRow(OutputConstants::COLUMNS);

  // Print table line (separator).
  printSeparator();

  // Print table content.
  for (int i = 0; i < (int)tableData.size() - 1; ++i) {
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
 * Print table in CSV format.
 *
 * @param  const std::vector<std::vector<std::string>>&
 */
void OutputHelper::printTableCSV(
    const std::vector<std::vector<std::string>>& tableData) {
  // Print head
  printCSVLine(OutputConstants::COLUMNS);

  // Print data
  for (const std::vector<std::string>& s : tableData) {
    printCSVLine(s);
  }
}