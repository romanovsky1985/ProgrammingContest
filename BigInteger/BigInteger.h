#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_

#include <vector>
#include <iostream>
#include <cctype>

/*
 * Для хранения цифер числа используем vector, и можно обойтись дефолтными конструкторами
 * и деструктором. Реализовать умножение двух длинных чисел можно через их сложение,
 * умножение числа на цифру и сдвиг на нужное количество разрядов. Также понадобится
 * ввод и вывод. Вот необходимый минимум для нашего класса BigInteger.
*/

class BigInteger {

public:

  typedef uint8_t data_t;

  BigInteger operator+(const BigInteger&) const;

  BigInteger operator*(data_t) const;

  BigInteger operator<<(size_t) const;

  BigInteger operator*(const BigInteger&) const;

  friend std::ostream& operator<<(std::ostream&, const BigInteger&);

  friend std::istream& operator>>(std::istream&, BigInteger&);

private:

  std::vector<data_t> data;

};

#endif
