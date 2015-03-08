#include <iostream>
#include <string>
#include "Card.h"

Card::Card(int _mface, int _msuit) {
  mface = _mface;
  msuit = _msuit;
}

Card::Card(const Card& arg) {
  mface = arg.getFace();
  msuit = arg.getSuit();
}

std::string Card::CardToString() const {
  return FACE[getFace()] + SUIT[getSuit()];
}

int Card::getFace() const {
  return mface;
}

int Card::getSuit() const {
  return msuit;
}
