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

// Subject structure.
struct Subject {
  std::string name;
  int	      credit;
  double      grade;
  double      scale4Grade;
  std::string textGrade;

  // Operator overloading for std::multiset sorting since the default is "<" and we need to sort it descending.
  // Also, we really need this since std::multiset doesn't support structs by default.
  bool operator < (const Subject& subject) const {
    return (grade > subject.grade) || (grade == subject.grade && credit > subject.credit);
  }
};

std::vector<Subject>readSubjectsFromCSVFile(std::string);
Subject readSubject(std::string);

double convertGradeTo4Scale(double);
std::string convertGradeToAScale(double);

#endif
