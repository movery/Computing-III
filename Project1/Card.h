#ifndef _CARD_H
#define _CARD_H

#include <string>

static std::string FACE[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
static std::string SUIT[4] = {"S", "H", "D", "C"};

class Card {
 private:
  int msuit;
  int mface;
 public:
  Card(int, int);
  Card(const Card&);
  int getFace() const;
  int getSuit() const;
  std::string CardToString() const;
};

#endif
