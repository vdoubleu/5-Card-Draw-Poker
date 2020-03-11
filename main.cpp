#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Dealer.h"

int main() {
  Deck deck;
  Deck* deck_ptr = &deck;
  deck.shuffle();
  
  Card* playerHand;
  Card* dealerHand;
  
  playerHand = Dealer::dealHand(deck_ptr);
  dealerHand = Dealer::dealHand(deck_ptr);

  std::cout << "Welcome to 5 card draw" << endl;
  std::cout << "You will be playing against the computer" << endl;
  
  std::cout << "-----------------------------------------" << endl;

  std::cout << "Your hand" << endl;
  Dealer::showHand(playerHand);
  
  Dealer::swapCards(playerHand, deck_ptr);
  
  std::cout << "Your new hand" << endl;
  Dealer::showHand(playerHand);
  
  std::cout << endl << "The CPU's hand" << endl;
  Dealer::showHand(dealerHand);

  Dealer::dealerSwapCards(dealerHand, deck_ptr);
  
  std::cout << endl;
  
  std::cout << "The CPU has decided which cards to swap" << endl;
  
  std::cout << endl << "The CPU's new hand" << endl;
  Dealer::showHand(dealerHand);
  
  std::cout << endl;
  switch(Dealer::compareHands(Dealer::determineHandSize(playerHand), Dealer::determineHandSize(dealerHand))){
    case 1: cout << "<you win, your hand was better>";
    break;
    case -1: cout << "<you lose, your hand was worse>";
    break;
    case 0: cout << "<it's a tie, nobodies hand was better>";
    break;
  }

  return 0;
}