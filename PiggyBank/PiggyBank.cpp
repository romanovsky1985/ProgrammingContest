#include "PiggyBank.h"

void PiggyBank::readCoins(std::istream& in) {
  size_t count;
  in >> count;
  coinValues.resize(count);
  coinWeights.resize(count);
  for (auto i = 0; i < count; i++)
    in >> coinValues[i] >> coinWeights[i];
}

/*
 * Вычисляем минимально возможную сумму шаг за шагом для каждого возможного
 * веса начиная с единицы и заканчивая заданным значением. Найденные
 * значения храним в мапе (минимальная сумма от веса) и используем на более
 * поздних шагах значения более ранних. На каждом шаге перебирая все типы
 * монет находим монету за вычетом веса которой оставшийся вес корректен и
 * достижим, а номинал монеты при этом минимален. Если такая монета есть
 * сохраняем значение минимально возможной суммы шага, иначе записываем туда
 * минус единицу. На последнем шаге получим искомый результат. 
 */
int PiggyBank::minValue(int totalWeight) const {
  std::map<int, int> steps;
  for (int stepWeight = 1; stepWeight <= totalWeight; stepWeight++) {
    int stepMinValue = -1;
    for (auto i = 0; i < coinValues.size(); i++) {
      int coinValue = coinValues[i];
      int coinWeight = coinWeights[i];
      int previousWeight = stepWeight - coinWeight;
      if (previousWeight < 0)
      	continue;
      int previousMinValue = steps[previousWeight];
      if (previousMinValue == -1)
        continue;
      if (stepMinValue == -1 || previousMinValue + coinValue < stepMinValue)
      	stepMinValue = previousMinValue + coinValue;
    }
    steps[stepWeight] = stepMinValue;
  }
  return steps[totalWeight];
}
