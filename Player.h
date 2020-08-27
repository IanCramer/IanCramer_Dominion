// Dominion Player Class File
// Ian Cramer
// 9/6/18
//

#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__


#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Card.h"
#include "Kingdom.h"

using namespace std;

class Player
{
// ---------- Static Seciton ----------
public:
  // Public Static Member Variables
  
  // Public Static Functions
  
  
  // End Public Static
  
private:
  // Private Static Members
  static int count;
  // Private Static Methods
  
// ---------- End Static Section ---------

public:
  // ----- Member Methods -----
  // Constructor
  Player(const string &theName);
  
  // Destructor
  ~Player();
  
  // ----- Game Functions -----
  // Turn Set Up
  void turnSetUp();
  void win() {winner = true;}
  
  // Cards
  void lookAtCards(vector<Card*> &cards);
  void lookAtHand();
  
  // --- Activities ---
  // Cards
  void resetHand();
  Card* draw(int number = 1);
  bool discard(const string &theCard, int cardSet = 2);
  void discard(vector<Card*> &cardSet, Card *theCard);
  void gain(Card *theCard);
  vector<Card*>& revealDeck(int num = 1);
  bool trash(const string &theCard, int cardSet = 2);
  void trash(vector<Card*> &cardSet, Card *theCard);
  Card* findCard(const string &theCard, vector<Card*> &cardSet);
  // Actions
  void addActions(int number = 1) {currActions += number;}
  bool playAction(Card *theCard);
  void skipActions() {currActions = 0;}
  vector<Card*> findActions();
  bool defense();
  // Buys
  void addBuys(int number = 1) {currBuys += number;}
  void useBuy(int amount) {currBuys -= 1; currMoney -= amount; spent += amount;}
  void skipBuys() {currBuys = 0;}
  vector<Card*> findTreasure();
  
  // Accessors
  string getName() {return name;}
  int getId() { return id; }
  int actionsRemaining() { return currActions; }
  int buysRemaining() { return currBuys; }
  int moneyRemaining() { return currMoney; }
  int getPoints() { return victoryPoints; }
  int handSize() { return hand.size(); }
  vector<Card*>& getCards(int cardSet = 0);
  vector<Card*> findVictory();
  
  // Mutators
  void addMoney(int amount = 1) {currMoney+=amount;}
  
  
  
private:
  // ----- Helper Methods -----
  // Player Constructor Helper Methods
  void cardStart();
  void rig();
  
  // Player Destructor Helper Methods
  int destroy(vector<Card*> &cardSet);
  
  // Internal Player Methods
  void calculateMoney();
  bool resetDeck();
  void shuffle(vector<Card*> &cards);
  
  
  // ----- Member Variables -----
  // Player Info
  string name;
  int id;
  bool winner = false;
  
  int victoryPoints = 3;
  int currActions = 0;
  int currBuys = 0;
  int currMoney = 0;
  int spent = 0;
  
  // Cards
  vector<Card*> hand = {};
  vector<Card*> deck = {};
  vector<Card*> discardPile = {};
  vector<Card*> inPlay = {};
  vector<Card*> revealed = {};
  vector<Card*>::iterator cardIter;
};
// ----- Static Initialization -----
int Player::count = 0;


// ---------- Constructor & Constructor Helpers ----------
Player::Player(const string &theName)
{
  count++;
  name = theName;
  id = count;
  
  cardStart();
}


// Destructor
Player::~Player()
{
   int x = 0;
   x += destroy(deck);
   if (x < 10)
      x += destroy(discardPile);
   if (x < 10)
      x += destroy(hand);
   if (x < 10)
      x += destroy(inPlay);
   if (x < 10)
      x += destroy(revealed);
}
// Destroy (Destructor Helper)
int Player::destroy(vector<Card*> &cardSet)
{
   int y = 0;
   int x = cardSet.size();
   Card* toDel;
   for (int i = 0; i < x; i++)
   {
      if (!cardSet[i]->getStartCard())
         continue;
      toDel = cardSet[i];
      delete toDel;
      cardSet[i] = nullptr;
      y++;
   }
   return y;
}


