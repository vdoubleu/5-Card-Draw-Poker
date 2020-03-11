#include <string>
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"

Card* Dealer::dealHand(Deck* deck){
  Card* hand = new Card[5];
  
  for(int currCard = 0; currCard < 5;  currCard++){
    hand[currCard] = deck->dealCard();
  }

  return hand;
}

void Dealer::showHand(Card hand[]){
  for(int currCard = 0; currCard < 5; currCard++){
    std::cout << "(" << currCard + 1 << ") " << hand[currCard].toString() << endl;
  }
  
}

int Dealer::determineHandSize(Card hand[]){
	//people who have folded have hand value of 0
  if (Dealer::flush(hand) == true && Dealer::cardExists(hand, 1) && Dealer::cardExists(hand, 13) && Dealer::cardExists(hand, 12) && Dealer::cardExists(hand, 11) && Dealer::cardExists(hand, 10)) {
		return 10;
	}
	else if (Dealer::flush(hand) == true && Dealer::straight(hand) == true) {
		return 9;
	}
	else if (Dealer::flush(hand) == true) {
		return 6;
	}
	else if (Dealer::straight(hand) == true) {
		return 5;
	} else
    return Dealer::pairValue(hand);

}

int Dealer::pairValue(Card hand[]){
	int pairAmount = 0;
	
	//sees how many matches there are
	for (int first = 0; first < 5; first++) {
		for (int sec = first + 1; sec < 5; sec++) {
			if (hand[first].face == hand[sec].face) {
				pairAmount += 1;
			}
		}
	}
	
  switch (pairAmount){
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    case 4: return 7;
    case 6: return 8;
    default: return 1;
  }
}

bool Dealer::straight(Card hand[]) {
	//sees if a player has a straight
	int compareNum =Dealer::biggestCard(hand);

	//checks if each number below that highest number exists
	for (int card = 0; card < 4; card++) {
		if (Dealer::cardExists(hand, compareNum - 1) == true)
			compareNum -= 1;
		else
			return false;
	}
	return true;

}

bool Dealer::flush(Card hand[]) {
	//checks if all cards have same suite
	for (int i = 1; i < 5; i++) {
		if (hand[0].suit != hand[i].suit)
			return false;
	}

	return true;
}

bool Dealer::cardExists(Card hand[], int cardValue){
  for(int currCard = 0; currCard < 5; currCard++){
    if(hand[currCard].face == cardValue)
      return true;
  }
  
  return false;
}

int Dealer::biggestCard(Card hand[]){
  int biggestNum = 0;
  
  for(int currCard = 0; currCard < 5; currCard++){
    if(hand[currCard].face > biggestNum)
      biggestNum = hand[currCard].face;
  }
  
  return biggestNum;
  
}

void Dealer::swapCards(Card hand[], Deck* deck){
  int swapCards[5];
	fill_n(swapCards, 5, 0);
	string userInput;
  
  std::cout << "Which cards do you want to switch? Input the numbers seperated by a space (e.g. 1 3 4)" << endl;

  getline(cin, userInput);
	
	int strLength = userInput.length();
  
	//individually extracts each number from the string
	for (int num = 0; num < (strLength + 1) / 2; num++) {
	  swapCards[num] = stoi(userInput.substr(num * 2, (num * 2) + 1));
	}
	
	//swaps the cards with the indexes inputted by the user with new cards from the deck
	for (int num = 0; num < 5; num++) {
	  if (swapCards[num] != 0) {
			hand[swapCards[num] - 1] = deck->dealCard();
		}
	}
}

int Dealer::compareHands(int handValue1, int handValue2){
  if(handValue1 > handValue2)
    return 1;
  else if(handValue1 == handValue2)
    return 0;
  else 
    return -1;
}

void Dealer::dealerSwapCards(Card hand[], Deck* deck){
  int pairAmount = 0;
	bool swapCards[5];
	
	for(int i = 0; i < 5; i++)
	  swapCards[i] = true;
	
	//sees how many matches there are
	for (int first = 0; first < 5; first++) {
		for (int sec = first + 1; sec < 5; sec++) {
			if (hand[first].face == hand[sec].face) {
        swapCards[first] = false;
        swapCards[sec] = false;
			}
		}
	}
	
	for(int card = 0; card < 5; card++){
	  if(swapCards[card] == true){
	    hand[card] = deck->dealCard();
	  }
	}
}