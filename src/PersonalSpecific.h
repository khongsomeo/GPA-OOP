/**
 * PersonalSpecific.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef PERSONAL_SPECIFIC_H
#define PERSONAL_SPECIFIC_H

#include "PersonalGPA.h"

/**
 * PersonalSpecific class
 *
 * This class is used when we want to calculate average
 * of some specific courses with default class code only.
 *
 * e.g: I want to calculate average of "CSCxxxxx" course.
 * So I'll use this class, with default subjectVector and classPrefix = "CSC".
 */
class PersonalSpecific : public PersonalGPA {
 public:
  /**
   * PersonalSpecific default constructor
   *
   * @return void
   */
  PersonalSpecific();

  /**
   * PersonalSpecific destructor
   *
   * @return void
   */
  ~PersonalSpecific();

  /**
   * Parameterised constructor.
   *
   * @param  std::vector<Course>&
   * @param  const std::vector<string>&
   */
  PersonalSpecific(std::vector<Course> &, const std::vector<std::string> &);

  /**
   * Add a specific course starting with "prefix".
   *
   * @param  std::vector<Course>&
   * @param  const std::string&
   */
  void addSpecific(std::vector<Course> &, const std::string &);

 public:
  /**
   * Parse a PersonalSpecific object.
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<PersonalGPA>
   */
  virtual std::shared_ptr<PersonalGPA> parse(
      const std::vector<std::string> &) override;
};
#endif  // PERSONAL_SPECIFIC_H
