#include "RomanFraction.h"

/*
 * В конструкторе читаем переданную строку с римской цифрой, переводим
 * числитель и знаменатель в десятичные числа и сразу сокращаем их
 * найдя НОД, остается только вывести число по требованию
 */

RomanFraction::RomanFraction(const std::string& strFraction) {
  int i = 0;
  while (i < strFraction.size() && strFraction[i] != '/')
    ++i;
  int gcd = numerator = toInt(std::string(strFraction, 0, i));
  int b = denominator = toInt(std::string(strFraction, i, strFraction.size() - i));
  while (gcd != b)
    if (gcd > b)
      gcd = gcd - b;
    else
      b = b - gcd;
  numerator /= gcd;
  denominator /= gcd;
}

/*
 * Перебираем строку от конца к началу, складывая значения
 * цифер, если значение меньше предыдущего, то вычитаем
 */
int RomanFraction::toInt(const std::string& roman) {
  static std::map<char, int> intByRoman;
  if (intByRoman.empty()) {
    intByRoman['I'] = 1;
    intByRoman['V'] = 5;
    intByRoman['X'] = 10;
    intByRoman['L'] = 50;
    intByRoman['C'] = 100;
    intByRoman['D'] = 500;
    intByRoman['M'] = 1000;
  };

  int result = 0;
  int previous = 0;
  int current = 0;
  for (auto it = roman.rbegin(); it != roman.rend(); it++) {
    current = intByRoman[*it];
    if (previous > current)
      result -= current;
    else
      result += current;
    previous = current;
  }
  return result;
}

/*
 * Делим на значения цифер от большего к меньшему, получившийся
 * остаток - количество соответствующих цифер. Двойные сочетания
 * (с вычитанием) считаем как отедельные цифры.
 */
std::string RomanFraction::toRoman(int number) {
  static std::map<int, std::string> romanByInt;
  if (romanByInt.empty()) {
   romanByInt[1] = "I";
   romanByInt[4] = "IV";
   romanByInt[5] = "V";
   romanByInt[9] = "IX";
   romanByInt[10] = "X";
   romanByInt[40] = "XL";
   romanByInt[50] = "L";
   romanByInt[90] = "XC";
   romanByInt[100] = "C";
   romanByInt[400] = "CD";
   romanByInt[500] = "D";
   romanByInt[900] = "CM";
   romanByInt[1000] = "M";
  };

  std::string result = "";
  auto it = romanByInt.rbegin();
  while (number) {
    int cnt = number / it->first;
    for (auto i = cnt; i != 0; i--)
      result += it->second;
    number = number % it->first;
    ++it;
  }
  return result;
}

std::ostream& operator<<(std::ostream& os, const RomanFraction& rf) {
  os << RomanFraction::toRoman(rf.numerator);
  if (rf.denominator != 1) {
    os << "/" << RomanFraction::toRoman(rf.denominator);
  }
  return os;
}
