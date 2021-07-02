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
    std::shared_ptr<IPersonal> chumeochuixoong = PersonalFactory::getInstance()
                                                                  ->create(argc, argv);

    // Print the textart.
    OutputHelper::printTextart();

    // Print the stats.
    std::cout << "Total passed classes: " << chumeochuixoong->getTotalClassesPassed() 
              << " (" << Utility::percent(chumeochuixoong->getTotalClassesPassed(),
                                          chumeochuixoong->getTotalClasses()) 
              <<  "%)" << '\n';

    // Print passed table
    OutputHelper::printTable(chumeochuixoong->toPassedVector());

    std::cout << '\n';

    // Print failed stats.
    std::cout << "Total failed classes: " << chumeochuixoong->getTotalClassesFailed() 
              << " (" << Utility::percent(chumeochuixoong->getTotalClassesFailed(),
                                          chumeochuixoong->getTotalClasses()) 
              <<  "%)" << '\n';

    // Print failed table.
    OutputHelper::printTable(chumeochuixoong->toFailedVector(), false);
  }

  // And catch exceptions 
  catch (const std::exception& e) {
    std::cout << "Error happened (" 
              << e.what() << ")" 
              << '\n';
  }

  return 0;
}
