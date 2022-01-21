/**
 * Calculate GPA - OOP version.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"CommandLineParser.h"
#include"InputHelper.h"
#include"OutputHelper.h"
#include"PersonalFactory.h"

int main(int argc, char* argv[]) {
  // Create a Command Line Parser with giving argc and argv
  CommandLineParser CLP(argc, argv);
  
  // These lines check if user needs to ignore input errors
  InputHelper::instance()->setInputFlag(
    CLP.cmdOptionExists("--ignore-input-error") ?
      InputConstants::IGNORE_INPUT_ERROR :
      InputConstants::ALLOW_INPUT_ERROR
  );

  // These lines check if user needs to output to .csv file.
  OutputHelper::instance()->setOutputFlag(
    CLP.cmdOptionExists("--csv") ?
      OutputConstants::FORMAT_CSV :
      OutputConstants::FORMAT_TABLE
  );

  // 2 digits after the floating point.
  std::cout << std::fixed << std::setprecision(2);

  // Input arguments vector.
  std::vector<std::string> input;

  // Mode (zero by default)
  int mode = 0;

  try {
    // Get input file.
    input.push_back(CLP.getCmdOption("--input"));

    // Specific mode.
    if (CLP.cmdOptionExists("--specific")) {
      input.push_back(CLP.getCmdOption("--specific"));
      mode = 1;
    }  

    // Ignore mode.
    else if (CLP.cmdOptionExists("--ignore")) {
      input.push_back(CLP.getCmdOption("--ignore"));
      mode = 2;
    }

    // Create new GPA calculator.
    std::shared_ptr<PersonalGPA> chumeochuixoong = PersonalFactory
      ::getInstance()
      ->create(mode, input);

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
      ->printTable(chumeochuixoong->toFailedVector());
  }

  // And catch exceptions
  catch (const std::exception& e) {
    std::cout << "Error happened ("
              << e.what() << ")"
              << '\n';
  }

  return 0;
}
