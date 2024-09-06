#ifndef _ROMANFRACTION_H_
#define _ROMANFRACTION_H_

#include <map>
#include <string>
#include <iostream>

class RomanFraction {

public:

  RomanFraction(const std::string&);

  static int toInt(const std::string&);

  static std::string toRoman(int);

  friend std::ostream& operator<<(std::ostream&, const RomanFraction&);

private:

  int numerator;

  int denominator;

};

#endif