// Card Start (Constructor Helper)
void Player::cardStart()
{
   Card *newCard;
  
   if (name == "Ian Cramer")
      return rig();
  
   for (int i = 0; i < 3; i++)
   {
      newCard = new Estate;
      newCard->setStartCard(true);
      deck.push_back(newCard);
   }
   for (int i = 0; i < 7; i++)
   {
      newCard = new Copper;
      newCard->setStartCard(true);
      deck.push_back(newCard);
   }
  shuffle(deck);
  
  draw(5);
}
// Rig the card start for me :)
void Player::rig()
{
   Card *newCard;
   // Give me Gold
   for (int i = 0; i < 7; i++)
   {
      newCard = new Gold;
      newCard->setStartCard(true);
      deck.push_back(newCard);
   }
   // Give Me Points
   newCard = new Province;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   // Give me Actions, buys, and money
   newCard = new Festival;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   // Give me Cards
   newCard = new CouncilRoom;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   // Give me Offense
   newCard = new Bandit;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   newCard = new Witch;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   // Give me Defense
   newCard = new Moat;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   // Give me OP
   newCard = new Artisan;
   newCard->setStartCard(true);
   deck.push_back(newCard);
   
   // Done Making Rigged Deck, Shuffle and Draw
   shuffle(deck);
   draw(5);
}


// ---------- End Constructor & Constructor Helpers ----------



// Turn Set Up
void Player::turnSetUp()
{
  currActions = 1;
  currBuys = 1;
  currMoney = 0;
  spent = 0;
  calculateMoney();
  if (findActions().size() == 0)
    currActions = 0;
  
  lookAtHand();
}

void Player::gain(Card *theCard)
{
  discardPile.push_back(theCard);
  victoryPoints += theCard->getVictoryPoints();
  cout << name << " got a " << theCard->getCardName() << "." << endl << endl;
}

// Calculate Money
void Player::calculateMoney()
{
  currMoney = 0;
  for (cardIter = hand.begin(); cardIter != hand.end(); cardIter++)
    currMoney += (*cardIter)->getValue();
  for (cardIter = inPlay.begin(); cardIter != inPlay.end(); cardIter++)
    currMoney += (*cardIter)->getBonusMoney();
  currMoney -= spent;
}

// Reset Hand
void Player::resetHand()
{
  // Discard from Hand
  int setSize = hand.size();
  for (int i = 0; i < setSize; i++)
    discardPile.push_back(hand[i]);
  for (int i = 0; i < setSize; i++)
     hand.pop_back();
  // Discard from Play
  setSize = inPlay.size();
  for (int i = 0; i < setSize; i++)
    discardPile.push_back(inPlay[i]);
  for (int i = 0; i < setSize; i++)
    inPlay.pop_back();
  // Draw 5 more
  spent = 0;
  draw(5);
}

// Draw
Card* Player::draw(int number)
{
  for (int i = 0; i < number; i++)
  {
    if (deck.size() == 0)
      if (!resetDeck())
         return NULL;
    cardIter = deck.begin();
    hand.push_back(*cardIter);
    deck.erase(cardIter);
  }
  calculateMoney();
  return hand[hand.size()-1];
}


// Discard
bool Player::discard(const string &theCard, int cardSet)
{
   switch(cardSet)
   {
      case 1:
         for (cardIter = deck.begin(); cardIter != deck.end(); cardIter++)
         {
            if ( (*cardIter)->getCardName() == theCard)
            {
               discard(deck, *cardIter);
               return true;
            }
         }
         break;
      case 2:
         for (cardIter = hand.begin(); cardIter != hand.end(); cardIter++)
         {
            if ( (*cardIter)->getCardName() == theCard)
            {
               discard(hand, *cardIter);
               return true;
            }
         }
         break;
      case 3:
      case 4:
      case 5:
         for (cardIter = revealed.begin(); cardIter != revealed.end(); cardIter++)
         {
            if ( (*cardIter)->getCardName() == theCard)
            {
               discard(revealed, *cardIter);
               return true;
            }
         }
         break;
      default:
         break;
   }
   return false;
}
void Player::discard(vector<Card*> &cardSet, Card *theCard)
{
   for (int i = 0; i < hand.size(); i++)
   {
      if ( cardSet[i] == theCard )
      {
         discardPile.push_back(theCard);
         cardSet[i] = cardSet[cardSet.size()-1];
         cardSet.pop_back();
         cout << name << " discarded a " << discardPile[discardPile.size()-1]->getCardName() << endl << endl;
         return;
      }
   }
}

