// Dominion Card Class File
// Ian Cramer
// 9/6/18
//



// Header Section
#pragma once

#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
// End Header Section



// -------------------- Card Abstract Parent Class Signature --------------------
class Card
{
public:
  enum Type {Action, Reaction, Attack, Treasure, Victory};
  // enum specificType {Cellar, Chapel, Moat, Chancellor, Harbinger, Merchant, Village, Woodcutter, Workshop, Vassal, Bureaucrat, Feast, Gardens, Militia, Moneylender, Poacher, Remodel, Smithy, Spy, Thief, Throne Room, Bandit, Council Room, Festival, Laboratory, Library, Market, Mine, Sentry, Witch, Adventurer, Artisan, Copper, Silver, Gold, Estate, Duchy, Province, Curse}
  
  // Constructor
  Card()
  {
      numCards++;
      //cout << "Card Made  --  " << numCards << " Cards." << endl;
  }
  
  // Destructor
  virtual ~Card()
  {
      numCards--;
      //cout << "Card Destroyed  --  " << numCards << " Cards." << endl;
  }
  
  // Complex Action Helpers
  virtual void complexAction() {}
  virtual void complexAction(bool b) {}
  virtual void complexAction(int x) {}
  virtual void complexAction(char c) {}
  virtual void complexAction(string s) {}
  
  // Accessors
  virtual string getCardName() {return cardName;}
  virtual Type getType() {return type;}
  virtual string getTypeStr() {return typeStr;}
  virtual int getCost() {return cost;}
  virtual int getValue() {return value;}
  virtual int getVictoryPoints() {return victoryPoints;}
  virtual int getBonusMoney() {return bonusMoney;}
  virtual int getBonusActions() {return bonusActions;}
  virtual int getBonusBuys() {return bonusBuys;}
  virtual int getBonusCards() {return bonusCards;}
  virtual string getInfo() {return info;}
  virtual int getId() {return cardId;}
  bool getStartCard() {return startCard;}
  
  // Mutators
  void setStartCard(bool b) {startCard = b;}
  
protected:
  
  string cardName = "";
  Type type;
  string typeStr;
  int cost = 0;
  int value = 0;
  int victoryPoints = 0;
  int bonusActions = 0;
  int bonusBuys = 0;
  int bonusCards = 0;
  int bonusMoney = 0;
  
  string info = "";
  
  int cardId = 0;
  bool startCard = false;
  
  static int numCards;
};
int Card::numCards = 0;

// -------------------- End Card Parent Class Signature --------------------



// -------------------- Specific Card Child Class Signatures --------------------

// ---------- Victory Card Child Class Signatures ----------

