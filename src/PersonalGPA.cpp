/**
 * PersonalGPA.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "PersonalGPA.h"

/**
 * PersonalGPA default constructor
 *
 * @return void
 */
PersonalGPA::PersonalGPA() {
  // Do nothing;
}

/**
 * PersonalGPA destructor
 *
 * @return void
 */
PersonalGPA::~PersonalGPA() {
  // Do nothing;
}

/**
 * Parameterised constructor
 *
 * @param  const std::vector<Course>&
 *
 * @throw  std::runtime_error
 */
PersonalGPA::PersonalGPA(const std::vector<Course> &courses) {
  for (const Course &course : courses) {
    addCourse(course);
  }

  // Calculate GPA if nothing went wrong.
  calculateGPA();
}

/**
 * Return total passed credits
 *
 * @return int
 */
int PersonalGPA::passedCredits() { return _passedCredits; }

/**
 * Return total failed credits
 *
 * @return int
 */
int PersonalGPA::failedCredits() { return _failedCredits; }

/**
 * Return GPA in scale 10.
 *
 * @return Grade
 */
Grade PersonalGPA::resultGPAScale10() { return _resultGPAScale10; }

/**
 * Return GPA in scale 4.
 *
 * @return Grade
 */
Grade PersonalGPA::resultGPAScale4() { return _resultGPAScale4; }

/**
 * Convert passed list to string vector.
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> PersonalGPA::passedListToStringVector() {
  std::vector<std::string> stringVector;

  stringVector.push_back("Overall");
  stringVector.push_back(std::to_string(passedCredits()));
  stringVector.push_back(resultGPAScale10().toString());
  stringVector.push_back(resultGPAScale4().toString());
  stringVector.push_back(resultGPAScale10().toAScale());
  stringVector.push_back("N/A");

  return stringVector;
}

/**
 * Convert failed list to string vector
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> PersonalGPA::failedListToStringVector() {
  std::vector<std::string> stringVector;

  stringVector.push_back("Overall");
  stringVector.push_back(std::to_string(failedCredits()));
  stringVector.push_back("None");
  stringVector.push_back("None");
  stringVector.push_back("None");
  stringVector.push_back("N/A");

  return stringVector;
}

/**
 * Convert to vector of string vectors.
 *
 * @return std::vector<std::vector<std::string>>
 */
std::vector<std::vector<std::string>> PersonalGPA::toPassedVector() {
  std::vector<std::vector<std::string>> resultVector;

  for (const Course &course : _coursesPassed) {
    resultVector.push_back(course.toStringVector());
  }

  // Push overall.
  resultVector.push_back(passedListToStringVector());

  return resultVector;
}

/**
 * Just like above, but for failed.
 *
 * @return std::vector<std::vector<std::string>>
 */
std::vector<std::vector<std::string>> PersonalGPA::toFailedVector() {
  std::vector<std::vector<std::string>> resultVector;

  for (const Course &course : _coursesFailed) {
    resultVector.push_back(course.toStringVector());
  }

  resultVector.push_back(failedListToStringVector());

  return resultVector;
}

/**
 * Return total courses.
 *
 * @return int
 */
int PersonalGPA::getTotalCourses() {
  int totalCourses = _coursesPassed.size() + _coursesFailed.size();

  return totalCourses;
}

/**
 * Return total passed courses.
 *
 * @return int
 */
int PersonalGPA::getTotalCoursesPassed() { return _coursesPassed.size(); }

/**
 * Return total failed courses.
 *
 * @return int
 */
int PersonalGPA::getTotalCoursesFailed() { return _coursesFailed.size(); }

/**
 * Get credit detail
 *
 * @return std::map<std::string, int>
 */
std::map<std::string, int> PersonalGPA::getCreditDetail() {
  return _creditDetail;
}

/**
 * Parse data into Personal
 *
 * @param  const std::vector<std::string>&
 *
 * @return std::shared_ptr<PersonalGPA>
 */
std::shared_ptr<PersonalGPA> PersonalGPA::parse(
    const std::vector<std::string> &input) {
  std::vector<Course> courses = Course::parseCourseVector(input.at(0));

  return std::make_shared<PersonalGPA>(courses);
}

/**
 * Calculate total GPA.
 *
 * @return void
 *
 * @throw  std::runtime_error
 */
void PersonalGPA::calculateGPA() {
  // Throw std::runtime_error if no course was added.
  if (0 == getTotalCourses()) {
    throw std::runtime_error("No course was added.");
  }

  for (const Course &course : _coursesPassed) {
    // Calculate new GPA.
    _sumGradeScale10 += course.grade() * course.credit();
    _sumGradeScale4 += course.grade().to4Scale() * course.credit();

    _resultGPAScale10 = _sumGradeScale10 / (1.0 * _passedCredits);
    _resultGPAScale4 = _sumGradeScale4 / (1.0 * _passedCredits);
  }
}

/**
 * Add a failed course to failed course list.
 *
 * @param  const Course&
 *
 * @return void
 */
void PersonalGPA::addFailedCourse(const Course &course) {
  // Remove course, if passed.
  // This happened when the student re-take a low-grade course, and failed.
  std::multiset<Course>::iterator it =
      std::find(_coursesPassed.begin(), _coursesPassed.end(), course);

  if (it != _coursesPassed.end()) {
    _coursesPassed.erase(it);
    _passedCredits -= course.credit();
    _creditDetail[course.type()] -= course.credit();
  }

  // If course already exist in failed list, update it.
  it = std::find(_coursesFailed.begin(), _coursesFailed.end(), course);

  if (it != _coursesFailed.end()) {
    _coursesFailed.erase(it);
    _coursesFailed.insert(course);
  }

  // Insert new failed class to list.
  else {
    _coursesFailed.insert(course);
    _failedCredits += course.credit();
  }
}

/**
 * Add a passed course to passed course list.
 *
 * @param  const Course&
 *
 * @return void
 */
void PersonalGPA::addPassedCourse(const Course &course) {
  // Remove failed attempts, if passed.
  std::multiset<Course>::iterator it =
      std::find(_coursesFailed.begin(), _coursesFailed.end(), course);

  if (it != _coursesFailed.end()) {
    _coursesFailed.erase(it);
    _failedCredits -= course.credit();
  }

  // If course already exist in passed list, update it.
  it = std::find(_coursesPassed.begin(), _coursesPassed.end(), course);

  if (it != _coursesPassed.end()) {
    _coursesPassed.erase(it);
    _coursesPassed.insert(course);
  }

  // Insert new passed class to list.
  else {
    _coursesPassed.insert(course);
    _passedCredits += course.credit();
    _creditDetail[course.type()] += course.credit();
  }
}

/**
 * Add a new course.
 *
 * @param  const Course&
 *
 * @return void
 */
void PersonalGPA::addCourse(const Course &course) {
  // If not passed, then insert into failed list.
  if (!course.passed()) {
    addFailedCourse(course);
  }

  else {
    addPassedCourse(course);
  }
}
