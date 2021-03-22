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
  double  _sumGrades;
  double  _resultGPA;

  // Classes.
  int                    _totalClasses;
  std::multiset<Subject> _classesPassed;
  std::multiset<Subject> _classesFailed;

  // Private methods.
  bool _passed(Subject);

public:
  // Constructor & destructor.
  Personal(std::vector<Subject>);
  ~Personal();

public:
  // Setter
  void setCredit(int);
  void setSumGrades(double);
  void setResultGPA(double);
  void setTotalClasses(int);
  void setPassedClass(Subject);
  void setFailedClass(Subject);

  // Getter.
  int 	      getResultCredits();
  double      getSumGrades();
  double      getResultGPA();
  double      getGPAIn10Scale();
  double      getGPAIn4Scale();
  std::string getGPAInAScale();

  // Classes (passed/failed) related.
  int getTotalClasses();
  int getTotalClassesPassed();
  int getTotalClassesFailed();

  std::multiset<Subject> getClassesPassed();
  std::multiset<Subject> getClassesFailed();

  void addSubject(Subject);
};

#endif