// Trash Cards
bool Player::trash(const string &theCard, int cardSet)
{
   switch(cardSet)
   {
      case 1:
         for (cardIter = deck.begin(); cardIter != deck.end(); cardIter++)
         {
            if ( (*cardIter)->getCardName() == theCard)
            {
               trash(deck, *cardIter);
               return true;
            }
         }
         break;
      case 2:
         for (cardIter = hand.begin(); cardIter != hand.end(); cardIter++)
         {
            if ( (*cardIter)->getCardName() == theCard)
            {
               trash(hand, *cardIter);
               return true;
            }
         }
         break;
      case 3:
      case 4:
      case 5:
         for (cardIter = revealed.begin(); cardIter != revealed.end(); cardIter++)
         {
            if ( (*cardIter)->getCardName() == theCard)
            {
               trash(revealed, *cardIter);
               return true;
            }
         }
         break;
      default:
         break;
   }
   return false;
}
void Player::trash(vector<Card*> &cardSet, Card *theCard)
{
   cout << name << " trashed a " << theCard->getCardName() << endl << endl;
   cardSet.erase( find(cardSet.begin(), cardSet.end(), theCard) );
}

// Reset Deck
bool Player::resetDeck()
{
  if (deck.size() != 0)
    return false;
  if (discardPile.size() <= 0)
     return false;
  shuffle(discardPile);
  for (int i = 0; i < discardPile.size(); i++)
    deck.push_back(discardPile[i]);
  discardPile = {};
  return true;
}

// Shuffle Deck
void Player::shuffle(vector<Card*> &cards)
{
  srand(time(NULL));
  for (int i = 0; i < cards.size(); i++)
  {
    int r = rand()%cards.size();
    Card* tmp = cards[i];
    cards[i] = cards[r];
    cards[r] = tmp;
  }
}

// Look at Cards
void Player::lookAtCards(vector<Card*> &cards)
{
  cout << cards.size() << " cards" << endl;
  for (cardIter = cards.begin(); cardIter != cards.end(); cardIter++)
    cout << (*cardIter)->getCardName() << ", ";
  cout << endl;
}

// Look at Hand
void Player::lookAtHand()
{
  cout << setw(12) << right << name << "'s Hand: ";
  lookAtCards(hand);
  if (inPlay.size() > 0)
  {
    cout << name << "'s Cards in Play: ";
    lookAtCards(inPlay);
  }
  calculateMoney();
  cout << setw(12) << right << "Actions: " << currActions
       << setw(10) << right << "Buys: " << currBuys
       << setw(10) << right << "Money: " << currMoney
       << endl << endl;
}

// Find Actions
vector<Card*> Player::findActions()
{
  vector<Card*> actions;
  cardIter = hand.begin();
  for (cardIter; cardIter != hand.end(); cardIter++)
    if ( (*cardIter)->getType() != Card::Victory && (*cardIter)->getType() != Card::Treasure )
      actions.push_back(*cardIter);
  return actions;
}
vector<Card*> Player::findTreasure()
{
  vector<Card*> treasure;
  cardIter = hand.begin();
  for (cardIter; cardIter != hand.end(); cardIter++)
    if ((*cardIter)->getType() == Card::Treasure)
      treasure.push_back(*cardIter);
  return treasure;
}
vector<Card*> Player::findVictory()
{
  vector<Card*> victories;
  cardIter = hand.begin();
  for (cardIter; cardIter != hand.end(); cardIter++)
    if ((*cardIter)->getType() == Card::Victory)
      victories.push_back(*cardIter);
  return victories;
}

bool Player::defense()
{
  for (cardIter = hand.begin(); cardIter != hand.end(); cardIter++)
    if ( (*cardIter)->getType() == Card::Reaction )
      return true;
  return false;
}

// Play Action
bool Player::playAction(Card *theCard)
{
  inPlay.push_back(theCard);
  hand.erase( find(hand.begin(), hand.end(), theCard) );
  currActions--;
  
  draw(theCard->getBonusCards());
  calculateMoney();
  currActions += theCard->getBonusActions();
  currBuys += theCard->getBonusBuys();
   
  return true;
}

// Reveal Cards from deck
vector<Card*>& Player::revealDeck(int num)
{
  for (int i = 0; i < num; i++)
  {
    if (deck.size() == 0)
      if (!resetDeck())
         return revealed;
    cardIter = deck.begin();
    revealed.push_back(*cardIter);
  }
  return revealed;
}

vector<Card*>& Player::getCards(int cardSet)
{
   switch(cardSet)
   {
      case 1:
         return deck;
      case 2:
         return hand;
      case 3:
         return discardPile;
      case 4:
         return inPlay;
      case 5:
         return revealed;
      default:
         return hand;
   }
}

Card* Player::findCard(const string &theCard, vector<Card*> &cardSet)
{
   for (cardIter = cardSet.begin(); cardIter != cardSet.end(); cardIter++)
      if ( (*cardIter)->getCardName() == theCard )
         return (*cardIter);
   return NULL;
}

#endif