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
  Grade() {
    _grade = 0.0;
  }

  Grade(double grade) {
    _grade = grade;
  }

  Grade(const Grade& other) {
    _grade = other._grade;
  }
  
  Grade& operator=(const Grade& other) {
    _grade = other._grade;
    return *this;
  }

  Grade& operator=(double grade) {
    _grade = grade;
    return *this;
  }

  ~Grade() {
    // Do nothing.
  }

public:
  // Convert grade to scales.
  
  double to4Scale() {
    if (_grade < 3.0) return 0.0;
    if (_grade < 4.0) return 1.0;
    if (_grade < 5.0) return 1.5;
    if (_grade < 6.0) return 2.0;
    if (_grade < 7.0) return 2.5;
    if (_grade < 8.0) return 3.0;
    if (_grade < 9.0) return 3.5;
    return 4.0;
  }

  std::string toAScale() {
    if (_grade < 3.0) return "F";
    if (_grade < 4.0) return "D";
    if (_grade < 5.0) return "D+";
    if (_grade < 6.0) return "C";
    if (_grade < 7.0) return "B";
    if (_grade < 8.0) return "B+";
    if (_grade < 9.0) return "A";
    return "A+";
  }

  // Comparision.

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

  // Arithmetic
  Grade operator+(const Grade& other) const {
    return Grade(_grade + other._grade);
  }

  Grade operator+(double other) const {
    return Grade(_grade + other);
  }
  
  Grade& operator+=(const Grade& other) {
    _grade += other._grade;
    return *this;
  }

  Grade& operator+=(double other) {
    _grade += other;
    return *this;
  }
  
  Grade operator-(const Grade& other) const {
    return Grade(_grade - other._grade);
  }

  Grade operator-(double other) const {
    return Grade(_grade - other);
  }
  
  Grade& operator-=(const Grade& other) {
    _grade -= other._grade;
    return *this;
  }

  Grade& operator-=(double other) {
    _grade -= other;
    return *this;
  }
  
  Grade operator*(const Grade& other) const {
    return Grade(_grade * other._grade);
  }

  Grade operator*(double other) const {
    return Grade(_grade * other);
  }
  
  Grade& operator*=(const Grade& other) {
    _grade *= other._grade;
    return *this;
  }

  Grade& operator*=(double other) {
    _grade *= other;
    return *this;
  }
  
  Grade operator/(const Grade& other) const {
    return Grade(_grade / other._grade);
  }

  Grade operator/(double other) const {
    return Grade(_grade / other);
  }
  
  Grade& operator/=(const Grade& other) {
    _grade /= other._grade;
    return *this;
  }

  Grade& operator/=(double other) {
    _grade /= other;
    return *this;
  }

  // Print Grade to the ostream.
  friend std::ostream& operator<<(std::ostream& out, const Grade& grade) {
    out << grade._grade; 
    return out;
  }
};

#endif
