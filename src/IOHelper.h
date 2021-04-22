/**
 * IOHelper.h.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef IO_HELPER_H
#define IO_HELPER_H

#define TEXTART_FILE "data/textart.txt"

class IOHelper {
public:
  struct Input {
    static std::vector<std::string> splitTokens(std::string, const std::string&);
    static Subject parseSubject(const std::string&);
    static std::vector<Subject> parseSubjectVector(const std::string&);
  };

  struct Output {
    static int                      columnCount;
    static std::vector<std::string> columnTitle;
    static std::vector<int>         columnWidth;

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
};

#endif
