//Outline of hand class representing a hand of a player

#include <vector>

#include "card.h"

class Hand
{
 public:
  int nBid; //Tricks bid
  int nWon; //Tricks won
  bool isDealer;
  int nCards; //Number fo cards in the hand

  Hand(bool isDealer);
  Hand(bool isDealer, int nCards);
  ~Hand();
  void add(Card card); //Add a new card to the hand
  void bid(int nBid);
  Card play(int cardNum); //Remove card from the hand and return a copy of it
  void won(bool trickWon);
  int calcScore();
  void print();

 private:
  vector<Card>* cards;
};
