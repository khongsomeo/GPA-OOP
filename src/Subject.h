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
  int         credit;
  double      grade;
  double      scale4Grade;
  std::string textGrade;

  // Operator overloading for std::multiset sorting since the default is "<" and we need to sort it descending.
  // Also, we really need this since std::multiset doesn't support structs by default.
  bool operator < (const Subject& subject) const {
    return (grade > subject.grade) || (grade == subject.grade && credit > subject.credit);
  }

  // Method to return a vector, containing subject's info in string.
  std::vector<std::string> toStringVector() {
    std::stringstream builder;
    builder << std::fixed << std::setprecision(2);

    std::vector<std::string> subjectString;

    builder << name;
    subjectString.push_back(builder.str());
    // Clear the stringstream.
    builder.str(std::string());
    
    builder << credit;
    subjectString.push_back(builder.str());
    builder.str(std::string());

    builder << grade;
    subjectString.push_back(builder.str());
    builder.str(std::string());

    builder << scale4Grade;
    subjectString.push_back(builder.str());
    builder.str(std::string());

    builder << textGrade;
    subjectString.push_back(builder.str());

    return subjectString;
  }
};

std::vector<Subject>readSubjectsFromCSVFile(std::string);
Subject readSubject(std::string);

double convertGradeTo4Scale(double);
std::string convertGradeToAScale(double);

#endif
