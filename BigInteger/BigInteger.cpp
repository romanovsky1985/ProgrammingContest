#include "BigInteger.h"

/*
 * Суммирование - поразрядно складываем цифры обоих чисел справа
 * налево, записывая результат в digits слева направо (чтобы их
 * записывать в конец вектора), затем переворачиваем результат.
*/
BigInteger BigInteger::operator+(const BigInteger& right) const {
  std::vector<data_t> digits;
  data_t digit = 0;
  auto l = data.rbegin();
  auto r = right.data.rbegin();
  while (digit != 0 || l != data.rend() || r != right.data.rend()) {
    if (l != data.rend())
      digit += *l++;
    if (r != right.data.rend())
      digit += *r++;
    digits.push_back(digit % 10);
    digit /= 10;
  }
  BigInteger result;
  result.data = std::vector<data_t>(digits.rbegin(), digits.rend());
  return result;
}

/*
 * Умножение на цифру - умножаем на заданную цифру все цифры числа
 * справа налево (от младшего разряда к старшему), аналогичным
 * образом записывая их слева направо и переворачивая в итоге.
*/
BigInteger BigInteger::operator*(data_t mult) const {
  std::vector<data_t> digits;
  data_t digit = 0;
  auto i = data.rbegin();
  while (digit != 0 || i != data.rend()) {
    if (i != data.rend())
      digit += *i++ * mult;
    digits.push_back(digit % 10);
    digit /= 10;
  }
  BigInteger result;
  result.data = std::vector<data_t>(digits.rbegin(), digits.rend());
  return result;
}

/*
 * Сдвиг - сдвигаем число на некоторое количество разрядов, то есть
 * дописываем заданное количество нулей в его конец.
*/
BigInteger BigInteger::operator<<(size_t shift) const {
  std::vector<data_t> zeros(shift, 0);
  BigInteger result(*this);
  result.data.insert(result.data.end(), zeros.begin(), zeros.end());
  return result;
}

/*
 * Умножение на другое число - поочередно умножаем правое число
 * на каждую из цифер левого числа, сдвигая каждый результат на
 * соответствующее число разрядов суммируем их в итоговом значении.
*/
BigInteger BigInteger::operator*(const BigInteger& mult) const {
  BigInteger result;
  size_t radix = 0;
  auto i = data.rbegin();
  while (i != data.rend()) {
    BigInteger tmp = mult * *i++;
    tmp = tmp << radix++;
    result = result + tmp;
  }
  return result;
}

/*
 * Ввод - пропустив все не цифровые символы и ведущие нули считываем
 * все цифры до первого не цифрового символа.
*/
std::istream& operator>>(std::istream& is, BigInteger& big)
{
  big.data.clear();
  auto ch = is.get();
  while (!std::isdigit(ch))
    ch = is.get();
  while (ch == '0')
    ch = is.get();
  while (std::isdigit(ch)) {
    big.data.push_back(ch - '0');
    ch = is.get();
  }
  is.unget();
  return is;
}

/*
 * Вывод - если вектор данных пуст, значит число есть ноль, который
 * и отправляем в поток вывода, иначе - все цифры друг за другом.
*/
std::ostream& operator<<(std::ostream& os, const BigInteger& big) {
  if (big.data.empty())
    return os << '0';

  auto i = big.data.begin();
  while (i != big.data.end())
    os << (int)*i++;
  return os;
}
