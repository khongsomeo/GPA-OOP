/**
 * This file defines Personal class.
 *
 * Code by @trhgquan - https://github.com/trhgquan.
 */

#ifndef PERSONAL_GPA_H
#define PERSONAL_GPA_H

#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include "Course.h"
#include "Grade.h"

/**
 * Personal GPA abstract class.
 *
 * Using this class when we need to calculate overall GPA.
 */
class PersonalGPA {
 protected:
  // Stores personal grades & credits.
  int _passedCredits = 0;
  int _failedCredits = 0;
  Grade _sumGrades = 0.0;
  Grade _resultGPA = 0.0;

  // Stores courses passed / failed.
  std::multiset<Course> _coursesPassed;
  std::multiset<Course> _coursesFailed;

 protected:
  /**
   * Calculate total GPA.
   *
   * @return void
   *
   * @throw  std::runtime_error
   */
  void calculateGPA();

  /**
   * Add a failed course to failed course list.
   *
   * @param  const Course&
   *
   * @return void
   */
  void addFailedCourse(const Course &);

  /**
   * Add a passed course to passed course list.
   *
   * @param  const Course&
   *
   * @return void
   */
  void addPassedCourse(const Course &);

 public:
  /**
   * PersonalGPA default constructor
   *
   * @return void
   */
  PersonalGPA();

  /**
   * PersonalGPA destructor
   *
   * @return void
   */
  ~PersonalGPA();

  /**
   * Parameterised constructor
   *
   * @param  const std::vector<Course>&
   *
   * @throw  std::runtime_error
   */
  PersonalGPA(const std::vector<Course> &);

  /**
   * Return total passed credits
   *
   * @return int
   */
  int passedCredits();

  /**
   * Return total failed credits
   *
   * @return int
   */
  int failedCredits();

  /**
   * Return GPA
   *
   * @return Grade
   */
  Grade resultGPA();

  /**
   * Convert passed list to string vector.
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> passedListToStringVector();

  /**
   * Convert failed list to string vector.
   *
   * @return std::vector<std::string>>
   */
  std::vector<std::string> failedListToStringVector();

  /**
   * Convert to vector of string vectors.
   *
   * @return std::vector<std::vector<std::string>>
   */
  std::vector<std::vector<std::string>> toPassedVector();

  /**
   * Just like above, but for failed.
   *
   * @return std::vector<std::vector<std::string>>
   */
  std::vector<std::vector<std::string>> toFailedVector();

  /**
   * Return total credits
   *
   * @return int
   */
  int getTotalPassedCredits();

  /**
   * Return total courses.
   *
   * @return int
   */
  int getTotalCourses();

  /**
   * Return total passed courses.
   *
   * @return int
   */
  int getTotalCoursesPassed();

  /**
   * Return total failed courses.
   *
   * @return int
   */
  int getTotalCoursesFailed();

  /**
   * Parse data into Personal
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<PersonalGPA>
   */
  virtual std::shared_ptr<PersonalGPA> parse(const std::vector<std::string> &);

  /**
   * Add a new course.
   *
   * @param  const Course&
   *
   * @return void
   */
  void addCourse(const Course &);
};
#endif  // PERSONAL_GPA_H
