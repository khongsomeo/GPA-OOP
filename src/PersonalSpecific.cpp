/**
 * PersonalSpecific.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "PersonalSpecific.h"

/**
 * PersonalSpecific default constructor
 *
 * @return void
 */
PersonalSpecific::PersonalSpecific() {
  // Do nothing
}

/**
 * PersonalSpecific destructor
 *
 * @return void
 */
PersonalSpecific::~PersonalSpecific() {
  // Do nothing
}

/**
 * Parameterised constructor.
 *
 * @param  std::vector<Course>&
 * @param  const std::vector<string>&
 */
PersonalSpecific::PersonalSpecific(
    std::vector<Course> &courses,
    const std::vector<std::string> &coursePrefixes) {
  for (const std::string &prefix : coursePrefixes) {
    addSpecific(courses, prefix);
  }

  // Calculate GPA.
  calculateGPA();
}

/**
 * Add a specific course starting with "prefix".
 *
 * @param  std::vector<Course>&
 * @param  const std::string&
 */
void PersonalSpecific::addSpecific(std::vector<Course> &courses,
                                   const std::string &prefix) {
  std::vector<int> positions;

  for (int i = 0; i < (int)courses.size(); ++i) {
    if (Utility::isPrefix(courses.at(i).name(), prefix)) {
      // Add subject.
      addCourse(courses.at(i));

      // Add to remove list.
      positions.push_back(i);
    }
  }

  // Remove courses to prevent re-adding them.
  for (const int &i : positions) {
    courses.erase(courses.begin() + i);
  }
}

/**
 * Parse a PersonalSpecific object.
 *
 * @param  const std::vector<std::string>&
 *
 * @return std::shared_ptr<PersonalGPA>
 */
std::shared_ptr<PersonalGPA> PersonalSpecific::parse(
    const std::vector<std::string> &input) {
  std::vector<Course> courses = Course::parseCourseVector(input.at(0));

  std::vector<std::string> prefixes =
      InputHelper::instance()->readFileLines(input.at(1));

  return std::make_shared<PersonalSpecific>(courses, prefixes);
}
