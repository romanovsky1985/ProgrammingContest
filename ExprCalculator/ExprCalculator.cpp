#include "ExprCalculator.h"

ExprCalculator::ExprCalculator(std::string s) : expr(s) {
}

int32_t ExprCalculator::calculate() {
  index = 0;
  return getSum();
}

/*
 * Считаем сумму слагаемых, составляющих выражение
*/
int32_t ExprCalculator::getSum() {
  int32_t sum = getMult();
  while (index < expr.size()) {
    switch (expr[index]) {
      case '-':
        ++index;
        sum -= getMult();
        break;
      case '+':
        ++index;
        sum += getMult();
        break;
      default:
        return sum;
    }
  }
  return sum;
}

/*
 * Считаем каждое слагаемое как произведение его элементов
*/
int32_t ExprCalculator::getMult() {
  int32_t mult = getElement();
  while (index < expr.size()) {
    switch (expr[index]) {
      case '*':
        ++index;
        mult *= getElement();
        break;
      case '/':
        ++index;
        mult /= getElement();
        break;
      default:
        return mult;
    }
  }
  return mult;
}

/*
 * Считаем элемент в произведении - это либо выражение в скобках,
 * и тогда пропустив скобки считаем в них выраждение (рекурсивный
 * переход) либо это число, для которого считываем подряд его цифры
*/

int32_t ExprCalculator::getElement() {
  int32_t element = 0;
  if (index < expr.size() && expr[index] == '(') {
    ++index;
    element = getSum();
    ++index;
  } else {
    while (index < expr.size() && std::isdigit(expr[index])) {
      element = 10 * element + (expr[index] - '0');
      ++index;
    }
  }
  return element;
}
