/**
 * PersonalSpecific.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"PersonalSpecific.h"

PersonalSpecific::PersonalSpecific() {
  // Do nothing
}

PersonalSpecific::~PersonalSpecific() {
  // Do nothing
}

/**
 * Parameterised constructor.
 *
 * @param  std::vector<Subject>&
 * @param  const std::vector<string>&
 */
PersonalSpecific::PersonalSpecific(
    std::vector<Subject>& subjects,
    const std::vector<std::string>& coursePrefixes) {
  for (const std::string& prefix : coursePrefixes) {
    addSpecific(subjects, prefix);
  }
}

/**
 * Add a specific course starting with "prefix".
 *
 * @param  std::vector<Subject>&
 * @param  const std::string&
 */
void PersonalSpecific::addSpecific(
    std::vector<Subject>& subjects,
    const std::string& prefix) {

  std::vector<int> positions;

  for (int i = 0; i < (int)subjects.size(); ++i) {
    if (Utility::isPrefix(subjects.at(i).name(), prefix)) {
      // Add subject.
      addSubject(subjects.at(i));

      // Add to remove list.
      positions.push_back(i);
    }
  }

  // Remove subjects to prevent re-adding them.
  for (const int& i : positions) {
    subjects.erase(subjects.begin() + i);
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
    const std::vector<std::string>& input) {
  std::vector<Subject> subjects = Subject::parseSubjectVector(
      input.at(0)
      );

  std::vector<std::string> prefixes = InputHelper::readFileLines(
      input.at(1)
      );

  return std::make_shared<PersonalSpecific>(
      subjects, prefixes
  );
}
