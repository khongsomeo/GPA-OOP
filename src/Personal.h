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
 * IPersonal interface.
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
  virtual std::string option() = 0;

  virtual std::vector<std::string> toStringVector() = 0;
  virtual std::vector<std::vector<std::string>> toPassedVector() = 0;
  virtual std::vector<std::vector<std::string>> toFailedVector() = 0;
  
  virtual int getTotalClasses() = 0;
  virtual int getTotalClassesPassed() = 0;
  virtual int getTotalClassesFailed() = 0;

  virtual std::shared_ptr<IPersonal> parse(
    const std::vector<std::string>&) = 0;
  virtual void addSubject(const Subject&) = 0;
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

  /**
   * Parameterised constructor
   *
   * @param  const std::vector<Subject>&
   */
  PersonalGPA(const std::vector<Subject>& subjects) {
    for (const Subject& subject : subjects) {
      addSubject(subject);
    }
  }

public:
  /**
   * Return option.
   *
   * @return std::string
   */
  std::string option() {
    return "--gpa";
  }

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
    std::vector<std::string> stringVector;

    stringVector.push_back("Overall");
    stringVector.push_back(std::to_string(_sumCredits));
    stringVector.push_back(_resultGPA.toString());
    stringVector.push_back(_resultGPA.to4Scale().toString());
    stringVector.push_back(_resultGPA.toAScale());

    return stringVector;
  }

  /**
   * Convert to vector of string vectors.
   *
   * @return std::vector<std::vector<std::string>>
   */
  std::vector<std::vector<std::string>> toPassedVector() {
    std::vector<std::vector<std::string>> resultVector;

    for (const Subject& subject : _classesPassed) {
      resultVector.push_back(subject.toStringVector());
    }

    // Push overall.
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

    for (const Subject& subject : _classesFailed) {
      resultVector.push_back(subject.toStringVector());
    }

    return resultVector;
  }

  /**
   * Return total classes.
   *
   * @return int
   *
   * @throw  std::runtime_error
   */
  int getTotalClasses() {
    int totalClasses = _classesPassed.size() + _classesFailed.size();

    // Handling the situtation that no class added.
    if (0 == totalClasses) {
      throw std::runtime_error("No class was added.");
    }

    return totalClasses;
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
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> parse(
    const std::vector<std::string>& argv) {
    std::vector<Subject> subjects = Subject::parseSubjectVector(
      argv.at(1)
    );

    return std::make_shared<PersonalGPA>(subjects);
  }

  /**
   * Add a new subject.
   *
   * @param  const Subject&
   */
  void addSubject(const Subject& subject) {
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
   * @param  const std::vector<Subject>&
   * @param  const std::string&
   */
  PersonalSpecific(
    const std::vector<Subject>& subjects,
    const std::string& coursePrefix) {
    for (const Subject& subject : subjects) {
      if (Utility::isPrefix(subject.name(), coursePrefix)) {
        addSubject(subject);
      }
    }
  }

public:
  /**
   * Return option
   *
   * @return std::string
   */
  std::string option() override {
    return "--specific";
  }

  /**
   * Parse a PersonalSpecific object.
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> parse(
    const std::vector<std::string>& argv) {
    std::vector<Subject> subjects = Subject::parseSubjectVector(
      argv.at(1)
    );

    return std::make_shared<PersonalSpecific>(
      subjects,
      argv.at(3)
    );
  }
};

/**
 * PersonalExcept class
 *
 * This class is used when we need to calculate GPA except some classes.
 *
 * For example, I need to calculate my GPA except PE, English and National Defense.
 * So I'll add these courses's code to except.txt, and use this class instead.
 */
class PersonalExcept : public PersonalGPA {
private:
  std::multiset<std::string> _ignoredCourses;

public:
  PersonalExcept() {
    // Do nothing.
  }

  ~PersonalExcept() {
    // Do nothing.
  }

  /**
   * Parameterised constructor for PersonalExcept
   *
   * @param  const std::vector<Subject>&
   * @param  const std::vector<std::string>&
   */
  PersonalExcept(
    const std::vector<Subject>& subjects,
    const std::vector<std::string>& ignoredCourses) {
    // Insert ignored courses inside a multiset.
    for (const std::string& course : ignoredCourses) {
      _ignoredCourses.insert(course);
    }

    // Add Subject when it doesn't exist inside _ignoredCourses.
    for (const Subject& subject : subjects) {
      if (_ignoredCourses.find(subject.name()) ==
          _ignoredCourses.end()) {
        addSubject(subject);
      }
    }
  }

public:
  /**
   * Return option.
   *
   * @return std::string
   */
  std::string option() {
    return "--ignore";
  }

  /**
   * Parse a PersonalExcept object.
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> parse(
    const std::vector<std::string>& argv) {
    std::vector<Subject> subjectVector = Subject
      ::parseSubjectVector(argv.at(1));
    std::vector<std::string> ignoredCourses = InputHelper
      ::readFileLines(argv.at(3));

    return std::make_shared<PersonalExcept>(
      subjectVector,
      ignoredCourses
    );
  }
};

/**
 * PersonalFactory class - Singleton pattern
 *
 * This class is used to generate Personal interface.
 */
class PersonalFactory {
private:
  // List of prototypes.
  std::vector<std::shared_ptr<IPersonal>> _prototypes;

  // Setting up.
  PersonalFactory() {
    // Push list of prototypes.
    _prototypes.push_back(std::make_shared<PersonalGPA>());
    _prototypes.push_back(std::make_shared<PersonalSpecific>());
    _prototypes.push_back(std::make_shared<PersonalExcept>());
  }

public:
  /**
   * Destructor
   *
   */
  ~PersonalFactory() {
    // Do nothing.
  }

public:
  /**
   * Init a new instance.
   *
   * @return std::shared_ptr<PersonalFactory>
   */
  static std::shared_ptr<PersonalFactory> getInstance() {
    static std::shared_ptr<PersonalFactory> instance(
      new PersonalFactory()
    );

    return instance;
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
   * @param  const std::string&
   *
   * @return std::shared_ptr<IPersonal>
   */
  std::shared_ptr<IPersonal> create(
    int argc,
    char** argv) {
    // So the idea is maintaining the input line ./<program name> <input csv> <option> <parameter>

    std::vector<std::string> arguments;
    for (int i = 0; i < argc; ++i) {
      arguments.push_back(
        std::string(argv[i])
      );
    }

    if (argc - 1 > 1) {
      // Detect prototype to use.
      for (const auto& it : _prototypes) {
        if (it->option() == std::string(arguments.at(2))) {
          return it->parse(arguments);
        }
      }
    }

    return _prototypes.at(0)->parse(arguments);
  }
};
#endif
