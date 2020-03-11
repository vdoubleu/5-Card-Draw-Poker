#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

const string Card::suit_arr[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const string Card::face_arr[]= {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
 

Card::Card(){
  face = 0;
  suit = 0;
}

Card::Card(int inputFace, int inputSuit){
  face = inputFace;
  suit = inputSuit;
}

string Card::toString() const{
  return face_arr[face] + " of " + suit_arr[suit];
}