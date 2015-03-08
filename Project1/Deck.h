#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include "Card.h"

class Deck {
 private:
  std::vector<Card> mdeck;
 public:
  Deck();
  Card drawCard();
  bool moreCards();
  void shuffleDeck();
};

#endif
