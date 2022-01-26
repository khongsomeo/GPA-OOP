/**
 * Subject.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"Subject.h"

/**
 * Parameterised constructor
 *
 * @param  const std::string&
 * @param  int
 * @param  double
 */
Subject::Subject(
    const std::string& name, int credit, double grade) {
  _name   = name;
  _credit = credit;
  _grade  = grade;
}

/**
 * Parameterised constructor overload.
 *
 * @param  const std::string&
 * @param  int
 * @param  const Grade&
 */
Subject::Subject(
    const std::string& name, int credit, const Grade& grade) {
  _name   = name;
  _credit = credit;
  _grade  = grade;
}

/**
 * Destructor
 *
 */
Subject::~Subject() {
  // Do nothing
}

/**
 * Subject name
 *
 * @return std::string
 */
std::string Subject::name() const {
  return _name;
}

/**
 * Subject credit
 *
 * @return int
 */
int Subject::credit() const {
  return _credit;
}

/**
 * Subject grade
 *
 * @return Grade
 */
Grade Subject::grade() const {
  return _grade;
}

/**
 * Operator overloading for std::multiset sorting.
 *
 * @param  const Subject&
 *
 * @return bool
 */
bool Subject::operator< (const Subject& subject) const {
  return (_grade > subject._grade) ||
    (_grade == subject._grade && _credit > subject._credit);
}

/**
 * Convert Subject to a string vector.
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> Subject::toStringVector() const {
  std::vector<std::string> subjectStringVector;

  subjectStringVector.push_back(_name);
  subjectStringVector.push_back(std::to_string(_credit));
  subjectStringVector.push_back(_grade.toString());
  subjectStringVector.push_back(_grade.to4Scale().toString());
  subjectStringVector.push_back(_grade.toAScale());

  return subjectStringVector;
}

/**
 * Check if subject passed.
 *
 * @return bool
 */
bool Subject::passed() const {
  return _grade >= 5.0;
}

/**
 * This method parse a subject from a CSV line.
 *
 * @param  const std::string&
 *
 * @return Subject
 */
Subject Subject::parse(const std::string& buffer) {
  std::vector<std::string> tokens = InputHelper::instance()
    ->splitTokens(buffer, ",");

  return Subject(
      tokens.at(0),
      stoi(tokens.at(1)),
      stod(tokens.at(2))
  );
}

/**
 * This method parse a vector of Subjects from a CSV file.
 *
 * @param  const std::string&
 *
 * @return std::vector<Subject>
 */
std::vector<Subject> Subject::parseSubjectVector(
    const std::string& fileName) {
  std::vector<Subject> subjects;

  std::vector<std::string> lineStrings = InputHelper::instance()
    ->readFileLines(fileName);

  // Read csv file by line.
  for (int i = 0; i < (int)lineStrings.size(); ++i) {
    try {
      subjects.push_back(parse(lineStrings[i]));
    }

    catch (const std::exception& e) {
      if (InputHelper::instance()->isLoggingParsingErrors()) {
        std::cout << "Error happened while reading file "
          << fileName
          << ", on line " << i + 1
          << " (" << e.what() << ")"
          << '\n';
      }
    }
  }

  return subjects;
}
