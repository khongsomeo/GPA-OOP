/**
 * Calculate GPA - OOP version.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "CommandLineParser.h"
#include "InputHelper.h"
#include "OutputHelper.h"
#include "PersonalFactory.h"

int main(int argc, char *argv[]) {
  // Create a Command Line Parser with giving argc and argv
  CommandLineParser CLP(argc, argv);

  // These lines check if user needs to ignore parsing errors
  InputHelper::instance()->setInputFlag(
      CLP.cmdOptionExists("--ignore-parsing-error")
          ? InputConstants::IGNORE_PARSING_ERROR
          : InputConstants::ALLOW_PARSING_ERROR);

  // These lines check if user don't want to output textart.
  OutputHelper::instance()->setOutputFlag(CLP.cmdOptionExists("--no-textart")
                                              ? OutputConstants::NO_TEXTART
                                              : OutputConstants::ALLOW_TEXTART);

  // These lines check if user needs to output to .csv file.
  OutputHelper::instance()->setOutputFlag(CLP.cmdOptionExists("--csv")
                                              ? OutputConstants::FORMAT_CSV
                                              : OutputConstants::FORMAT_TABLE);

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
    std::shared_ptr<PersonalGPA> personalGPAObj =
        PersonalFactory ::instance()->create(mode, input);

    /**
     * Outputing
     *
     */
    if (!OutputHelper::instance()->isCSVOutput() &&
        OutputHelper::instance()->isAllowTextart()) {
      // Print the textart.
      OutputHelper::instance()->printTextart();
    }

    // Print the stats.
    std::cout << "Total passed courses: "
              << personalGPAObj->getTotalCoursesPassed() << " ("
              << Utility::percent(personalGPAObj->getTotalCoursesPassed(),
                                  personalGPAObj->getTotalCourses())
              << "%)" << '\n';

    // Print passed table
    OutputHelper::instance()->printTable(personalGPAObj->toPassedVector());

    // Print credit stats
    if (personalGPAObj->getTotalCoursesPassed() > 0) {
      std::cout << "Passed credit details: " << '\n';
      for (const auto &credit : personalGPAObj->getCreditDetail()) {
        std::cout << "Courses type " << credit.first << ": " << credit.second
                  << " ("
                  << Utility::percent(credit.second,
                                      personalGPAObj->passedCredits())
                  << "%)" << '\n';
      }
    }

    std::cout << '\n';

    // Print failed stats.
    std::cout << "Total failed courses: "
              << personalGPAObj->getTotalCoursesFailed() << " ("
              << Utility::percent(personalGPAObj->getTotalCoursesFailed(),
                                  personalGPAObj->getTotalCourses())
              << "%)" << '\n';

    // Print failed table.
    OutputHelper::instance()->printTable(personalGPAObj->toFailedVector());
  }

  // And catch exceptions
  catch (const std::exception &e) {
    std::cout << "Error happened (" << e.what() << ")" << '\n';
  }

  return 0;
}