// Estate
class Estate : public Card
{
public:
  // Constructor
  Estate()
  {
    Card::cardName = "Estate";
    Card::type = Victory;
    Card::typeStr = "Victory";
    Card::cost = 2;
    Card::victoryPoints = 1;
    Card::info = "A victory card worth 1 victory point.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Estate()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Estate::num = 0;

// Duchy
class Duchy : public Card
{
public:
  // Constructor
  Duchy()
  {
    Card::cardName = "Duchy";
    Card::type = Victory;
    Card::typeStr = "Victory";
    Card::cost = 5;
    Card::victoryPoints = 3;
    Card::info = "A victory card worth 3 victory points.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Duchy()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Duchy::num = 0;

// Province
class Province : public Card
{
public:
  // Constructor
  Province()
  {
    Card::cardName = "Province";
    Card::type = Victory;
    Card::typeStr = "Victory";
    Card::cost = 8;
    Card::victoryPoints = 6;
    Card::info = "A victory card worth 6 victory points. When this deck is empty, the game is over.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Province()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Province::num = 0;

// Gardens
class Gardens : public Card
{
public:
  // Constructor
  Gardens()
  {
    Card::cardName = "Gardens";
    Card::type = Victory;
    Card::typeStr = "Victory";
    Card::cost = 8;
    Card::victoryPoints = 6;
    Card::info = "A victory card worth 1 victory point per 10 cards you have (Round Down).";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Gardens()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Gardens::num = 0;

// Curse
class Curse : public Card
{
public:
  // Constructor
  Curse()
  {
    Card::cardName = "Curse";
    Card::type = Victory;
    Card::typeStr = "Victory";
    Card::cost = 0;
    Card::victoryPoints = -1;
    Card::info = "A victory card worth -1 victory points. When a witch is played, each other player gains a curse.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Curse()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Curse::num = 0;

// ---------- End Victory Card Child Class Signatures ----------


// ---------- Treasure Card Child Class Signatures ----------

// Copper
class Copper : public Card
{
public:
  // Constructor
  Copper()
  {
    Card::cardName = "Copper";
    Card::type = Treasure;
    Card::typeStr = "Treasure";
    Card::cost = 0;
    Card::value = 1;
    Card::info = "A treasure card worth 1 money.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Copper()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Copper::num = 0;

// Silver
class Silver : public Card
{
public:
  // Constructor
  Silver()
  {
    Card::cardName = "Silver";
    Card::type = Treasure;
    Card::typeStr = "Treasure";
    Card::cost = 3;
    Card::value = 2;
    Card::info = "A treasure card worth 2 money.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Silver()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Silver::num = 0;

// Gold
class Gold : public Card
{
public:
  // Constructor
  Gold()
  {
    Card::cardName = "Gold";
    Card::type = Treasure;
    Card::typeStr = "Treasure";
    Card::cost = 6;
    Card::value = 3;
    Card::info = "A treasure card worth 3 money.";
    //Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Gold()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Gold::num = 0;

// ---------- End Treasure Card Child Class Signatures ----------


// ---------- Action Card Child Class Signatures ----------

// Cellar
class Cellar : public Card
{
public:
  // Constructor
  Cellar()
  {
    Card::cardName = "Cellar";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 2;
    Card::bonusActions = 1;
    Card::info = "An action card: +1 Action. Discard any number of cards, then draw that many.";
    Card::cardId = 1;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Cellar()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Cellar::num = 0;

// Chapel
class Chapel : public Card
{
public:
  // Constructor
  Chapel()
  {
    Card::cardName = "Chapel";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 2;
    Card::info = "Trash up to 4 cards from your hand.";
    Card::cardId = 2;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Chapel()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Chapel::num = 0;

// Moat
class Moat : public Card
{
public:
  // Constructor
  Moat()
  {
    Card::cardName = "Moat";
    Card::type = Reaction;
    Card::typeStr = "Action";
    Card::cost = 2;
    Card::bonusCards = 2;
    Card::info = "An action card: +2 Cards. When another player plays an Attack card, you may first reveal this from your hand. If you do, you are unaffected by that Attack.";
    Card::cardId = 3;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Moat()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Moat::num = 0;

// Harbinger
class Harbinger : public Card
{
public:
  // Constructor
  Harbinger()
  {
    Card::cardName = "Harbinger";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 3;
    Card::bonusCards = 1;
    Card::bonusActions = 1;
    Card::info = "An action card: +1 Card, +1 Action. Look through your discard pile. You may put a card from it onto your deck.";
    Card::cardId = 4;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Harbinger()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Harbinger::num = 0;

// Merchant
class Merchant : public Card
{
public:
  // Constructor
  Merchant()
  {
    Card::cardName = "Merchant";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 3;
    Card::bonusCards = 1;
    Card::bonusActions = 1;
    Card::bonusMoney = 0;
    Card::info = "An action card: +1 Card, +1 Action. The first time you play a silver this turn +1 Money.";
    Card::cardId = 5;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Merchant()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
  void complexAction(bool hasSilver) {if (hasSilver) bonusMoney = 1;}
  
private:
   static int num;
};
int Merchant::num = 0;

// Vassal
class Vassal : public Card
{
public:
  // Constructor
  Vassal()
  {
    Card::cardName = "Vassal";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 3;
    Card::bonusMoney = 2;
    Card::info = "An action card: +2 Money. Discard the top card of your deck. If it is an action card you may play it.";
    Card::cardId = 6;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Vassal()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Vassal::num = 0;

// Village
class Village : public Card
{
public:
  // Constructor
  Village()
  {
    Card::cardName = "Village";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 3;
    Card::bonusCards = 1;
    Card::bonusActions = 2;
    Card::info = "An action card: +1 Card, +2 Actions";
    Card::cardId = 7;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Village()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Village::num = 0;

// Woodcutter -- Removed
class Woodcutter : public Card
{
public:
  // Constructor
  Woodcutter()
  {
    Card::cardName = "Woodcutter";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 3;
    Card::bonusMoney = 2;
    Card::bonusBuys = 1;
    Card::info = "An action card: +1 Buy, +2 Money.";
    Card::cardId = -1; // Card Removed From Game
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Woodcutter()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Woodcutter::num = 0;


// Workshop
class Workshop : public Card
{
public:
  // Constructor
  Workshop()
  {
    Card::cardName = "Workshop";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 3;
    Card::info = "An action card: Gain a card costing up to 4 money.";
    Card::cardId = 8;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Workshop()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Workshop::num = 0;

// Bureaucrat
class Bureaucrat : public Card
{
public:
  // Constructor
  Bureaucrat()
  {
    Card::cardName = "Bureaucrat";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::info = "Gain a Silver onto your deck. Each other player reveals a Victory card from their hand and puts it onto their deck (or reveals a hand with no Victory cards).";
    Card::cardId = 9;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Bureaucrat()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Bureaucrat::num = 0;

// Militia
class Militia : public Card
{
public:
  // Constructor
  Militia()
  {
    Card::cardName = "Militia";
    Card::type = Attack;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::bonusMoney = 2;
    Card::info = "An action card: +2 Money. Each other player discards down to 3 cards in hand.";
    Card::cardId = 11;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Militia()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Militia::num = 0;

// Moneylender
class Moneylender : public Card
{
public:
   // Constructor
   Moneylender()
   {
      Card::cardName = "Moneylender";
      Card::type = Action;
      Card::typeStr = "Action";
      Card::cost = 4;
      Card::bonusMoney = 0;
      Card::info = "You may trash a Copper from your hand for +3 Money.";
      Card::cardId = 12;
      num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
   }
   ~Moneylender()
   {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
   }

   void complexAction(bool trashedCopper) {if (trashedCopper) bonusMoney = 3;}
   
private:
   static int num;
};
int Moneylender::num = 0;

// Poacher
class Poacher: public Card
{
public:
  // Constructor
  Poacher()
  {
    Card::cardName = "Poacher";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::bonusCards = 1;
    Card::bonusActions = 1;
    Card::bonusMoney = 1;
    Card::info = "+1 Card, +1 Action, +1 Money. Discard a card per empty supply pile.";
    Card::cardId = 13;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Poacher()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Poacher::num = 0;

// Remodel
class Remodel : public Card
{
public:
  // Constructor
  Remodel()
  {
    Card::cardName = "Remodel";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::info = "An action card: Trash a card from your hand. Gain a card costing up to 2 Money more than the trashed card.";
    Card::cardId = 14;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Remodel()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Remodel::num = 0;

// Smithy
class Smithy : public Card
{
public:
  // Constructor
  Smithy()
  {
    Card::cardName = "Smithy";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::bonusCards = 3;
    Card::info = "An action card: +3 Cards.";
    Card::cardId = 15;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Smithy()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Smithy::num = 0;

// Throne Room
class ThroneRoom : public Card
{
public:
  // Constructor
  ThroneRoom()
  {
    Card::cardName = "Throne Room";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::info = "You may play an action card from your hand twice.";
    Card::cardId = 16;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~ThroneRoom()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int ThroneRoom::num = 0;

// Bandit
class Bandit : public Card
{
public:
  // Constructor
  Bandit()
  {
    Card::cardName = "Bandit";
    Card::type = Attack;
    Card::typeStr = "Action";
    Card::cost = 4;
    Card::info = "Gain a Gold. Each other player reveals the top two cards of their deck, trashes a revealed treasure card other than a copper, and discards the rest.";
    Card::cardId = 17;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Bandit()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Bandit::num = 0;

// Council Room
class CouncilRoom : public Card
{
public:
  // Constructor
  CouncilRoom()
  {
    Card::cardName = "Council Room";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::bonusCards = 4;
    Card::bonusBuys = 1;
    Card::info = "An action card: +4 Cards, +1 Buy. Each other player draws one card.";
    Card::cardId = 18;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~CouncilRoom()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int CouncilRoom::num = 0;

// Festival
class Festival : public Card
{
public:
  // Constructor
  Festival()
  {
    Card::cardName = "Festival";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::bonusActions = 2;
    Card::bonusBuys = 1;
    Card::bonusMoney = 2;
    Card::info = "An action card: +2 Actions, +1 Buy, +2 Money.";
    Card::cardId = 19;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Festival()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Festival::num = 0;

// Laboratory
class Laboratory : public Card
{
public:
  // Constructor
  Laboratory()
  {
    Card::cardName = "Laboratory";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::bonusActions = 1;
    Card::bonusCards = 2;
    Card::info = "An action card: +2 Cards, +1 Actions.";
    Card::cardId = 20;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Laboratory()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Laboratory::num = 0;

// Library
class Library : public Card
{
public:
  // Constructor
  Library()
  {
    Card::cardName = "Library";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::info = "An action card: Draw until you have 7 cards in hand, skipping any action cards you choose to; they will then be discarded.";
    Card::cardId = 21;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Library()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Library::num = 0;

// Market
class Market : public Card
{
public:
  // Constructor
  Market()
  {
    Card::cardName = "Market";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::bonusMoney = 1;
    Card::bonusCards = 1;
    Card::bonusActions = 1;
    Card::bonusBuys = 1;
    Card::info = "An action card: +1 Card, +1 Action, +1 Buy, +1 Money.";
    Card::cardId = 22;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Market()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Market::num = 0;

// Mine
class Mine : public Card
{
public:
  // Constructor
  Mine()
  {
    Card::cardName = "Mine";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::info = "An action card: Trash a Treasure card from your hand. Gain a Treasure card to your hand costing up to $3 more.";
    Card::cardId = 23;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Mine()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Mine::num = 0;

// Sentry
class Sentry : public Card
{
public:
  // Constructor
  Sentry()
  {
    Card::cardName = "Sentry";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::bonusCards = 1;
    Card::bonusActions = 1;
    Card::info = "An action card: +1 Card, +1 Action. Look at the top 2 cards of your deck. Trash and/or discard any number of them. Put the rest back on top in any order.";
    Card::cardId = 24;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Sentry()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Sentry::num = 0;

// Witch
class Witch : public Card
{
public:
  // Constructor
  Witch()
  {
    Card::cardName = "Witch";
    Card::type = Attack;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::bonusCards = 2;
    Card::info = "An action card: +2 Cards. Each other player gains a curse.";
    Card::cardId = 25;
    num++;
  	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Witch()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Witch::num = 0;

// Witch
class Artisan : public Card
{
public:
  // Constructor
  Artisan()
  {
    Card::cardName = "Artisan";
    Card::type = Action;
    Card::typeStr = "Action";
    Card::cost = 5;
    Card::info = "An action card: Gain a card costing up to 5 Money to your hand. Place a card from your hand onto your deck.";
    Card::cardId = 26;
    num++;
 	 //cout << cardName << " Made  --  " << num << " " << cardName << "s." << endl;
  }
  ~Artisan()
  {
      num--;
      //cout << cardName << " Destroyed  --  " << num << " " << cardName << "s." << endl;
  }
  
private:
   static int num;
};
int Artisan::num = 0;





// ---------- End Action Card Child Class Signatures ----------


#endif