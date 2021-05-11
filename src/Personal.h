/**
 * This file defines Personal class.
 *
 * Code by @trhgquan - https://github.com/trhgquan.
 */

#pragma once

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
  virtual std::vector<std::vector<std::string>> toPassedVector() = 0;
  virtual std::vector<std::vector<std::string>> toFailedVector() = 0;
  
  virtual int getTotalClasses() = 0;
  virtual int getTotalClassesPassed() = 0;
  virtual int getTotalClassesFailed() = 0;

  virtual std::shared_ptr<IPersonal> parse(char**) = 0;
  virtual void addSubject(Subject) = 0;
};

/**
 * Personal GPA class.
 *
 * Using this class when we need to calculate overall GPA.
 */
class PersonalGPA : public IPersonal {
protected:
  // Stores personal grades & credits.
  int   _sumCredits = 0;
  Grade _sumGrades  = 0.0;
  Grade _resultGPA  = 0.0;

  // Stores classes passed / failed.
  std::multiset<Subject> _classesPassed;
  std::multiset<Subject> _classesFailed;

public:
  PersonalGPA() {
    // Do nothing;
  }

  ~PersonalGPA() {
    // Do nothing;
  }

  PersonalGPA(const std::vector<Subject>& subjects) {
    for (int i = 0; i < subjects.size(); ++i) {
      addSubject(subjects[i]);
    }
  }

public:
  /**
   * Return total credits
   *
   * @return int
   */
  int sumCredits() {
    return _sumCredits;
  }

  /**
   * Return sum grades.
   * 
   * @return Grade
   */
  Grade sumGrades() {
    return _sumGrades;
  }

  /**
   * Return GPA
   *
   * @return Grade
   */
  Grade resultGPA() {
    return _resultGPA;
  }

  /**
   * Convert class to string vector.
   *
   * @return std::vector<std::string>
   */
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

  /**
   * Convert to vector of string vectors.
   *
   * @return std::vector<std::vector<std::string>>
   */
  std::vector<std::vector<std::string>> toPassedVector() {
    std::vector<std::vector<std::string>> resultVector;

    for (auto subject : _classesPassed) {
      resultVector.push_back(subject.toStringVector());
    }

    resultVector.push_back(toStringVector());

    return resultVector;
  }

  /**
   * Just like above, but for failed.
   *
   * @return std::vector<std::vector<std::string>>
   */
  std::vector<std::vector<std::string>> toFailedVector() {
    std::vector<std::vector<std::string>> resultVector;

    for (auto subject : _classesFailed) {
      resultVector.push_back(subject.toStringVector());
    }

    return resultVector;
  }

  /**
   * Return total classes.
   *
   * @return int
   */
  int getTotalClasses() {
    return _classesPassed.size() + _classesFailed.size();
  }

  /**
   * Return total passed classes.
   *
   * @return int
   */
  int getTotalClassesPassed() {
    return _classesPassed.size();
  }

  /**
   * Return total failed classes.
   *
   * @return int
   */
  int getTotalClassesFailed() {
    return _classesFailed.size();
  }

  /**
   * Parse data into Personal
   *
   * @param  char**
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> parse(char** argv) {
    std::vector<Subject> subjects = Subject::parseSubjectVector(std::string(argv[1]));

    return std::make_shared<PersonalGPA>(subjects);
  }

  /**
   * Add a new subject.
   *
   * @param  Subject
   */
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
  PersonalSpecific() {
    // Do nothing
  }

  ~PersonalSpecific() {
    // Do nothing
  }

  /**
   * Parameterised constructor.
   *
   * @param  std::vector<Subject>
   * @param  const std::string&
   */
  PersonalSpecific(std::vector<Subject> subjects, const std::string& coursePrefix) {
    for (int i = 0; i < subjects.size(); ++i) {
      if (Utility::isPrefix(subjects[i].name(), coursePrefix)) {
          addSubject(subjects[i]);
      }
    }
  }

public:
  /**
   * Parse a PersonalSpecific object.
   *
   * @param  char**
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> parse(char** argv) override {
    std::vector<Subject> subjects = Subject::parseSubjectVector(std::string(argv[1]));

    return std::make_shared<PersonalSpecific>(subjects, std::string(argv[2]));
  }
};


/**
 * PersonalFactory class - Singleton pattern
 *
 * This class is used to generate Personal interface.
 */
class PersonalFactory {
private:
  // Singleton
  inline static PersonalFactory* _instance = NULL;

  // List of prototypes.
  std::vector<std::shared_ptr<IPersonal>> _prototypes;

  // Setting up.
  PersonalFactory() {
    _prototypes.push_back(std::make_shared<PersonalGPA>());
    _prototypes.push_back(std::make_shared<PersonalSpecific>());
  }
public:
  ~PersonalFactory() {
    delete _instance;
  }

public:
  /**
   * Init a new instance.
   *
   * @return PersonalFactory*
   */
  static PersonalFactory* instance() {
    if (_instance == NULL) {
      _instance = new PersonalFactory();
    }

    return _instance;
  }

  /**
   * Return total items inside _prototypes.
   *
   * @return int
   */
  int prototypeSize() {
    return _prototypes.size();
  }

  /**
   * Create a new instacne of IPersonal
   *
   * @param  const std::vector<Subject>&
   * @param  const std::string
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> create(const int& argc, char** argv) {
    // New instance's pointer
    std::shared_ptr<IPersonal> newPersonal = _prototypes[argc - 2]->parse(argv);

    return newPersonal;
  }
};
#endif
