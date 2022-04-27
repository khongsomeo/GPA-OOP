/**
 * Course.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "Course.h"

/**
 * Course destructor
 *
 * @return void
 */
Course::~Course() {
  // Do nothing
}

/**
 * Parameterised constructor
 *
 * @param  const std::string&
 * @param  int
 * @param  double
 * @param  const std::string&
 */
Course::Course(const std::string &name, int credit, double grade,
               const std::string &type) {
  _name = name;
  _credit = credit;
  _grade = grade;
  _type = type;
}

/**
 * Course name
 *
 * @return std::string
 */
std::string Course::name() const { return _name; }

/**
 * Course credit
 *
 * @return int
 */
int Course::credit() const { return _credit; }

/**
 * Course grade
 *
 * @return Grade
 */
Grade Course::grade() const { return _grade; }

/**
 * Course type
 *
 * @return std::string
 */
std::string Course::type() const { return _type; }

/**
 * Operator overloading for std::multiset sorting.
 *
 * @param  const Course&
 *
 * @return bool
 */
bool Course::operator<(const Course &course) const {
  return (_grade > course._grade) ||
         (_grade == course._grade && _credit > course._credit);
}

/**
 * Operator overloading for std::multiset searching.
 *
 * @param const Course&
 *
 * @return bool
 */
bool Course::operator==(const Course &course) const {
  return (_name == course._name) && (_credit == course._credit) && (_type == course._type);
}

/**
 * Convert Course to a string vector.
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> Course::toStringVector() const {
  std::vector<std::string> courseStringVector;

  courseStringVector.push_back(_name);
  courseStringVector.push_back(std::to_string(_credit));
  courseStringVector.push_back(_grade.toString());
  courseStringVector.push_back(_grade.to4Scale().toString());
  courseStringVector.push_back(_grade.toAScale());
  courseStringVector.push_back(_type);

  return courseStringVector;
}

/**
 * Check if a course is passed.
 *
 * @return bool
 */
bool Course::passed() const { return _grade >= 5.0; }

/**
 * This method parse a course from a CSV line.
 *
 * @param  const std::string&
 *
 * @return Course
 */
Course Course::parse(const std::string &buffer) {
  std::vector<std::string> tokens =
      InputHelper::instance()->splitTokens(buffer, ",");

  return Course(tokens.at(0), stoi(tokens.at(1)), stod(tokens.at(2)),
                tokens.at(3));
}

/**
 * This method parse a vector of Courses from a CSV file.
 *
 * @param  const std::string&
 *
 * @return std::vector<Course>
 */
std::vector<Course> Course::parseCourseVector(const std::string &fileName) {
  std::vector<Course> courses;

  std::vector<std::string> lineStrings =
      InputHelper::instance()->readFileLines(fileName);

  // Read csv file by line.
  for (int i = 0; i < (int)lineStrings.size(); ++i) {
    try {
      courses.push_back(parse(lineStrings[i]));
    }

    catch (const std::exception &e) {
      if (InputHelper::instance()->isLoggingParsingErrors()) {
        std::cout << "Error happened while reading file " << fileName
                  << ", on line " << i + 1 << " (" << e.what() << ")" << '\n';
      }
    }
  }

  return courses;
}
