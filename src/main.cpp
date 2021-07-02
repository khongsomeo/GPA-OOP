/**
 * Calculate GPA - OOP version.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"include.h"

int main(int argc, char* argv[]) {
  // 2 digits after the floating point.
  std::cout << std::fixed << std::setprecision(2);
  
  // Create a new IPersonal instance.
  try {
    std::shared_ptr<IPersonal> chumeochuixoong = PersonalFactory
      ::getInstance()
      ->create(argc, argv);

    /**
     * These lines check if user needs to output to .csv file.
     *
     */

    bool isOutputCSV = 0;

    for (int i = 0; i < argc; ++i) {
      if (std::string(argv[i]) == "--csv") {
        isOutputCSV = 1;
        break;
      }
    }

    /**
     * Outputing
     *
     */

    if (!isOutputCSV) {
      // Print the textart.
      OutputHelper::printTextart();
    }

    // Print the stats.
    std::cout << "Total passed classes: " 
              << chumeochuixoong->getTotalClassesPassed() 
              << " (" 
              << Utility::percent(
                  chumeochuixoong->getTotalClassesPassed(),
                  chumeochuixoong->getTotalClasses()) 
              << "%)"
              << '\n';

    if (!isOutputCSV) {
      // Print passed table
      OutputHelper::printTable(chumeochuixoong->toPassedVector());
    }

    else {
      OutputHelper::printCSVTable(chumeochuixoong->toPassedVector());
    }

    std::cout << '\n';

    // Print failed stats.
    std::cout << "Total failed classes: " 
              << chumeochuixoong->getTotalClassesFailed() 
              << " (" 
              << Utility::percent(
                  chumeochuixoong->getTotalClassesFailed(),
                  chumeochuixoong->getTotalClasses()) 
              << "%)" 
              << '\n';

    if (!isOutputCSV) {
      // Print failed table.
      OutputHelper::printTable(
        chumeochuixoong->toFailedVector(), 
        false
      );
    }

    else {
      OutputHelper::printCSVTable(
        chumeochuixoong->toFailedVector()
      );
    }
  }

  // And catch exceptions 
  catch (const std::exception& e) {
    std::cout << "Error happened (" 
              << e.what() << ")" 
              << '\n';
  }

  return 0;
}
