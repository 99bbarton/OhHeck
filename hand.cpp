//Implementation of the hand class

#include <cstdio>
#include <iostream>
#include <cstdlib>

#include "hand.h"

using namespace std;

Hand::Hand(bool isDealer)
{
  this.isDealer = isDealer;
  nWon = 0;
  cards = new vector<Card>();
  nCards = 0;
}

Hand::Hand(bool isDealer, in nCards)
{
  this.isDealer = isDealer;
  nWon = 0;
  cards = new vector<Card>();
  cards->reserve(nCards);
}

Hand::~Hand()
{
  delete cards;
}

void Hand::add(Card card)
{
  cards->push_back(card);
  nCards++;
}

void Hand::bid(int nBid)
{
  this.nBid = nBid;
}  

bool Hand::isValidPlay(char ledSuit, int cardNum)
{
  if (startSuit == 0) //If this is the first play of the round, any play is valid
    return true;

  if (startSuit == cards->at(cardNum).suit) //If following suit, valid
    return true;

  bool hasLedSuit = false;
  for (int i = 0; i < cards->size(); i++)
    {
      if (cards->at(i).suit == startSuit)
	hasLedSuit = true;
    }

  return !hasLedSuit; //If have the suit that was led, must play a card of that suit
}

Card Hand::play(int cardNum)
{
  Card card = cards->at(cardNum); 
  cards->erase(cards->begin() + cardNum);
  nCards--;
  
  return card;
}

void Hand::won(bool trickWon)
{
  if (trickWon)
    nWon++;
}

int Hand::calcScore()
{
  if (nBid == nWon)
    return nBid + 5;
  else
    return nWon;
}


void Hand::print()
{
  cout << "Tricks Bid For = " << nBid << "\t:\tTricks Won = " << nWon << endl;
  cout << "Cards left in hand:" << endl;
  for (int i = 0; i < cards->size(); i++)
    cards->at(i).print();
  cout <<"\n" << endl;
}
