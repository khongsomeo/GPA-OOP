/**
 * Calculate GPA - OOP version.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"include.h"

int main(int argc, char* argv[]) {
  // 2 digits after the floating point.
  std::cout << std::fixed << std::setprecision(2);

  // Input must have the '*.csv' file.
  if (argc - 1 != 1) {
    std::cout << "Error: Input file not specified." << '\n';
    return 0;
  }

  // Cast filename from argument to std::string.
  std::string fileName(argv[1]);

  // Check if the input file exist or not.
  if (!isFileExist(fileName)) {
    std::cout << "Error: Cannot open " << fileName << " due to some teachnical reasons." << '\n';
    return 0;
  }

  // Read subjects into vector.
  std::vector<Subject> subjects = readSubjectsFromCSVFile(fileName);

  // Create a new Personal object.
  Personal* chumeochuixoong = new Personal(subjects);

  // Print list of classes passed.
  std::cout << "Total classes passed: " << chumeochuixoong->getTotalClassesPassed() << '\n';
  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';
  std::cout << "| class name | credits | grade (10 - scale) | grade (4 - scale) | grade (A - scale) |" << '\n';
  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';
  for (auto subject : chumeochuixoong->getClassesPassed())
    std::cout << "|" << std::setw(12)
              << subject.name
              << "|" << std::setw(9)
              << subject.credit
              << "|" << std::setw(20)
              << subject.grade
              << "|" << std::setw(19)
              << subject.scale4Grade
              << "|" << std::setw(19)
              << subject.textGrade
              << "|\n";

  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';
  std::cout << "|" << std::setw(12) << "***"
            << "|" << std::setw(9)
            << chumeochuixoong->getResultCredits()
            << "|" << std::setw(20)
            << chumeochuixoong->getGPAIn10Scale()
            << "|" << std::setw(19)
            << chumeochuixoong->getGPAIn4Scale()
            << "|" << std::setw(19)
            << chumeochuixoong->getGPAInAScale()
            << "|\n";
  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';

  // Print list of failed classes.
  std::cout << "Total classes failed: " << chumeochuixoong->getTotalClassesFailed() << '\n';
  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';
  std::cout << "| class name | credits | grade (10 - scale) | grade (4 - scale) | grade (A - scale) |" << '\n';
  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';
  for (auto subject : chumeochuixoong->getClassesFailed())
    std::cout << "|" << std::setw(12)
              << subject.name
              << "|" << std::setw(9)
              << subject.credit
              << "|" << std::setw(20)
              << subject.grade
              << "|" << std::setw(19)
              << subject.scale4Grade
              << "|" << std::setw(19)
              << subject.textGrade
              << "|\n";

  std::cout << "+------------+---------+--------------------+-------------------+-------------------+" << '\n';

  delete chumeochuixoong;

  return 0;
}
