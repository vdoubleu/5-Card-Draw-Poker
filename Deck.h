#include <iostream>
#include <string>
#include "Card.h"

#ifndef DECK_H_
#define DECK_H_

using namespace std;

class Deck{
  private:
  const int SIZE_OF_DECK = 52;
  
  Card* card_arr = new Card[SIZE_OF_DECK];

  public:
 int currentCard = 0;
  
  Deck();
 ~Deck();
  
  void shuffle();
  Card dealCard();
  bool moreCards();
};

#endif //DECK_H_