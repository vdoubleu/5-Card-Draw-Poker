#include <iostream>
#include <string>
#include "Deck.h"
#include <stdlib.h>
#include <time.h>

Deck::Deck(){
  for(int face = 0, pos = 0; face < 13; face++)
    for(int suit = 0; suit < 4; suit++, pos++)
      card_arr[pos] = Card(face, suit);
}

Deck::~Deck(){
  
}

void Deck::shuffle(){
  srand(time(NULL));
  
  for(int currCard = 0; currCard < 52; currCard++)
    swap(card_arr[currCard], card_arr[rand()%52]);
}

Card Deck::dealCard(){
  currentCard++;
  return card_arr[currentCard - 1];
}

bool Deck::moreCards(){
  if(currentCard < 52)
    return true;
  else 
    return false;
}