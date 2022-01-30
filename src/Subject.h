/**
 * This file defines the structure of a subject.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "Grade.h"
#include "InputHelper.h"

class Subject {
 private:
  std::string _name;
  int _credit;
  Grade _grade;

 public:
  /**
   * Parameterised constructor
   *
   * @param  const std::string&
   * @param  int
   * @param  double
   */
  Subject(const std::string &, int, double);

  /**
   * Parameterised constructor overload.
   *
   * @param  const std::string&
   * @param  int
   * @param  const Grade&
   */
  Subject(const std::string &, int, const Grade &);

  /**
   * Destructor
   *
   */
  ~Subject();

 public:
  /**
   * Subject name
   *
   * @return std::string
   */
  std::string name() const;

  /**
   * Subject credit
   *
   * @return int
   */
  int credit() const;

  /**
   * Subject grade
   *
   * @return Grade
   */
  Grade grade() const;

  /**
   * Operator overloading for std::multiset sorting.
   *
   * @param  const Subject&
   *
   * @return bool
   */
  bool operator<(const Subject &) const;

  /**
   * Convert Subject to a string vector.
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> toStringVector() const;

  /**
   * Check if subject passed.
   *
   * @return bool
   */
  bool passed() const;

  /**
   * This method parse a subject from a CSV line.
   *
   * @param  const std::string&
   *
   * @return Subject
   */
  static Subject parse(const std::string &);

  /**
   * This method parse a vector of Subjects from a CSV file.
   *
   * @param  const std::string&
   *
   * @return std::vector<Subject>
   */
  static std::vector<Subject> parseSubjectVector(const std::string &fileName);
};
#endif  // SUBJECT_H
