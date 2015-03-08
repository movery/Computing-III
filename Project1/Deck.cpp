#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

Deck::Deck() {
  for(int i = 0; i < 13; i++)
    for(int j = 0; j < 4; j++) {
      Card card(i, j);
      mdeck.push_back(card);
    }
}

Card Deck::drawCard() {
  Card draw = mdeck.back();
  mdeck.pop_back();
  return draw;
}

bool Deck::moreCards() {
  if(mdeck.size() <= 0) 
    return false;

  return true;
}

void Deck::shuffleDeck() {
  int temp;
  srand(time(NULL));
  for(int i = 0; i < mdeck.size(); i++) {
    temp = rand() % 52;
    iter_swap(mdeck.begin() + i, mdeck.begin() + temp);
  }
}
