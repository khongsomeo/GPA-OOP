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
  // Constructors and destructor.
  Subject(std::string name, int credit, double grade) {
    _name   = name;
    _credit = credit;
    _grade  = grade;
  }

  ~Subject() {
    // Do nothing
  }
public:
  // Getter
  std::string name() {
    return _name;
  }

  int credit() {
    return _credit;
  }

  Grade grade() {
    return _grade;
  }

  // Operator overloading for std::multiset sorting since the default is "<" and we need to sort it descending.
  // Also, we really need this since std::multiset doesn't support structs by default.
  bool operator< (const Subject& subject) const {
    return (_grade > subject._grade) || (_grade == subject._grade && _credit > subject._credit);
  }

  // Method to return a vector, containing subject's info in string.
  std::vector<std::string> toStringVector() {
    std::stringstream builder;
    builder << std::fixed << std::setprecision(2);

    std::vector<std::string> subjectString;

    builder << _name;
    subjectString.push_back(builder.str());
    builder.str(std::string());
    
    builder << _credit;
    subjectString.push_back(builder.str());
    builder.str(std::string());

    builder << _grade;
    subjectString.push_back(builder.str());
    builder.str(std::string());

    builder << _grade.to4Scale();
    subjectString.push_back(builder.str());
    builder.str(std::string());

    builder << _grade.toAScale();
    subjectString.push_back(builder.str());

    return subjectString;
  }

  // Check if a subject is passed.
  bool passed() {
    return _grade >= 5.0;
  }
};

std::vector<Subject>readSubjectsFromCSVFile(std::string);
#endif
