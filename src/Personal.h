/**
 * This file defines Personal class.
 *
 * Code by @trhgquan - https://github.com/trhgquan.
 */

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef PERSONAL_H
#define PERSONAL_H

class Personal {
private:
  // Personal grades.
  int 	  _sumCredits;
  Grade   _sumGrades;
  Grade   _resultGPA;

  // Classes.
  std::multiset<Subject> _classesPassed;
  std::multiset<Subject> _classesFailed;

public:
  // Constructor & destructor.
  Personal(const std::vector<Subject>& subjectVector) {
    _sumCredits = 0;
    _sumGrades = Grade(0.0);
    _resultGPA = Grade(0.0);

    for (auto subject : subjectVector)
      addSubject(subject);
  }

  ~Personal() {
    // Do nothing;
  }

public:
  // Getter.
  int sumCredits() {
    return _sumCredits;
  }

  Grade sumGrades() {
    return _sumGrades;
  }

  Grade resultGPA() {
    return _resultGPA;
  }

  // Convert Personal class into a string vector.
  std::vector<std::string> toStringVector() {
    std::stringstream builder;
    std::vector<std::string> resultVector;

    builder << std::fixed << std::setprecision(2);

    builder << "GPA";
    resultVector.push_back(builder.str());
    builder.str(std::string());

    builder << _sumCredits;
    resultVector.push_back(builder.str());
    builder.str(std::string());

    builder << _resultGPA;
    resultVector.push_back(builder.str());
    builder.str(std::string());

    builder << _resultGPA.to4Scale();
    resultVector.push_back(builder.str());
    builder.str(std::string());

    builder << _resultGPA.toAScale();
    resultVector.push_back(builder.str());
    builder.str(std::string());
      
    return resultVector;
  }

  // Classes (passed/failed) related.
  int getTotalClasses() {
    return _classesPassed.size() + _classesFailed.size();
  }

  int getTotalClassesPassed() {
    return _classesPassed.size();
  }

  int getTotalClassesFailed() {
    return _classesFailed.size();
  }

  std::multiset<Subject> classesPassed() {
    return _classesPassed;
  }

  std::multiset<Subject> classesFailed() {
    return _classesFailed;
  }

  // Handling how we add a new subject.
  void addSubject(Subject subject) {
    // If not passed, then insert into failed list.
    if (!subject.passed()) {
      _classesFailed.insert(subject);
      return;
    }

    // Calculate new GPA.
    _sumCredits += subject.credit();
    _sumGrades += subject.grade() * Grade(subject.credit());
    _resultGPA = _sumGrades / Grade(1.0 * _sumCredits);

    // Insert to passed list.
    _classesPassed.insert(subject);
  }
};

#endif
