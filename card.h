//Card class header


class Card{
 public:
  int value;
  char suit; 
  bool isTrump;

  Card(int val, char s, bool t); //Value, suit, trump or not
  ~Card();
  bool operator<(const Card& card) const; //Returns true if this would lose to that card 
  void print();
};
