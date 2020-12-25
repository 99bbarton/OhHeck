//Implementation of Card class

#include <cstdio>

#include "card.h"


Card::Card(int val, char s, bool trump)
{
  value = val;
  suit = s;
  isTrump = trump;
}


Card::~Card(){}


/*
  @param card : The card to compare with.
  Returns true if this card's value is less than that card's value

 */
bool Card::operator<(const Card& card)
{
  if (isTrump && card.isTrump) //If both trump
    return value < card.value;
  else if (isTrump) //This card is trump
    return false;
  else if (card.isTrump) //That card is trump
    return true;
  else if (suit == card.suit) //If the cards are the same suit, value matters
    return value < card.value;
  else
    return true;
}

void Card::print()
{
  printf("(Suit = %c, Value = %d)\n", suit, value);
}
