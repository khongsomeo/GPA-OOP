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
  if (argc - 1 == 0) {
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

  // Create a new IPersonal instance.
  try {
    std::shared_ptr<IPersonal> chumeochuixoong = PersonalFactory::instance()->create(argc, argv);

    // Print the textart.
    OutputHelper::printTextart();

    std::cout << "Total passed classes: " << chumeochuixoong->getTotalClassesPassed() << " (" << Utility::percent(chumeochuixoong->getTotalClassesPassed(), chumeochuixoong->getTotalClasses()) <<  "%)" << '\n';
    OutputHelper::printTable(chumeochuixoong->toPassedVector());

    std::cout << '\n';
  
    std::cout << "Total failed classes: " << chumeochuixoong->getTotalClassesFailed() << " (" << Utility::percent(chumeochuixoong->getTotalClassesFailed(), chumeochuixoong->getTotalClasses()) <<  "%)" << '\n';

    OutputHelper::printTable(chumeochuixoong->toFailedVector(), false);
  } catch (const std::exception& e) {
    std::cout << "Error happened, code: " << e.what() << '\n';
  }

  return 0;
}
