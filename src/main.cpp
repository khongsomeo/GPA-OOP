/**
 * Calculate GPA - OOP version.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"include.h"

int main(int argc, char* argv[]) {
  // 2 digits after the floating point.
  std::cout << std::fixed << std::setprecision(2);

  try {
    std::shared_ptr<PersonalGPA> chumeochuixoong = PersonalFactory
      ::getInstance()
      ->create(argc, argv);

    /**
     * These lines check if user needs to output to .csv file.
     *
     */
    OutputHelper::instance()->setOutputFormat(
      Utility::hasParameter(argc, argv, "--csv") ?
        OutputConstants::FORMAT_CSV :
        OutputConstants::FORMAT_TABLE
    );

    /**
     * Outputing
     *
     */
    if (!OutputHelper::instance()->isCSVOutput()) {
      // Print the textart.
      OutputHelper::instance()->printTextart();
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

    // Print passed table
    OutputHelper::instance()
      ->printTable(chumeochuixoong->toPassedVector());

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

    // Print failed table.
    OutputHelper::instance()
      ->printTable(
        chumeochuixoong->toFailedVector(),
        false
      );
  }

  // Catch exception if arguments went wrong
  catch (const std::out_of_range& oor) {
    std::cout << "Error happened (missing arguments)" << '\n';
  }

  // And catch exceptions
  catch (const std::exception& e) {
    std::cout << "Error happened ("
              << e.what() << ")"
              << '\n';
  }

  return 0;
}
