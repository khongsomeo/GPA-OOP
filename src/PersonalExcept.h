/**
 * PersonalExcept.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef PERSONAL_EXCEPT_H
#define PERSONAL_EXCEPT_H

#include "PersonalGPA.h"

/**
 * PersonalExcept class
 *
 * This class is used when we need to calculate GPA except some courses.
 *
 * For example, I need to calculate my GPA except PE, English and National
 * Defense. So I'll add these courses's code to except.txt, and use this class
 * instead.
 */
class PersonalExcept : public PersonalGPA {
 private:
  std::multiset<std::string> _ignoredCourses;

 public:
  /**
   * PersonalExcept default constructor
   *
   * @return void
   */
  PersonalExcept();

  /**
   * PersonalExcept destructor
   *
   * @return void
   */
  ~PersonalExcept();

  /**
   * Parameterised constructor for PersonalExcept
   *
   * @param  const std::vector<Course>&
   * @param  const std::vector<std::string>&
   */
  PersonalExcept(const std::vector<Course> &, const std::vector<std::string> &);

 public:
  /**
   * Parse a PersonalExcept object.
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<PersonalGPA>
   */
  virtual std::shared_ptr<PersonalGPA> parse(
      const std::vector<std::string> &) override;
};
#endif  // PERSONAL_EXCEPT_H
