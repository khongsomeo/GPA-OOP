/**
 * Implementation of functions defined inside "OutputHelper.h"
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"OutputHelper.h"

// Total columns
int OutputHelper::columnCount = 5;

// Column size
std::vector<int> OutputHelper::columnWidth = {12, 9, 20, 19, 19};

// Column title
std::vector<std::string> OutputHelper::columnTitle = {"class name", "credits", "grade (10 - scale)", "grade (4 - scale)", "grade (A - scale)"};

/**
 * This function print the textart.
 * (a cooler but not suitable move). 
 */
void OutputHelper::printTextart() {
  // Create a file stream
  std::ifstream fileStream(TEXTART_FILE, std::ios::in);

  // Create a line buffer
  std::string lineBuffer;
  while (getline(fileStream, lineBuffer))
    std::cout << lineBuffer << '\n'; 

  std::cout << '\n';

  fileStream.close();
}

/**
 * This function print a table line.
 *
 */
void OutputHelper::printTableLine() {
  // Set filling.
  std::cout << std::setfill('-');

  // Print first column - 1 column.
  for (int i = 0; i < columnCount - 1; ++i) {
    std::cout << "+"
              << std::setw(columnWidth[i] + 1);
  }

  // Print the last column
  std::cout << "+"
            << std::setw(columnWidth[columnCount - 1] + 2)
            << "+\n";
}

/**
 * This function print the table title.
 *
 */
void OutputHelper::printTableRow() {
  OutputHelper::printTableRow(columnTitle);
}

/**
 * This function print the table.
 *
 * @param  const std::vector<std::string>&
 */
void OutputHelper::printTableRow(const std::vector<std::string>& columnData) {
  std::cout << std::setfill(' ');
  
  // Print first columnCount - 1 columns.
  for (int i = 0; i < columnCount - 1; ++i) {
    std::cout << "|"
              << std::setw(columnWidth[i] - 1)
              << columnData[i]
              << " ";
  }

  // Print last column.
  std::cout << "|"
            << std::setw(columnWidth[columnCount - 1] - 1)
            << columnData[columnCount - 1]
            << " |\n";
}

/**
 * This function print a row with a subject as data.
 *
 * @param  Subject
 */
void OutputHelper::printTableRow(Subject subject) {
  std::vector<std::string>subjectStringVector = subject.toStringVector();

  OutputHelper::printTableRow(subjectStringVector);
}

/**
 * This function print the personal result as a table row.
 *
 * @param  Personal*
 */
void OutputHelper::printTableRow(Personal* personal) {
  std::vector<std::string>personalResultStringVector = personal->toStringVector();

  OutputHelper::printTableRow(personalResultStringVector);
}

/**
 * This function print the full GPA Table.
 *
 * @param  Personal*
 */
void OutputHelper::printGPATable(Personal* personal) {
  std::cout << "Total classes passed: " << personal->getTotalClassesPassed() 
            << " ("<< Utility::percent(personal->getTotalClassesPassed(), personal->getTotalClasses())
            << " %)" << '\n';
  
  OutputHelper::printTableLine();

  OutputHelper::printTableRow();
  
  OutputHelper::printTableLine();

  for (auto subject : personal->classesPassed())
    OutputHelper::printTableRow(subject);

  OutputHelper::printTableLine();

  OutputHelper::printTableRow(personal);

  OutputHelper::printTableLine();

  std::cout << '\n';
}

/**
 * This function print the failed table.
 *
 * @param  Personal*
 */
void OutputHelper::printFailedTable(Personal* personal) {
  std::cout << "Total classes failed: " << personal->getTotalClassesFailed() 
            << " ("<< Utility::percent(personal->getTotalClassesFailed(), personal->getTotalClasses())
            << " %)" << '\n';

  OutputHelper::printTableLine();

  OutputHelper::printTableRow();

  OutputHelper::printTableLine();

  for (auto subject : personal->classesFailed())
    OutputHelper::printTableRow(subject);

  OutputHelper::printTableLine();

  std::cout << '\n';
}
