/**
 * This file defines Personal class.
 *
 * Code by @trhgquan - https://github.com/trhgquan.
 */

#ifndef PERSONAL_H
#define PERSONAL_H

#include<string>
#include<vector>
#include<memory>
#include<set>
#include<stdexcept>

#include"Subject.h"
#include"Grade.h"

/**
 * Personal GPA abstract class.
 *
 * Using this class when we need to calculate overall GPA.
 */
class PersonalGPA {
protected:
  // Stores personal grades & credits.
  int   _sumCredits = 0;
  Grade _sumGrades  = 0.0;
  Grade _resultGPA  = 0.0;

  // Stores classes passed / failed.
  std::multiset<Subject> _classesPassed;
  std::multiset<Subject> _classesFailed;

public:
  PersonalGPA();

  ~PersonalGPA();

  /**
   * Parameterised constructor
   *
   * @param  const std::vector<Subject>&
   */
  PersonalGPA(const std::vector<Subject>&);

  /**
   * Return total credits
   *
   * @return int
   */
  int sumCredits();

  /**
   * Return sum grades.
   *
   * @return Grade
   */
  Grade sumGrades();

  /**
   * Return GPA
   *
   * @return Grade
   */
  Grade resultGPA();

  /**
   * Convert class to string vector.
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> toStringVector();

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
   * Return total classes.
   *
   * @return int
   *
   * @throw  std::runtime_error
   */
  int getTotalClasses();

  /**
   * Return total passed classes.
   *
   * @return int
   */
  int getTotalClassesPassed();

  /**
   * Return total failed classes.
   *
   * @return int
   */
  int getTotalClassesFailed();

  /**
   * Parse data into Personal
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<IPersonal>
   */
  virtual std::shared_ptr<PersonalGPA> parse(
    const std::vector<std::string>& input);

  /**
   * Add a new subject.
   *
   * @param  const Subject&
   */
  void addSubject(const Subject& subject);
};
#endif
