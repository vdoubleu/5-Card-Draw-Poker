#include <iostream>
#include <string>

#ifndef CARD_H_
#define CARD_H_

using namespace std;

class Card{
  private:
  static const string suit_arr[];
  static const string face_arr[];
  
  public:
  int face;
  int suit;
  
  Card(int, int);
  Card();
  string toString() const;


};



#endif //CARD_H_