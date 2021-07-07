/**
 * Grade implementation.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef GRADE_H
#define GRADE_H

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
  Grade() {
    _grade = 0.0;
  }

  /**
   * Parameterised constructor
   *
   * @param  double
   */
  Grade(double grade) {
    _grade = grade;
  }

  /**
   * Parameterised constructor
   *
   * @param  const Grade&
   */
  Grade(const Grade& other) {
    _grade = other._grade;
  }

  /**
   * Overload assign operator
   *
   * @param  const Grade&
   *
   * @return const Grade&
   */
  const Grade& operator=(const Grade& other) {
    _grade = other._grade;
    return *this;
  }

  /**
   * Overload assign operator
   *
   * @param  double
   *
   * @return const Grade&
   */
  const Grade& operator=(double grade) {
    _grade = grade;
    return *this;
  }

  /**
   * Destructor
   *
   */
  ~Grade() {
    // Do nothing.
  }

public:
  /**
   * Convert grade to 4 scale.
   *
   * @return Grade
   */
  Grade to4Scale() const {
    if (_grade < 3.0) return Grade(0.0);
    if (_grade < 4.0) return Grade(1.0);
    if (_grade < 5.0) return Grade(1.5);
    if (_grade < 6.0) return Grade(2.0);
    if (_grade < 7.0) return Grade(2.5);
    if (_grade < 8.0) return Grade(3.0);
    if (_grade < 9.0) return Grade(3.5);
    return Grade(4.0);
  }

  /**
   * Convert grade to A scale.
   *
   * @return std::string
   */
  std::string toAScale() const {
    if (_grade < 3.0) return "F";
    if (_grade < 4.0) return "D";
    if (_grade < 5.0) return "D+";
    if (_grade < 6.0) return "C";
    if (_grade < 7.0) return "B";
    if (_grade < 8.0) return "B+";
    if (_grade < 9.0) return "A";
    return "A+";
  }

  /**
   * Convert grade to string.
   *
   * @return std::string
   */
  std::string toString() const {
    std::stringstream builder;

    builder << std::fixed << std::setprecision(2);

    builder << _grade;

    return builder.str();
  }

  /**
   * Arithmetic comparision
   *
   */

  bool operator<(const Grade& other) const {
    return _grade < other._grade;
  }

  bool operator>(const Grade& other) const {
    return _grade > other._grade;
  }

  bool operator>=(const Grade& other) const {
    return _grade >= other._grade;
  }

  bool operator<=(const Grade& other) const {
    return _grade <= other._grade;
  }

  bool operator==(const Grade& other) const {
    return _grade == other._grade;
  }

  /**
   * Arithmetic operators
   *
   */
  Grade operator+(const Grade& other) const {
    return Grade(_grade + other._grade);
  }

  Grade operator+(double other) const {
    return Grade(_grade + other);
  }

  const Grade& operator+=(const Grade& other) {
    _grade += other._grade;
    return *this;
  }

  const Grade& operator+=(double other) {
    _grade += other;
    return *this;
  }

  Grade operator-(const Grade& other) const {
    return Grade(_grade - other._grade);
  }

  Grade operator-(double other) const {
    return Grade(_grade - other);
  }

  const Grade& operator-=(const Grade& other) {
    _grade -= other._grade;
    return *this;
  }

  const Grade& operator-=(double other) {
    _grade -= other;
    return *this;
  }

  Grade operator*(const Grade& other) const {
    return Grade(_grade * other._grade);
  }

  Grade operator*(double other) const {
    return Grade(_grade * other);
  }

  const Grade& operator*=(const Grade& other) {
    _grade *= other._grade;
    return *this;
  }

  const Grade& operator*=(double other) {
    _grade *= other;
    return *this;
  }

  Grade operator/(const Grade& other) const {
    return Grade(_grade / other._grade);
  }

  Grade operator/(double other) const {
    return Grade(_grade / other);
  }

  const Grade& operator/=(const Grade& other) {
    _grade /= other._grade;
    return *this;
  }

  const Grade& operator/=(double other) {
    _grade /= other;
    return *this;
  }

  /**
   * Cast to ostream.
   *
   * @param  std::ostream&
   * @param  const Grade&
   *
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream& out, const Grade& grade) {
    out << grade._grade;
    return out;
  }
};

#endif
