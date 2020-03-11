#include <iostream>
#include <string>
#include "Deck.h"

#ifndef DEALER_H_
#define DEALER_H_

class Dealer{
  private:
    static bool flush(Card[]);
    static bool straight(Card[]);
    static int pairValue(Card[]);
    
    static bool cardExists(Card[], int);
    static int biggestCard(Card[]);
  
  
  public:
    static Card* dealHand(Deck*);
    static void showHand(Card[]);
    
    static int determineHandSize(Card[]);
    static void swapCards(Card[], Deck*);
    static int compareHands(int, int);
    static void dealerSwapCards(Card[], Deck*);
};


#endif //DEALER_H_