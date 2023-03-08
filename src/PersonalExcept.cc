/**
 * PersonalExcept.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "PersonalExcept.h"

/**
 * PersonalExcept default constructor
 *
 * @return void
 */
PersonalExcept::PersonalExcept() {
  // Do nothing.
}

/**
 * PersonalExcept destructor
 *
 * @return void
 */
PersonalExcept::~PersonalExcept() {
  // Do nothing.
}

/**
 * Parameterised constructor for PersonalExcept
 *
 * @param  const std::vector<Course>&
 * @param  const std::vector<std::string>&
 */
PersonalExcept::PersonalExcept(const std::vector<Course> &courses,
                               const std::vector<std::string> &ignoredCourses) {
  // Insert ignored courses inside a multiset.
  for (const std::string &course : ignoredCourses) {
    _ignoredCourses.insert(course);
  }

  // Add Course when it doesn't exist inside _ignoredCourses.
  for (const Course &course : courses) {
    if (_ignoredCourses.find(course.name()) == _ignoredCourses.end()) {
      addCourse(course);
    }
  }

  // Calculate GPA based on passed course.
  calculateGPA();
}

/**
 * Parse a PersonalExcept object.
 *
 * @param  const std::vector<std::string>&
 *
 * @return std::shared_ptr<PersonalGPA>
 */
std::shared_ptr<PersonalGPA> PersonalExcept::parse(
    const std::vector<std::string> &input) {
  std::vector<Course> courseVector = Course::parseCourseVector(input.at(0));

  std::vector<std::string> ignoredCourses =
      InputHelper::instance()->readFileLines(input.at(1));

  return std::make_shared<PersonalExcept>(courseVector, ignoredCourses);
}
