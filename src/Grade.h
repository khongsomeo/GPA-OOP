/**
 * Grade implementation.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef GRADE_H
#define GRADE_H

#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>

/**
 * Grade class.
 *
 * I can implement the grades by a double, yet the conversions needs
 * to be done in many functions.
 *
 * Hence, creating a new class is the most suitable option.
 */
class Grade {
private:
  double _grade;

public:
  /**
   * Default constructor
   *
   */
  Grade();

  /**
   * Parameterised constructor
   *
   * @param  double
   */
  Grade(double);

  /**
   * Parameterised constructor
   *
   * @param  const Grade&
   */
  Grade(const Grade&);

  /**
   * Destructor
   *
   */
  ~Grade();

  /**
   * Overload assign operator
   *
   * @param  const Grade&
   *
   * @return const Grade&
   */
  const Grade& operator=(const Grade&);

  /**
   * Overload assign operator
   *
   * @param  double
   *
   * @return const Grade&
   */
  const Grade& operator=(double);

public:
  /**
   * Convert grade to 4 scale.
   *
   * @return Grade
   */
  Grade to4Scale() const;

  /**
   * Convert grade to A scale.
   *
   * @return std::string
   */
  std::string toAScale() const;

  /**
   * Convert grade to string.
   *
   * @return std::string
   */
  std::string toString() const;

  /**
   * Arithmetic comparision
   *
   */

  bool operator<(const Grade&) const;

  bool operator>(const Grade&) const;

  bool operator>=(const Grade&) const;

  bool operator<=(const Grade&) const;

  bool operator==(const Grade&) const;

  /**
   * Arithmetic operators
   *
   */
  Grade operator+(const Grade&) const;

  Grade operator+(double) const;

  const Grade& operator+=(const Grade&);

  const Grade& operator+=(double);

  Grade operator-(const Grade&) const;

  Grade operator-(double) const;

  const Grade& operator-=(const Grade&);

  const Grade& operator-=(double);

  Grade operator*(const Grade&) const;

  Grade operator*(double) const;

  const Grade& operator*=(const Grade&);

  const Grade& operator*=(double);

  Grade operator/(const Grade&) const;

  Grade operator/(double) const;

  const Grade& operator/=(const Grade&);

  const Grade& operator/=(double);

  /**
   * Cast to ostream.
   *
   * @param  std::ostream&
   * @param  const Grade&
   *
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream&, const Grade&);
};

#endif
