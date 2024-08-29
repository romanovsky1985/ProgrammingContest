#ifndef _PIGGYBANK_H_
#define _PIGGYBANK_H_

#include <vector>
#include <map>
#include <iostream>

class PiggyBank {

public:

  int minValue(int totalWeigth) const;

  void readCoins(std::istream& in);

private:

  std::vector<int> coinValues;

  std::vector<int> coinWeights;

};

#endif

