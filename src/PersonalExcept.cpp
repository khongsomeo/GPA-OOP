/**
 * PersonalExcept.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "PersonalExcept.h"

PersonalExcept::PersonalExcept() {
  // Do nothing.
}

PersonalExcept::~PersonalExcept() {
  // Do nothing.
}

/**
 * Parameterised constructor for PersonalExcept
 *
 * @param  const std::vector<Subject>&
 * @param  const std::vector<std::string>&
 */
PersonalExcept::PersonalExcept(const std::vector<Subject> &subjects,
                               const std::vector<std::string> &ignoredCourses) {
  // Insert ignored courses inside a multiset.
  for (const std::string &course : ignoredCourses) {
    _ignoredCourses.insert(course);
  }

  // Add Subject when it doesn't exist inside _ignoredCourses.
  for (const Subject &subject : subjects) {
    if (_ignoredCourses.find(subject.name()) == _ignoredCourses.end()) {
      addSubject(subject);
    }
  }
}

/**
 * Parse a PersonalExcept object.
 *
 * @param  const std::vector<std::string>&
 *
 * @return std::shared_ptr<PersonalGPA>
 */
std::shared_ptr<PersonalGPA>
PersonalExcept::parse(const std::vector<std::string> &input) {
  std::vector<Subject> subjectVector =
      Subject ::parseSubjectVector(input.at(0));

  std::vector<std::string> ignoredCourses =
      InputHelper::instance()->readFileLines(input.at(1));

  return std::make_shared<PersonalExcept>(subjectVector, ignoredCourses);
}
