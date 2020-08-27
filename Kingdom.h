// Kingdom Class File
// Ian Cramer
// 9/6/18
//


// Header Section
#pragma once

#ifndef __KINGDOM_H__
#define __KINGDOM_H__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

#include "Card.h"

using namespace std;
// End Header Section



class Kingdom
{
// -------------------- Static --------------------
public:
  // ---------- Public Static ----------
  
  // ----- Public Static Member Variables -----
  static vector< vector<Card*> > fullDeck;
  static bool fullDeckMade;
  static const int DECKSIZE = 11;
  // ----- End Public Static Member Variables -----
  
  // ----- Public Static Functions -----
  static void makeFullDeck();
  // ----- Public Static Functions -----
  
  // ---------- End Public Static ----------
  
private:
  // ---------- Private Static ----------
  
  // ----- Private Static Members -----
  // ----- End Private Static Members -----
  
  // ----- Private Static Methods -----
  // --- Deck Building Helpers ---
  // Victory Cards
  static vector<Card*> makeEstates();
  static vector<Card*> makeDuchys();
  static vector<Card*> makeProvinces();
  static vector<Card*> makeGardens();
  static vector<Card*> makeCurses();
  // Treasures
  static vector<Card*> makeCoppers();
  static vector<Card*> makeSilvers();
  static vector<Card*> makeGolds();
  // Actions
  static vector<Card*> makeCellars();
  static vector<Card*> makeChapels();
  static vector<Card*> makeMoats();
  static vector<Card*> makeHarbingers();
  static vector<Card*> makeMerchants();
  static vector<Card*> makeVassals();
  static vector<Card*> makeVillages();
  static vector<Card*> makeWoodcutters();
  static vector<Card*> makeWorkshops();
  static vector<Card*> makeBureaucrats();
  static vector<Card*> makeMilitia();
  static vector<Card*> makeMoneylender();
  static vector<Card*> makePoachers();
  static vector<Card*> makeRemodels();
  static vector<Card*> makeSmithy();
  static vector<Card*> makeThroneRoom();
  static vector<Card*> makeBandits();
  static vector<Card*> makeCouncilRooms();
  static vector<Card*> makeFestivals();
  static vector<Card*> makeLaboratory();
  static vector<Card*> makeLibrary();
  static vector<Card*> makeMarkets();
  static vector<Card*> makeMines();
  static vector<Card*> makeSentry();
  static vector<Card*> makeWitches();
  static vector<Card*> makeArtisans();
  // ----- End Private Static Methods -----
  
// -------------------- End Static --------------------
  
public:
  // Constructor
  Kingdom();
  
  // Destructor
  ~Kingdom();
  
  // Show Kingdom
  void showKingdom();
  
  // Valid Card
  bool validCard(const string &cardName);
  bool fullValidCard(const string &cardName);
  // Find Card
  Card* findCard(const string &cardName);
  // Give Card
  Card* giveCard(const string &cardName);
  // Provinces Remaining (For determining game over)
  int provincesRemaining() {return provRemain;}
  // Card Remaining
  int numRemain(Card *theCard);
  int numRemain(vector<Card*> theCards) {return (theCards.size() - 1);}
  int emptySupplyPiles();
  
private:
  // Methods
  // Constructor Helpers
  void makeKingdom();
  
  
  
  // Variables
  vector< vector<Card*> > mDeck;
  bool mDeckMade = false;
  bool random = false;
  int provRemain = 12;
  
  // Iterators
  vector<Card*>::iterator cardIter;
  vector< vector<Card*> >::iterator deckIter;
   
};
// Static Variable Initialization
bool Kingdom::fullDeckMade = false;
vector< vector<Card*> > Kingdom::fullDeck = {};

