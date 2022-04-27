/**
 * This file defines the structure of a subject.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

#include "Grade.h"
#include "InputHelper.h"

class Course {
 private:
  std::string _name;
  int _credit;
  Grade _grade;
  std::string _type;

 public:
  /**
   * Parameterised constructor
   *
   * @param  const std::string&
   * @param  int
   * @param  double
   * @param  const std::string&
   */
  Course(const std::string &, int, double, const std::string &);

  /**
   * Course destructor
   *
   * @return void
   */
  ~Course();

 public:
  /**
   * Course name
   *
   * @return std::string
   */
  std::string name() const;

  /**
   * Course credit
   *
   * @return int
   */
  int credit() const;

  /**
   * Course grade
   *
   * @return Grade
   */
  Grade grade() const;

  /**
   * Course type
   *
   * @return std::string
   */
  std::string type() const;

  /**
   * Operator overloading for std::multiset sorting.
   *
   * @param  const Course&
   *
   * @return bool
   */
  bool operator<(const Course &) const;

  /**
   * Operator overloading for std::multiset searching.
   *
   * @param  const Course&
   *
   * @return bool
   */
  bool operator==(const Course &) const;

  /**
   * Convert Course to a string vector.
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> toStringVector() const;

  /**
   * Check if a course passed.
   *
   * @return bool
   */
  bool passed() const;

  /**
   * This method parse a subject from a CSV line.
   *
   * @param  const std::string&
   *
   * @return Course
   */
  static Course parse(const std::string &);

  /**
   * This method parse a vector of Courses from a CSV file.
   *
   * @param  const std::string&
   *
   * @return std::vector<Course>
   */
  static std::vector<Course> parseCourseVector(const std::string &fileName);
};
#endif  // COURSE_H
