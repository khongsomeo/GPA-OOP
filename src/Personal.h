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
  int 	  sumCredits;
  double  sumGrades;
  double  resultGPA;

  // Classes.
  std::multiset<Subject> classesPassed;
  std::multiset<Subject> classesFailed;

  // Private methods.
  bool passed(Subject);

public:
  Personal(std::vector<Subject>);
  ~Personal(){}

  // Setter
  void setCredit(int);
  void setSumGrades(double);
  void setResultGPA(double);
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
  int getTotalClassesPassed();
  int getTotalClassesFailed();

  std::multiset<Subject> getClassesPassed();
  std::multiset<Subject> getClassesFailed();

  void addSubject(Subject);
};

#endif
