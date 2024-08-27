#ifndef _EXPRCALCULATOR_H_
#define _EXPRCALCULATOR_H_

#include <string>
#include <cctype>

/*
 * Согласно порядку арифметических операций любое выражение можно посчитать
 * как сумму слагаемых, каждое из которых есть произведение элементов,
 * каждый из которых, в свою очередь, это либо число, либо вновь выражение в
 * скобках (здесь, собственно, и осуществляется рекурсивный переход)
*/

class ExprCalculator {

public:

  ExprCalculator(std::string);

  int32_t calculate();

private:

  std::string expr;
  
  size_t index;

  int32_t getSum();
  
  int32_t getMult();
  
  int32_t getElement();
  
};

#endif
