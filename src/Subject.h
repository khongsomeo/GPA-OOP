/**
 * This file defines the structure of a subject.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {
private:
  std::string _name;
  int         _credit;
  Grade       _grade;

public:
  /**
   * Parameterised constructor
   *
   * @param  std::string
   * @param  int
   * @param  double
   */
  Subject(std::string name, int credit, double grade) {
    _name   = name;
    _credit = credit;
    _grade  = grade;
  }

  /**
   * Parameterised constructor overload.
   *
   * @param  std::string
   * @param  int
   * @param  Grade
   */
  Subject(std::string name, int credit, Grade grade) {
    _name   = name;
    _credit = credit;
    _grade  = grade;
  }

  /**
   * Destructor
   */
  ~Subject() {
    // Do nothing
  }
public:
  /**
   * Subject name
   *
   * @return std::string
   */
  std::string name() {
    return _name;
  }

  /**
   * Subject credit
   *
   * @return int
   */
  int credit() {
    return _credit;
  }

  /**
   * Subject grade
   *
   * @return Grade
   */
  Grade grade() {
    return _grade;
  }

  // Operator overloading for std::multiset sorting since the default is "<" and we need to sort it descending.
  // Also, we really need this since std::multiset doesn't support structs by default.
  bool operator< (const Subject& subject) const {
    return (_grade > subject._grade) || (_grade == subject._grade && _credit > subject._credit);
  }

  /**
   * Convert Subject to a string vector.
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> toStringVector() {
    std::vector<std::string> subjectStringVector;

    subjectStringVector.push_back(_name);
    subjectStringVector.push_back(std::to_string(_credit));
    subjectStringVector.push_back(_grade.toString());
    subjectStringVector.push_back(_grade.to4Scale());
    subjectStringVector.push_back(_grade.toAScale());

    return subjectStringVector;
  }

  /**
   * Check if subject passed.
   *
   * @return bool
   */
  bool passed() {
    return _grade >= 5.0;
  }

  /**
   * This method parse a subject from a CSV line.
   *
   * @param  const std::string&
   *
   * @return Subject
   */
  static Subject parse(const std::string& buffer) {
    std::vector<std::string> tokens = InputHelper::splitTokens(buffer, ",");

    return Subject(tokens[0], stoi(tokens[1]), stod(tokens[2]));
  }

  /**
   * This method parse a vector of Subjects from a CSV file.
   *
   * @param  const std::string&
   *
   * @return std::vector<Subject>
   */
  static std::vector<Subject> parseSubjectVector(const std::string& fileName) {
    std::vector<Subject> subjects;

    std::vector<std::string> lineStrings = InputHelper::readFileLines(fileName);

    // Read csv file by line.
    for (int i = 0; i < lineStrings.size(); ++i) {
      try {
        subjects.push_back(parse(lineStrings[i]));
      }
 
      catch (const std::exception& e) {
        std::cout << "Error happened while reading file " << fileName
                  << ", on line " << i + 1
                  << " (" << e.what() << ")" 
                  << '\n';
      }
    }

    return subjects;
  }
};
#endif
