#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include "Deck.h"
#include "Card.h"

using namespace std;

/* Determines the value of a hand based on whether or not it */
/* it contains a Flush, Straight, Full-House, 4-of a kind,   */
/* Three of a kind, 2-Pair or 1-Pair, or just a single       */
/* High-Card                                                 */
int evaluateHand(vector<Card>&);

/* Helper function to sort each hand to make evaluating it   */
/* and reading it much easier on the eyes.                   */
bool compareCards(const Card&, const Card&);

/* Determines a stronger hand. First evaluates the hands     */
/* Based on the scores (the two integers). If they are equal */
/* it iterates through and determines which one has better   */
/* "High Cards". If all the cards have the same face value   */
/* a tie is declared. REQUIRES THE HAND TO BE SORTED BY FACE */
int compareHands(const vector<Card>&, const vector<Card>&, int, int);

/* Basic Heuristic to determine how to alter the hand, and   */
/* then alters it. Explained in the README.                  */
void dealerReEvaluate(Deck&, vector<Card>&, int);

int main() {

  Deck d1;
  vector<Card> hand1;
  vector<Card> hand2;
  string input;
  int h1Score, h2Score, flag = 0;

  d1.shuffleDeck();

  /* Draw Cards for each hand */
  for(int i = 0; i < 5; i++) {
    hand1.push_back(d1.drawCard());
    hand2.push_back(d1.drawCard());
  }
  
  /* Sort and Display the Dealer's Hand */
  sort(hand1.begin(), hand1.end(), compareCards);
  cout << "Dealer's Hand: " << endl;
  for(int i = 0; i < 5; i++) 
    cout << "XX" << " ";
  cout << "\n" << endl;

  /* Sort and Display the Player's Hand */
  sort(hand2.begin(), hand2.end(), compareCards);
  cout << "Player's Hand: " << endl;
  for(int i = 0; i < 5; i++) 
    cout << hand2[i].CardToString() << " ";
  cout << "\n" << endl;
  
  h1Score = evaluateHand(hand1);
  dealerReEvaluate(d1, hand1, h1Score);

  /* Ask Player if they want to throw away cards, and which cards */
  cout << "Which cards would you like to discard?" << endl;
  cout << "Enter card numbers in ascending order (1, 2, 3, 4, 5)" << endl;
  getline(cin, input);
  istringstream sin(input);
  int temp;
  for(int offset = 0; sin >> temp; offset++) {
    hand2.erase(hand2.begin() + (temp - 1) - offset);
    hand2.push_back(d1.drawCard());
  }
  cout << endl;

  /* Sort and Display the Dealer's Hand */
  sort(hand1.begin(), hand1.end(), compareCards);
  cout << "Dealer's Hand: " << endl;
  for(int i = 0; i < 5; i++) 
    cout << hand1[i].CardToString() << " ";
  cout << "\n" << endl;

  /* Sort and Display the Player's Hand */
  sort(hand2.begin(), hand2.end(), compareCards);
  cout << "Player's Hand: " << endl;
  for(int i = 0; i < 5; i++) 
    cout << hand2[i].CardToString() << " ";
  cout << "\n" << endl;

  /* Get Evaluation Values */
  h2Score = evaluateHand(hand2);

  /* Determine a Winner */
  switch(compareHands(hand1, hand2, h1Score, h2Score)) {
  case 1:
    cout << "Dealer Wins!" << endl;
    break;
  case 2:
    cout << "Player Wins!" << endl;
    break;
  case 3:
    cout << "Tie!" << endl;
    break;
  }

  return 0;
}

