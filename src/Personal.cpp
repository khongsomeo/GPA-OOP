/**
 * Personal APIs.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"Personal.h"

/**
 * Constructor for Personal class.
 *
 */
Personal::Personal(std::vector<Subject> subjectsVector) {
  // Set default greades to 0.
  setCredit(0);
  setSumGrades(0);
  setResultGPA(0);

  // Set default classes to 0.
  setTotalClasses(0);

  // Add subjects to Personal.
  for (auto subject : subjectsVector) addSubject(subject);
}

/**
 * Destructor for Personal class.
 *
 */
Personal::~Personal() {
  // Do nothing.
}

/**
 * This function set credit for Personal.
 *
 * @param int
 */
void Personal::setCredit(int credit) {
  _sumCredits = credit;
}

/**
 * This function set sum grades for Personal.
 *
 * @param double
 */
void Personal::setSumGrades(double grades) {
  _sumGrades = grades;
}

/**
 * This function set result GPA for Personal.
 *
 * @param double
 */
void Personal::setResultGPA(double grades) {
  _resultGPA = grades;
}

/**
 * This function set total classes for Personal.
 *
 * @param classes
 */
void Personal::setTotalClasses(int classes) {
  _totalClasses = classes;
}

/**
 * This function insert a passed class into passed set.
 *
 * @param Subject
 */
void Personal::setPassedClass(Subject subject) {
  _classesPassed.insert(subject);
}

/**
 * This function insert a failed class into failed set.
 *
 * @param Subject
 */
void Personal::setFailedClass(Subject subject) {
  _classesFailed.insert(subject);
}

/**
 * This function get result credit from Personal class.
 *
 * @return int
 */
int Personal::getResultCredits() {
  return _sumCredits;
}

/**
 * This function get sum grades from Personal class.
 *
 * @return double
 */
double Personal::getSumGrades() {
  return _sumGrades;
}

/**
 * This function get result GPA from Personal class.
 *
 * @return double
 */
double Personal::getResultGPA() {
  return _resultGPA;
}

/**
 * This function get result GPA (in 10 - scale) from Personal class.
 *
 * @return double
 */
double Personal::getGPAIn10Scale() {
  return getResultGPA();
}

/**
 * This function get result GPA (in 4 - scale) from Personal class.
 *
 * @return double
 */
double Personal::getGPAIn4Scale() {
  return convertGradeTo4Scale(getResultGPA());
}

/**
 * This function get result GPA (in A - scale) from Personal class.
 *
 * @return std::string
 */
std::string Personal::getGPAInAScale() {
  return convertGradeToAScale(getResultGPA());
}

/**
 * This function return total classes.
 *
 * @return int
 */
int Personal::getTotalClasses() {
  return _totalClasses;
}

/**
 * This function return a number represents how many classes passed.
 *
 * @return int
 */
int Personal::getTotalClassesPassed() {
  return _classesPassed.size();
}

/**
 * This function return a number represents how many classes failed.
 *
 * @return int
 */
int Personal::getTotalClassesFailed() {
  return _classesFailed.size();
}

/**
 * This function return a set of passed classes.
 *
 * @return std::multiset<Subject>
 */
std::multiset<Subject> Personal::getClassesPassed() {
  return _classesPassed;
}

/**
 * This function return a set of failed classes.
 *
 * @return std::multiset<Subject>
 */
std::multiset<Subject> Personal::getClassesFailed() {
  return _classesFailed;
}

/**
 * This function add a subject into result.
 *
 * @param Subject
 */
void Personal::addSubject(Subject subject) {
  // Count this subject.
  setTotalClasses(getTotalClasses() + 1);

  // If a class is failed, insert it into failed set.
  if (!Personal::_passed(subject)) {
    setFailedClass(subject);
    return;
  }

  // Insert subject into passed set.
  setPassedClass(subject);

  // Calculate total credits and GPA.
  setCredit(getResultCredits() + subject.credit);
  setSumGrades(getSumGrades() + (1.0 * subject.credit * subject.grade));
  setResultGPA(getSumGrades() / (1.0 * getResultCredits()));
}

/**
 * This function check if a grade is enough to pass.
 *
 * @param  Subject
 * @return bool
 */
bool Personal::_passed(Subject subject) {
  return subject.grade >= 5.0;
}
