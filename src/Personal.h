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

/**
 * Personal interface.
 *
 */
class IPersonal {
public:
  virtual ~IPersonal() {
    // Do nothing.
  }

public:
  virtual int sumCredits()  = 0;
  virtual Grade sumGrades() = 0;
  virtual Grade resultGPA() = 0;
  
  virtual std::vector<std::string> toStringVector() = 0;
  
  virtual int getTotalClasses() = 0;
  virtual int getTotalClassesPassed() = 0;
  virtual int getTotalClassesFailed() = 0;

  virtual std::multiset<Subject> classesPassed() = 0;
  virtual std::multiset<Subject> classesFailed() = 0;

  virtual void addSubject(Subject) = 0;
};

/**
 * Personal GPA class.
 *
 * Using this class when we need to calculate overall GPA.
 */
class PersonalGPA : public IPersonal {
protected:
  // Personal grades.
  int 	  _sumCredits;
  Grade   _sumGrades;
  Grade   _resultGPA;

  // Classes.
  std::multiset<Subject> _classesPassed;
  std::multiset<Subject> _classesFailed;

public:
  PersonalGPA() {
    _sumCredits = 0;
    _sumGrades  = 0.0;
    _resultGPA  = 0.0;
  }

  // Constructor & destructor.
  PersonalGPA(const std::vector<Subject>& subjectVector) {
    for (auto subject : subjectVector)
      addSubject(subject);
  }

  ~PersonalGPA() {
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
    _sumGrades += subject.grade() * subject.credit();
    _resultGPA = _sumGrades / (1.0 * _sumCredits);

    // Insert to passed list.
    _classesPassed.insert(subject);
  }
};

/**
 * PersonalSpecific class
 *
 * This class is used when we want to calculate average
 * of some specific classes with default class code only.
 *
 * e.g: I want to calculate average of "CSCxxxxx" course.
 * So I'll use this class, with default subjectVector and classPrefix = "CSC".
 */
class PersonalSpecific : public PersonalGPA {
public:
  PersonalSpecific(const std::vector<Subject>& subjectVector, const std::string& classPrefix) {
    _sumCredits = 0;
    _sumGrades  = 0.0;
    _resultGPA  = 0.0;

    // Add classes with specific prefix only.
    for (auto subject : subjectVector) {
      if (Utility::isPrefix(subject.name(), classPrefix))
        addSubject(subject);
    }
  }

  ~PersonalSpecific() {
    // Do nothing
  }
};

#endif