int evaluateHand(vector<Card>& hand) {
  int flush, straight, four, full_house, three, pairs, k;
  flush = straight = four = full_house = three = pairs = 0;

  /* Checks for a flush */
  k = 0;
  for(int i = 0; i < 4; i++)
    if(hand[i].getSuit() == hand[i + 1].getSuit())
      k++;
  if(k == 4)
    flush = 1;

  /* Checks for a straight (Aces High and Aces Low) */
  k = 0;
  for(int i = 0; i < 4; i++)
    if(hand[i].getFace() == hand[i + 1].getFace() - 1)
      k++;
  if(k == 4)
    straight = 1;
  if(k == 3 && hand[3].getFace() == 3 && hand[4].getFace() == 12)
    straight = 1;

  /* Checks for Four of a Kind */
  k = 0;
  for(int i = 0; i < 2; i++) {
    k = i; 
    while(k < i + 3 && hand[k].getFace() == hand[k + 1].getFace()) 
      k++;
    if(k == i + 3)
      four = 1;
  }
  
  /* Checks for Three of a Kind and Full House */
  k = 0;
  for(int i = 0; i < 3; i++) {
    k = i;
    while(k < i + 2 && hand[k].getFace() == hand[k + 1].getFace())
      k++;
    if(k == i + 2) {
      three = 1;
      switch(i) {
      case 0:
	if(hand[3].getFace() == hand[4].getFace())
	  full_house = 1;
	break;
      case 1:
	if(hand[0].getFace() == hand[4].getFace())
	  full_house = 1;
	break;
      case 2:
	if(hand[0].getFace() == hand[1].getFace())
	  full_house = 1;
	break;
      }
    }
  }

  /* First set of return values */
  if(straight && flush)
    return 9;
  else if(four)
    return 8;
  else if(full_house)
    return 7;
  else if(flush)
    return 6;
  else if(straight)
    return 5;
  else if(three)
    return 4;

  /* Checks for One Pair or Two Pair */
  for(int i = 0; i < 4; i++)
    if(hand[i].getFace() == hand[i + 1].getFace())
      pairs++;

  /* Second set of return values */
  if(pairs == 2)
    return 3;
  if(pairs == 1)
    return 2;
  else
    return 1;
}

bool compareCards(const Card& card1, const Card& card2) {
  return card1.getFace() < card2.getFace();
}

int compareHands(const vector<Card>& hand1, const vector<Card>& hand2, int h1Score, int h2Score) {
  if(h1Score > h2Score)
    return 1;
  else if(h1Score < h2Score)
    return 2;
  else {
    for(int i = 4; i > 0; i--) {
      if(hand1[i].getFace() > hand2[i].getFace()) {
	return 1;
      } else if(hand1[i].getFace() < hand2[i].getFace()) {
	return 2;
      }
    }
    return 3;
  }
}

void dealerReEvaluate(Deck& d1, vector<Card>& hand, int eval) {
  int temp1, temp2, temp3, temp4, pair = 0;
  switch(eval) {
  case 1:
    hand.erase(hand.begin(), hand.begin() + 3);
    hand.push_back(d1.drawCard());
    hand.push_back(d1.drawCard());
    hand.push_back(d1.drawCard());
    break;
  case 2:
    for(int i = 0; i < 4; i++)
      if(hand[i].getFace() == hand[i + 1].getFace()) {
	temp1 = i;
	temp2 = i + 1;
      }
    for(int i = 4; i >= 0; i--)
      if(i != temp1 && i != temp2) {
	hand.erase(hand.begin() + i);
      }
    hand.push_back(d1.drawCard());
    hand.push_back(d1.drawCard());
    hand.push_back(d1.drawCard());
    break;
  case 3:
    for(int i = 0; i < 4; i++)
      if(hand[i].getFace() == hand[i + 1].getFace() && pair == 0) {
	temp1 = i;
	temp2 = i + 1;
	pair++;
      } else if(hand[i].getFace() == hand[i + 1].getFace() && pair == 1) {
	temp3 = i;
	temp4 = i + 1;
	pair++;
      }
    for(int i = 4; i >= 0; i--)
      if(i != temp1 && i != temp2 && i != temp3 && i != temp4) {
	hand.erase(hand.begin() + i);
      }
    hand.push_back(d1.drawCard());
    break;
  case 4:
    for(int i = 0; i < 3; i++)
      if(hand[i].getFace() == hand[i + 1].getFace() && hand[i].getFace() == hand[i + 2].getFace()) {
	temp1 = i;
	temp2 = i + 1;
	temp3 = i + 2;
      }
    for(int i = 4; i >= 0; i--)
      if(i != temp1 && i != temp2 && i != temp3) {
	hand.erase(hand.begin() + i);
      }
    hand.push_back(d1.drawCard());
    hand.push_back(d1.drawCard());
    break;
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    break;
  }
}