// Static Method Definitions
// Making The Deck
vector<Card*> Kingdom::makeEstates()
{
  vector<Card*> cards;
  for (int i = 0; i < 25; i++)
  {
    Card *newCard = new Estate;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeDuchys()
{
  vector<Card*> cards;
  for (int i = 0; i < 13; i++)
  {
    Card *newCard = new Duchy;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeProvinces()
{
  vector<Card*> cards;
  for (int i = 0; i < 13; i++)
  {
    Card *newCard = new Province;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeGardens()
{
  vector<Card*> cards;
  for (int i = 0; i < 13; i++)
  {
    Card *newCard = new Gardens;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeCurses()
{
  vector<Card*> cards;
  for (int i = 0; i < 31; i++)
  {
    Card *newCard = new Curse;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeCoppers()
{
  vector<Card*> cards;
  for (int i = 0; i < 61; i++)
  {
    Card *newCard = new Copper;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeSilvers()
{
  vector<Card*> cards;
  for (int i = 0; i < 41; i++)
  {
    Card *newCard = new Silver;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeGolds()
{
  vector<Card*> cards;
  for (int i = 0; i < 31; i++)
  {
    Card *newCard = new Gold;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeCellars()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Cellar;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeChapels()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Chapel;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeMoats()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Moat;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeHarbingers()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Harbinger;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeMerchants()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Merchant;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeVassals()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Vassal;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeVillages()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Village;
    cards.push_back(newCard);
  }
  return cards;
}

/* Removed
vector<Card*> Kingdom::makeWoodcutters()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Woodcutter;
    cards.push_back(newCard);
  }
  return cards;
}
*/

vector<Card*> Kingdom::makeWorkshops()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Workshop;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeBureaucrats()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Bureaucrat;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeMilitia()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Militia;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeMoneylender()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Moneylender;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makePoachers()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Poacher;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeRemodels()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Remodel;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeSmithy()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Smithy;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeThroneRoom()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new ThroneRoom;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeBandits()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Bandit;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeCouncilRooms()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new CouncilRoom;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeFestivals()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Festival;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeLaboratory()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Laboratory;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeLibrary()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Library;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeMarkets()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Market;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeMines()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Mine;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeSentry()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Sentry;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeWitches()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Witch;
    cards.push_back(newCard);
  }
  return cards;
}

vector<Card*> Kingdom::makeArtisans()
{
  vector<Card*> cards;
  for (int i = 0; i < DECKSIZE; i++)
  {
    Card *newCard = new Artisan;
    cards.push_back(newCard);
  }
  return cards;
}

void Kingdom::makeFullDeck()
{
  if (fullDeckMade)
    return;
  
  fullDeck.push_back(makeEstates());
  fullDeck.push_back(makeDuchys());
  fullDeck.push_back(makeProvinces());
//   fullDeck.push_back(makeGardens());
  fullDeck.push_back(makeCurses());
  
  fullDeck.push_back(makeCoppers());
  fullDeck.push_back(makeSilvers());
  fullDeck.push_back(makeGolds());
   
  fullDeck.push_back(makeCellars());
  fullDeck.push_back(makeChapels());
  fullDeck.push_back(makeMoats());
  fullDeck.push_back(makeHarbingers());
  fullDeck.push_back(makeMerchants());
  fullDeck.push_back(makeVassals());
  fullDeck.push_back(makeVillages());
//  fullDeck.push_back(makeWoodcutters());
  fullDeck.push_back(makeWorkshops());
  fullDeck.push_back(makeBureaucrats());
  fullDeck.push_back(makeMilitia());
  fullDeck.push_back(makeMoneylender());
  fullDeck.push_back(makePoachers());
  fullDeck.push_back(makeRemodels());
  fullDeck.push_back(makeSmithy());
  fullDeck.push_back(makeThroneRoom());
  fullDeck.push_back(makeBandits());
  fullDeck.push_back(makeCouncilRooms());
  fullDeck.push_back(makeFestivals());
  fullDeck.push_back(makeLaboratory());
  fullDeck.push_back(makeLibrary());
  fullDeck.push_back(makeMarkets());
  fullDeck.push_back(makeMines());
  fullDeck.push_back(makeSentry());
  fullDeck.push_back(makeWitches());
  fullDeck.push_back(makeArtisans());
  
  fullDeckMade = true;
}

// End Static Definitions

// ---------- Constructor & Constructor Helpers ----------
// Constructor
Kingdom::Kingdom()
{
  makeFullDeck();
  makeKingdom();
  showKingdom();
}


// Destuctor
Kingdom::~Kingdom()
{
   Card* toDel;
   int x = fullDeck.size();
   for (int i = 0; i < x; i++)
   {
      int y = fullDeck[i].size();
      for (int j = 0; j < y; j++)
      {
         toDel = fullDeck[i][j];
         delete toDel;
         fullDeck[i][j] = nullptr;
      }
   }
}


void Kingdom::makeKingdom()
{
   srand(time(NULL));
   string in;
   
   // Add the Basic Set of Cards
   for (deckIter = fullDeck.begin(); deckIter != fullDeck.end(); deckIter++)
   {
      // All treasure and victory cards go into the game deck
      if ( (*(deckIter->begin()))->getType() == Card::Treasure ||
           (*(deckIter->begin()))->getType() == Card::Victory
         )
      {
         mDeck.push_back(*deckIter);
      }
      else
      {
         cout << "   " << (*(deckIter->begin()))->getCardName() << endl;
      }
   }
   
   // Add the desired cards
   cout << "Which Resources Would You Like to Include?" << endl;
   cout << "Enter the card you want, 1 to pick ranomly, or 0 to finish:" << endl;
   while (mDeck.size() < 17)
   {
      if (!random)
         getline(cin, in);
      else
         in = (*(fullDeck[rand()%fullDeck.size()].begin()))->getCardName();
      if (in == "0")
         break;
      if (in == "1")
         random = true;
            
      // Add Cards
      if (validCard(in))
         cout << "Already added." << endl;
      else if (!fullValidCard(in))
         cout << "Invalid Card" << endl;
      else
      {
         for (deckIter = fullDeck.begin(); deckIter != fullDeck.end(); deckIter++)
            if ( (*(deckIter->begin()))->getCardName() == in )
            {
               mDeck.push_back(*deckIter);
               cout << in << " was added." << endl;
               break;
            }
      }
      cout << endl;
   }
   // Done Adding Cards
   mDeckMade = true;
   cout << endl;
} 

// Show Kingdom
void Kingdom::showKingdom()
{
  cout << endl;
  cout << setw(60) << right << "The Kingdom Contains:" << endl;
  
  if (mDeckMade)
  {
    
    cout << setw(16) << left << " Card"
         << setw(11) << left << "Type"
         << setw(8) << left << "Cost"
         << setw(8) << left << "Value"
         << setw(9) << left << "Points"
         << setw(8) << left << "+Money"
         << setw(11) << left << "+Actions"
         << setw(8) << left << "+Buys"
         << setw(10) << left << "+Cards"
         << setw(0) << left << "Remaining"
         << endl;
    
    for (deckIter = mDeck.begin(); deckIter != mDeck.end(); deckIter++)
    {
      cout << setw(15) << left << (*(deckIter->begin()))->getCardName()
           << setw(13) << left << (*(deckIter->begin()))->getTypeStr()
           << setw(9) << left << (*(deckIter->begin()))->getCost()
           << setw(9) << left << (*(deckIter->begin()))->getValue()
           << setw(9) << left << (*(deckIter->begin()))->getVictoryPoints()
           << setw(8) << left << (*(deckIter->begin()))->getBonusMoney()
           << setw(10) << left << (*(deckIter->begin()))->getBonusActions()
           << setw(8) << left << (*(deckIter->begin()))->getBonusBuys()
           << setw(11) << left << (*(deckIter->begin()))->getBonusCards()
           << setw(0) << left << numRemain(*deckIter) << endl;
    }
  }
  cout << endl;
}

// Valid Card
bool Kingdom::validCard(const string &cardName)
{
  for (deckIter = mDeck.begin(); deckIter != mDeck.end(); deckIter++)
    if ( (*(deckIter->begin()))->getCardName() == cardName )
      return true;
  return false;
}
bool Kingdom::fullValidCard(const string &cardName)
{
  for (deckIter = fullDeck.begin(); deckIter != fullDeck.end(); deckIter++)
    if ( (*(deckIter->begin()))->getCardName() == cardName )
      return true;
  return false;
}

// Find Card
Card* Kingdom::findCard(const string &cardName)
{
  for (deckIter = mDeck.begin(); deckIter != mDeck.end(); deckIter++)
  {
    cardIter = deckIter->begin();
    if (cardName == (*cardIter)->getCardName())
      return *cardIter;
  }
  return NULL;
}

Card* Kingdom::giveCard(const string &cardName)
{
  Card* retCard = NULL;
  for (deckIter = mDeck.begin(); deckIter != mDeck.end(); deckIter++)
  {
    cardIter = deckIter->begin();
    if (cardName == (*cardIter)->getCardName())
    {
      retCard = *cardIter;
      break;
    }
  }
  
  if (retCard->getCardName() == "Province")
    provRemain--;
  
  deckIter->erase(cardIter);
  return retCard;
}

int Kingdom::numRemain(Card *theCard)
{
  for (deckIter = mDeck.begin(); deckIter != mDeck.end(); deckIter++)
    if ( (*(deckIter->begin()))->getCardName() == theCard->getCardName() )
      return ( (*deckIter).size() - 1 );
  return 0;
}

int Kingdom::emptySupplyPiles()
{
   int emptySupplyPiles = 0;
   for (deckIter = mDeck.begin(); deckIter != mDeck.end(); deckIter++)
      if ( numRemain(*(deckIter->begin())) == 0 )
         emptySupplyPiles++;
   
   return emptySupplyPiles;
}

#endif



