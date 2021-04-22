/**
 * Calculate GPA - OOP version.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"include.h"

int main(int argc, char* argv[]) {
  // 2 digits after the floating point.
  std::cout << std::fixed << std::setprecision(2);

  // Input must have the path to input file.
  if (argc - 1 != 1) {
    std::cout << "Error: Input file not specified." << '\n';
    return 0;
  }

  // Cast filename from argument to std::string.
  std::string fileName(argv[1]);

  // Check if the input file exist or not.
  if (!Utility::isFileExist(fileName)) {
    std::cout << "Error: Cannot open " << fileName << " due to some teachnical reasons." << '\n';
    return 0;
  }

  // Read subjects into vector.
  std::vector<Subject> subjects = IOHelper::Input::parseSubjectVector(fileName);

  // Create a new Personal object.
  Personal* chumeochuixoong = new Personal(subjects);

  // Print the textart.
  IOHelper::Output::printTextart();

  // Print list of classes passed.
  IOHelper::Output::printGPATable(chumeochuixoong);

  // Print list of failed classes.
  IOHelper::Output::printFailedTable(chumeochuixoong);

  delete chumeochuixoong;

  return 0;
}
