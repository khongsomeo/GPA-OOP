/**
 * Implementation of functions defined inside "IOHelper.h"
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"IOHelper.h"

// Total columns
int IOHelper::Output::columnCount = 5;

// Column size
std::vector<int> IOHelper::Output::columnWidth = {12, 9, 20, 19, 19};

// Column title
std::vector<std::string> IOHelper::Output::columnTitle = {"class name", "credits", "grade (10 - scale)", "grade (4 - scale)", "grade (A - scale)"};

/**
 * This function print the textart.
 * (a cooler but not suitable move). 
 */
void IOHelper::Output::printTextart() {
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
void IOHelper::Output::printTableLine() {
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
void IOHelper::Output::printTableRow() {
  IOHelper::Output::printTableRow(columnTitle);
}

/**
 * This function print the table.
 *
 * @param  const std::vector<std::string>&
 */
void IOHelper::Output::printTableRow(const std::vector<std::string>& columnData) {
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
void IOHelper::Output::printTableRow(Subject subject) {
  std::vector<std::string>subjectStringVector = subject.toStringVector();

  IOHelper::Output::printTableRow(subjectStringVector);
}

/**
 * This function print the personal result as a table row.
 *
 * @param  Personal*
 */
void IOHelper::Output::printTableRow(Personal* personal) {
  std::vector<std::string>personalResultStringVector = personal->toStringVector();

  IOHelper::Output::printTableRow(personalResultStringVector);
}

/**
 * This function print the full GPA Table.
 *
 * @param  Personal*
 */
void IOHelper::Output::printGPATable(Personal* personal) {
  std::cout << "Total classes passed: " << personal->getTotalClassesPassed() 
            << " ("<< Utility::percent(personal->getTotalClassesPassed(), personal->getTotalClasses())
            << " %)" << '\n';
  
  IOHelper::Output::printTableLine();

  IOHelper::Output::printTableRow();
  
  IOHelper::Output::printTableLine();

  for (auto subject : personal->classesPassed())
    IOHelper::Output::printTableRow(subject);

  IOHelper::Output::printTableLine();

  IOHelper::Output::printTableRow(personal);

  IOHelper::Output::printTableLine();

  std::cout << '\n';
}

/**
 * This function print the failed table.
 *
 * @param  Personal*
 */
void IOHelper::Output::printFailedTable(Personal* personal) {
  std::cout << "Total classes failed: " << personal->getTotalClassesFailed() 
            << " ("<< Utility::percent(personal->getTotalClassesFailed(), personal->getTotalClasses())
            << " %)" << '\n';

  IOHelper::Output::printTableLine();

  IOHelper::Output::printTableRow();

  IOHelper::Output::printTableLine();

  for (auto subject : personal->classesFailed())
    IOHelper::Output::printTableRow(subject);

  IOHelper::Output::printTableLine();

  std::cout << '\n';
}

/**
 * This function split a string to tokens.
 *
 * @param  std::string
 * @param  const std::string&
 * @return std::vector<std::string>
 */
std::vector<std::string> IOHelper::Input::splitTokens(std::string haystack, const std::string& needle) {
  std::vector<std::string>tokens;
  std::string token;

  size_t index = 0;

  while ((index = haystack.find(needle)) != std::string::npos) {
    tokens.push_back(haystack.substr(0, index));

    haystack.erase(0, index + needle.length());
  }

  tokens.push_back(haystack);

  return tokens;
}

/**
 * This function parse a string to Subject object.
 *
 * @param  const std::string&
 * @return Subject
 */
Subject IOHelper::Input::parseSubject(const std::string& buffer) {
  std::vector<std::string> tokens = IOHelper::Input::splitTokens(buffer, ",");

  return Subject(tokens[0], stoi(tokens[1]), stod(tokens[2]));
}

/**
 * This function parse Subjects from a CSV file.
 *
 * @param  const std::string&
 * @return std::vector<Subject>
 */
std::vector<Subject> IOHelper::Input::parseSubjectVector(const std::string& fileName) {
  std::vector<Subject> subjectsVector;
  std::string buffer;
  
  std::ifstream reader(fileName);
  int currentLine = 0;

  while (std::getline(reader, buffer)) {
    ++currentLine;
    try {
      subjectsVector.push_back(IOHelper::Input::parseSubject(buffer));
    } catch (const std::exception& e) {
      std::cout << "Error occured in line " << currentLine
                << ", code: " << e.what() << '\n';
    }
  }

  reader.close();

  return subjectsVector;
}
