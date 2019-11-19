//CARD.H

#ifndef Card_h

#define Card_h

#include<iostream>

#include<string>

#include<cstdlib>

#include<ctime>

#include<iomanip>

using namespace std;

//The enumerated data types

enum Suit

{

Clubs = 1,

Diamonds = 2,

Hearts = 3,

Spades = 4

};

//The Card class

class Card

{

  

private:

string description;

Suit suit;

int number;

public:

  

// default constructor

Card()

{

number = 0;

description = "";

}

  

// get function for suit

Suit getCardSuit()

{

return suit;

}

  

// set function for suit

void setCardSuit(Suit m_suit)

{

suit = m_suit;

}

  

int getCardNumber()

{

return number;

}

  

// set function for card

void setCardNumber(int m_num)

{

number = m_num;

}

  

// get function for description

string getCardDescription()

{

return description;

}

  

// set the card description

void setDescription(string m_description)

{

description = m_description;

}

  

// Overloaded operator < function

bool operator <(const Card& card2)

{

if (suit < card2.suit)

return true;

else if (suit > card2.suit)

return false;

  

else

{

if (number == 1)

return false;

  

else if (card2.number == 1)

return true;

  

else if (card2.number < number)

return true;

}

return false; // may be incorrect

}

};

#endif /* Card_h */

//DECK.H

#ifndef Deck_h

#define Deck_h

//#include <Card.h>

#include<iostream>

#include<string.h>

#include<cstdlib>

#include<ctime>

#include<iomanip>

using namespace std;

const int SIZE = 52;

Card card[52]; // card array

//Class Deck definition

class Deck

{

//private card variable

Card deckOfCards[SIZE];

  

public:

void initialize()

{

//the string to perform the description

string cardDesc;

char name[10];

int setFlag;

  

//the for loop to initialize the deck Of Cards

for (int i = 1; i <= SIZE; i++)

{

setFlag = 0;

if (i == 1 || i == 14 || i == 27 || i == 40)

{

cardDesc = "Ace";

setFlag = 1;

}

  

else if (i == 11 || i == 24 || i == 37 || i == 50)

{

cardDesc = "Jack";

setFlag = 1;

}

  

else if (i == 12 || i == 25 || i == 38 || i == 51)

{

cardDesc = "Queen";

setFlag = 1;

}

  

else if (i == 13 || i == 26 || i == 39 || i == 52)

{

cardDesc = "King";

setFlag = 1;

}

  

if(i <= 13)

{

deckOfCards[i - 1].setCardSuit(Spades);

deckOfCards[i - 1].setCardNumber(i);

  

if(setFlag == 0)

{

(deckOfCards[i - 1].getCardNumber(), name, 10);

cardDesc = ((string)name);

}

cardDesc = " of Spades";

deckOfCards[i - 1].setDescription(cardDesc);

}

  

else if (i > 13 && i <= 26)

{

deckOfCards[i - 1].setCardSuit(Hearts);

deckOfCards[i - 1].setCardNumber(i - 13);

  

if(setFlag == 0)

{

(deckOfCards[i - 1].getCardNumber(), name, 10);

cardDesc = ((string)name);

}

cardDesc = " of Hearts";

deckOfCards[i - 1].setDescription(cardDesc);

}

  

else if(i > 26 && i <= 39)

{

deckOfCards[i - 1].setCardSuit(Diamonds);

  

deckOfCards[i - 1].setCardNumber(i - 26);

  

if(setFlag == 0)

{

  

(deckOfCards[i - 1].getCardNumber(), name, 10);

  

cardDesc = ((string)name);

  

}

cardDesc = " of Diamonds";

  

deckOfCards[i - 1].setDescription(cardDesc);

}

  

else

{

deckOfCards[i - 1].setCardSuit(Clubs);

deckOfCards[i - 1].setCardNumber(i - 39);

  

if(setFlag == 0)

{

(deckOfCards[i - 1].getCardNumber(), name, 10);

cardDesc = ((string)name);

}

cardDesc = (" of Clubs");

deckOfCards[i - 1].setDescription(cardDesc);

}

}

}

void shuffle()

{

  

Card cardObj;

int numRandm;

srand(time(NULL));

  

for (int i = 0; i < SIZE; i++)

{

numRandm = rand() % 52;

  

cardObj = deckOfCards[i];

deckOfCards[i] = deckOfCards[numRandm];

deckOfCards[numRandm] = cardObj;

}

}

  

void deal()

{

Card hands[13][4];

for(int j = 0 ; j < 13; j++)

{

for(int i = 0; i < 4; i++)

{

hands[j][i] = deckOfCards[i + 4 * j];

}

  

}

sort(hands);

display(hands);

}

  

void sort(Card hands[13][4])

{

Card cardObj;

int j;

for (int itr = 0; itr < 4; itr++)

{

for(int i = 1 ; i < 13 ; i++)

{

cardObj = hands[i][itr];

j = i - 1;

while(j >= 0 && hands[j][itr] < cardObj)

{

hands[j + 1][itr] = hands[j][itr];

j--;

}

hands[j + 1][itr] = cardObj;

}

}

}

void display(Card hands[13][4])

{

Suit suit;

int number;

  

cout << endl << setw(14) << "Player 1" << setw(16) << "Player 2" << setw(16)<< "Player 3" << setw(16) << "Player 4";

cout << endl << setw(14) << "--------" << setw(16) << "--------" << setw(16)<< "--------" << setw(16) << "--------" << endl << endl;

for (int j = 0 ; j < 13 ; j++)

{

for (int i = 0 ; i < 4 ; i++)

{

suit = hands[j][i].getCardSuit();

number = hands[j][i].getCardNumber();

  

if (suit == 1)

cout << setw(10) << "Club";

  

else if (suit == 2)

cout << setw(10) << "Diamond";

  

else if (suit == 3)

cout << setw(10) << "Heart";

  

else

cout << setw(10) << "Spade";

  

if (number == 1)

cout << setw(6) << "Ace";

  

else if(number == 11)

  

cout << setw(6) << "Jack";

  

else if(number == 12)

  

cout << setw(6) << "Queen";

  

else if(number == 13)

  

cout << setw(6) << "King";

  

else

cout << setw(6) << number;

}

cout << endl;

}

}

};

#endif /* Deck_h */

// MAIN.CPP

//#include "Card.h"

//#include "Deck.h"

#include <iostream>

using namespace std;

int main()

{

Deck deckOfCards;

deckOfCards.initialize();

int choice = 1;

  

do

{

cout << "\nWhat would you like to do now?" << endl;

cout << "1) Shuffle Cards" << endl;

cout << "2) Deal Cards" << endl;

cout << "3) End Program" << endl;

cout << "Enter your selection (1, 2, or 3): ";

cin >> choice;

switch(choice)

{

  

case 1:

cout << "Shuffling cards" << endl;

deckOfCards.shuffle();

cout << "Cards are now shuffled" << endl;

break;

  

case 2:

cout << "Dealing cards" << endl;

deckOfCards.deal();

cout << "Cards are now dealt" << endl;

break;

  

case 3:

cout<<"Ending the program" << endl;

exit(0);

break;

  

default:

cout << "Please try again and enter a number from the menu!";

}

} while (choice != 3);

}



