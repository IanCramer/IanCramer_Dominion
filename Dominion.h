// Dominion Game Class File
// Ian Cramer
// 9/6/18
//



// Header Section
#pragma once

#ifndef __DOMINION_H__
#define __DOMINION_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>


#include "Player.h"
#include "Kingdom.h"

using namespace std;
// End Header Section


class Dominion
{
public:
  // ---------- Methods ----------
  // Constructor
  Dominion();
  
  // Destructor
  ~Dominion();
  
  // Turn
  void turn(Player *thePlayer);
  bool gameOver();
  
  // ---------- End Methods ----------
  
  // ---------- Members ----------
  vector<Player*> players;
  vector<Player*>::iterator currPlayer;
  
  Kingdom *myKingdom;
  vector<Card*>::iterator cardIter;
  
  
private:
  // ---------- Methods ----------
  // ----- Constructor Helpers -----
  void makePlayers();
  
  // ----- End Constructor Helpers -----
  
  // ---------- End Methods ---------
  // ----- Turn Helpers -----
  void actionPhase(Player *thePlayer);
  bool doAction(Player *thePlayer, Card *theCard);
  void buys(Player *thePlayer);
  
  Player* findWinner();
  
  // ---------- Members ----------
  
};

// ----- Constructor and Constructor Helpers -----
// Constructor
Dominion::Dominion()
{
  do
  {
    makePlayers();
    myKingdom = new Kingdom();
    currPlayer = players.begin();
    while (myKingdom->provincesRemaining() > 0 && myKingdom->emptySupplyPiles() < 3)
    {
      if (currPlayer == players.end())
        currPlayer = players.begin();
      
      turn(*currPlayer);
      currPlayer++;
    }
  }
  while ( gameOver() );
  
}

// Make Players
void Dominion::makePlayers()
{
  string in;
  cout << "How many players will be playing?" << endl;
  while (true)
  {
    getline(cin, in); cout << endl;
    if (in == "2" || in == "3" || in == "4")
      break;
    cout << "Please enter a number between 2 and 4 (inclusive): ";
  }
  int numPlayers = (int)in[0] - '0';
  
  for (int i = 1; i <= numPlayers; i++)
  {
    string playerName;
    cout << "What is player " << i << "'s name?" << endl;
    getline(cin, playerName); cout << endl;
    Player *newPlayer = new Player(playerName);
    players.push_back(newPlayer);
  }
  
}

// ----- End Constructor and Constructor Helpers -----

// Destructor
Dominion::~Dominion()
{
   int x = players.size();
   for (int i = 0; i < x; i++)
      delete players[i];
   delete myKingdom;
}

// ----- Turn and Turn Helpers -----
// Turn Function
void Dominion::turn(Player *thePlayer)
{
  bool endTurn = false;
  cout << endl;
  cout << setw(50) << right << thePlayer->getName() << "'s Turn" << endl;
  thePlayer->turnSetUp();
  
  while (true)
  {
    cout << "What would you like to do? " << endl;
    cout << "  1. Look at hand" << endl
         << "  2. Look at kingdom" << endl
         << "  3. Play Actions" << endl
         << "  4. Buy Cards" << endl
         << "  5. Get Card Info" << endl
         << "  0. End Turn" << endl;

    string in = "";
    while (!isdigit(in[0]))
    {
      cout << "Please enter the corresponding number: ";
      getline(cin, in);
    }
    cout << endl;
    int choice = (int)in[0] - '0';
    switch (choice)
    {
      case 1:
        thePlayer->lookAtHand();
        break;
      case 2:
        myKingdom->showKingdom();
        break;
      case 3:
        if (thePlayer->actionsRemaining() > 0)
          actionPhase(thePlayer);
        else
          cout << "You cannot play anymore actions." << endl;
        break;
      case 4:
        if (thePlayer->actionsRemaining() > 0)
        {
          cout << "You must complete your action phase before buying cards." << endl;
          continue;
        }
        if (thePlayer->buysRemaining() > 0)
          buys(thePlayer);
        else
          cout << "You cannot purchase anymore cards." << endl;
        break;
      case 5:
        while (true)
        {
          cout << "Which card do you want to know about?" << endl;
          getline(cin, in);
          if (myKingdom->validCard(in))
          {
            cout << ( myKingdom->findCard(in) )->getInfo() << endl;
            break;
          }
          cout << "Invalid card, please try again." << endl;
        }
        break;
      case 0:
          endTurn = true;
        break;
      default:
        continue;
    }
    cout << endl;
    if (endTurn)
      break;
  }
  cout << thePlayer->getName() << "'s Turn is Over" << endl << endl;
  thePlayer->resetHand();
  return;
}
// End Turn Function

// Action Phase
void Dominion::actionPhase(Player *thePlayer)
{
  bool acted = false;
  while (!acted)
  {
    // Find Actions
    vector<Card*> actions = thePlayer->findActions();
    // No Actions to Play
    if (actions.size() == 0)
    {
      cout << "No actions in hand. ";
      thePlayer->skipActions();
      return;
    }
    // Show Actions
    cout << "Your Actions" << endl;
    for (cardIter = actions.begin(); cardIter != actions.end(); cardIter++)
      cout << (*cardIter)->getCardName() << " -  " << (*cardIter)->getInfo() << endl;
    cout << endl;
    // Play an Action
    cout << "Which action would you like to play? Enter 0 to skip or 1 to go back." << endl;
    string in; getline(cin, in); cout << endl;
    
    if (in == "0")
      thePlayer->skipActions();
    if (in == "0" || in == "1")
      return;
    
    for (cardIter = actions.begin(); cardIter != actions.end(); cardIter++)
    {
      if (in == (*cardIter)->getCardName())
      {
        acted = doAction(thePlayer, *cardIter);
        thePlayer->lookAtHand();
        break;
      }
    }
    if (!acted)
      cout << "Invalid Response." << endl;
    
    // No Actions to Play
    if (thePlayer->findActions().size() == 0)
      thePlayer->skipActions();
  }
}
// End Action Phase

// Complex Card Acitons
bool Dominion::doAction(Player *thePlayer, Card *theCard)
{
  bool acted = false;
  string a, b, c;
  int x = -1, y, z;
  bool n, m;
  vector<Card*> tCards;
  Card* tmpCard = NULL;
  vector<Player*>::iterator playerIter;
  
  switch ( theCard->getId() )
  {
    case 1: // Cellar
        acted = thePlayer->playAction(theCard);
        while (true)
        {
           cout << "Enter number of cards to discard & draw:  ";
           getline(cin, a);
           if ( isdigit(a[0]) )
              x = y = (int)a[0] - '0';
           if (x >= 0 && x <= thePlayer->handSize())
              break;
           else
              cout << "Invalid Number" << endl;
        }
        while (x > 0)
        {
           thePlayer->lookAtHand();
           cout << "Which card would you like to discard?" << endl;
           getline(cin, a);
           if (thePlayer->discard(a))
              x--;
           else
              cout << "Invalid Card" << endl;
        }
        thePlayer->draw(y);
      break; // End Cellar
      
    case 2: // Chapel
        acted = thePlayer->playAction(theCard);
        thePlayer->lookAtHand();
        while (true)
        {
           cout << "Enter number of cards to trash:  ";
           getline(cin, a);
           if ( isdigit(a[0]) )
              x = y = (int)a[0] - '0';
           if (x >= 0 && x <= thePlayer->handSize())
              break;
           else
              cout << "Invalid Number" << endl;
        }
        thePlayer->lookAtHand();
        while (x > 0)
        {
           cout << "Which cards would you like to trash?" << endl;
           getline(cin, a);
           if (thePlayer->trash(a,2))
              x--;
           else
              cout << "Invalid Card" << endl;
        }
      break; // End Chapel
        
    case 3: // Moat
      break; // End Moat
        
    case 4: // Harbinger
        acted = thePlayer->playAction(theCard);
        n = false;
        tCards = thePlayer->getCards(3); // This gives the dominion object access to the player's discard pile.
        thePlayer->lookAtCards(tCards);
        while (tCards.size() > 0)
        {
           cout << "Which card would you like to place on top of your deck?" << endl;
           getline(cin, a);
           for (cardIter = tCards.begin(); cardIter != tCards.end(); cardIter++)
           {
              if ( a == (*cardIter)->getCardName() )
              {
                 thePlayer->getCards(1).insert( thePlayer->getCards(1).begin(), (*cardIter) ); // This line is a little ridiculous but oh well. getCards(1) returns a reference to the player's deck.
                 tCards.erase(cardIter);
                 n = true;
                 break;
              }
           }
           if (n)
              break;
        }
      break; // End Harbinger
        
    case 5: // Merchant
      tCards = thePlayer->getCards();
      for (int i = 0; i < tCards.size(); i++)
         if (tCards[i]->getCardName() == "Silver")
            theCard->complexAction(true);
      break; // End Merchant
        
     case 6: // Vassal
        tmpCard = thePlayer->getCards(1)[0];
        cout << "Top card is " << tmpCard->getCardName() << endl;
        if (tmpCard->getType() == Card::Treasure || tmpCard->getType() == Card::Victory)
           thePlayer->discard(thePlayer->getCards(), thePlayer->draw());
        else
        {
           cout << "Would you like to play the " << tmpCard->getCardName() << "? (yes/no)" << endl;
           getline(cin, a);
           if (a[0] == 'Y' || a[0] == 'y')
           {
              thePlayer->draw();
              thePlayer->addActions();
              doAction(thePlayer, tmpCard);
           }
           else
              thePlayer->discard(thePlayer->getCards(), thePlayer->draw());
        }
        break; // End Vassal
        
     case 7: // Village
        break; // End Village
        
    case 8: // Workshop
        myKingdom->showKingdom();
        while (true)
        {
           cout << "You may get a card costing up to 4 money." << endl << "Which card would you like:  ";
           getline(cin, a);
           if (myKingdom->validCard(a) && myKingdom->findCard(a)->getCost() <= 4)
           {
              thePlayer->gain( myKingdom->giveCard(a) );
              break;
           }
           cout << "Invalid Card." << endl;
        }
      break; // End Workshop
        
     case 9: // Bureaucrat
        thePlayer->getCards(1).insert( thePlayer->getCards(1).begin(), myKingdom->giveCard("Silver") );
        for (int i = 0; i < players.size(); i++)
        {
           // Don't Attack yourself
           if (players[i]->getId() == thePlayer->getId())
              continue;
           // Check others' protection
           if (players[i]->defense())
           {
              cout << players[i]->getName() << " has a moat." << endl;
              continue;
           }
           // Get the attacked player's hand
           tCards = players[i]->getCards();
           // Reveal Cards
           cout << players[i]->getName() << " has ";
           for (cardIter = tCards.begin(); cardIter != tCards.end(); cardIter++)
              // Reveal a Victory Card
              if ( (*cardIter)->getType() == Card::Victory )
              {
                 cout << "a " << (*cardIter)->getCardName() << endl;
                 n = true;
                 break;
              }
           // Or, if no victory cards, reveal your hand
           if (!n)
              players[i]->lookAtCards(tCards);
        }
        break; // End Bureaucrat
        
     case 10: // Gardens
        break; // End Gardens
        
    case 11:
      // Militia
      for (int i = 0; i < players.size(); i++)
      {
        if (players[i]->getId() == thePlayer->getId())
          continue;
        if (players[i]->defense())
        {
           cout << players[i]->getName() << " has a moat." << endl;
           continue;
        }
        cout << players[i]->getName() << " must discard 2 cards or down to 3 cards." << endl;
        x = 2;
        while (x > 0 && players[i]->handSize() > 3)
        {
          players[i]->lookAtHand();
          cout << "Which cards would you like to discard?" << endl;
          getline(cin, a);
          if (players[i]->discard(a))
            x--;
        }
      }
      break; // End Militia
        
    case 12: // Moneylender
        thePlayer->lookAtHand();
        tCards = thePlayer->getCards();
        tmpCard = thePlayer->findCard("Copper", tCards);
        if (tmpCard == NULL)
           break;
        cout << "Trash copper for +3 Money?  ";
        getline(cin, a);
        if (a[0] == 'Y' || a[0] == 'y')
        {
           thePlayer->trash("Copper", 2);
           theCard->complexAction(true);
        }
      break; // End Moneylender
        
    case 13: // Poacher
        acted = thePlayer->playAction(theCard);
        x = myKingdom->emptySupplyPiles();
        while (x > 0)
        {
           thePlayer->lookAtHand();
           cout << "Which card would you like to discard?" << endl;
           getline(cin, a);
           if (thePlayer->discard(a))
              x--;
           else
              cout << "Invalid Card" << endl;
        }
      break; // End Poacher
        
    case 14: // Remodel
        acted =  thePlayer->playAction(theCard);
        while (true)
        {
           thePlayer->lookAtHand();
           cout << "Enter card to trash:  ";
           getline(cin, a);
           tmpCard = thePlayer->findCard(a, thePlayer->getCards());
           if (tmpCard != NULL)
              break;
           cout << "Invalid Card" << endl;
        }
        x = tmpCard->getCost() + 2;
        thePlayer->trash(a, 2);
        while (true)
        {
           myKingdom->showKingdom();
           cout << "You may gain a card costing up to " << x << " money." << endl;
           cout << "Enter card to gain:  ";
           getline(cin, a);
           if (myKingdom->validCard(a))
           {
              tmpCard = myKingdom->giveCard(a);
              if (tmpCard->getCost() <= x)
              {
                 thePlayer->gain(tmpCard);
                 break;
              }
           }
           cout << "Invalid Card" << endl;
        }
      break; // End Remodel
        
    case 15: // Smithy
      break; // End Smithy
        
     case 16: // Throne Room
        acted = thePlayer->playAction(theCard);
        tCards = thePlayer->findActions();
        while (tCards.size() > 0)
        {
           cout << "Your Actions: ";
           thePlayer->lookAtCards(tCards);
           cout << "Choose an action to play twice:  ";
           getline(cin, a);
           tmpCard = thePlayer->findCard(a, thePlayer->getCards());
           if (tmpCard != NULL)
              break;
           cout << "Invalid Card" << endl;
        }
        thePlayer->addActions(2);
        doAction(thePlayer, tmpCard);
        thePlayer->getCards().push_back(tmpCard);
        thePlayer->getCards(4).pop_back();
        doAction(thePlayer, tmpCard);
        break; // End Throne Room
        
     case 17: // Bandit
        thePlayer->gain( myKingdom->giveCard("Gold") );
        for (playerIter = players.begin(); playerIter != players.end(); playerIter++)
        {
           if ((*playerIter)->getId() == thePlayer->getId())
              continue;
           if ((*playerIter)->defense())
           {
              cout << (*playerIter)->getName() << " has a moat." << endl;
              continue;
           }
           n = false; m = false;
           
           cout << "The top two cards of " << (*playerIter)->getName() << "'s deck: ";
           cout << (*playerIter)->getCards(1)[0]->getCardName() << ", "
                << (*playerIter)->getCards(1)[1]->getCardName() << endl;
           
           if ( (*playerIter)->getCards(1)[0]->getType() == Card::Treasure &&
                (*playerIter)->getCards(1)[0]->getCardName() != "Copper")
              n = true;
           if ( (*playerIter)->getCards(1)[1]->getType() == Card::Treasure &&
                (*playerIter)->getCards(1)[1]->getCardName() != "Copper")
              m = true;
           
           while (n && m)
           {
              cout << (*playerIter)->getName() << " must trash a treasure card." << endl;
              cout << "Enter the card to trash:  ";
              getline(cin, a);
              if (a == (*playerIter)->getCards(1)[0]->getCardName())
                 n = true;
              if (a == (*playerIter)->getCards(1)[1]->getCardName())
                 m = true;
           }
           
           if (!m)
              (*playerIter)->discard((*playerIter)->getCards(1), (*playerIter)->getCards(1)[1]);
           if (!n && m)
              (*playerIter)->trash((*playerIter)->getCards(1), (*playerIter)->getCards(1)[1]);
           if (!n)
              (*playerIter)->discard((*playerIter)->getCards(1), (*playerIter)->getCards(1)[0]);
           if (!m && n)
              (*playerIter)->trash((*playerIter)->getCards(1), (*playerIter)->getCards(1)[0]);
        }
        break; // End Bandit
        
    case 18: // Council Room
      cout << "Each player draws one card." << endl;
      for (int i = 0; i < players.size(); i++)
        players[i]->draw();
      break; // End Council Room
    
     case 19: // Festival
      break; // End Festival
        
    case 20: // Laboratory
      break; // End Laboratory
      
    case 21: // Library
      while (thePlayer->handSize() <= 7)
      {
         tmpCard = thePlayer->draw();
         cout << "You drew a " << tmpCard->getCardName() << endl;
         if (tmpCard->getTypeStr() == "Action")
         {
            while (a[0] != 'y' && a[0] != 'Y' && a[0] != 'n' && a[0] != 'N')
            {
               cout << "Discard the " << tmpCard->getCardName() << "? ";
               getline(cin, a);
            }
            if (a[0] == 'y' || a[0] == 'Y')
               thePlayer->discard(thePlayer->getCards(), tmpCard);
         }
      }
      break; // End Library
        
     case 22: // Market
        break; // End Market
        
     case 23: // Mine
        tCards = thePlayer->findTreasure();
        if (tCards.size() == 0)
           break;
        thePlayer->lookAtCards(tCards);
        while (true)
        {
           cout << "Choose a card to trash:  ";
           getline(cin, a);
           if (a == "Copper" || a == "Silver" || a == "Gold")
           {
              x = thePlayer->findCard(a, thePlayer->getCards())->getCost();
              thePlayer->trash(a, 2);
              break;
           }
           cout << "Invalid Card" << endl;
        }
        if (x == 0)
           thePlayer->gain(myKingdom->giveCard("Silver"));
        else
           thePlayer->gain(myKingdom->giveCard("Gold"));
        break; // End Mine
        
     case 24: // Sentry
        acted = thePlayer->playAction(theCard);
        tmpCard = NULL;
        tCards = thePlayer->revealDeck(2);
        thePlayer->lookAtCards(tCards);
        while (tCards.size() > 0)
        {
           cout << "Enter card to trash or 0 when done:  ";
           getline(cin, a);
           if (a[0] == '0')
              break;
           tmpCard = thePlayer->findCard(a, tCards);
           if (tmpCard == NULL)
           {
              cout << "Invalid Card" << endl;
              continue;
           }
           thePlayer->trash(thePlayer->getCards(1), tmpCard);
           tCards.erase( find(tCards.begin(), tCards.end(), tmpCard) );
        }
        while (tCards.size() > 0)
        {
           cout << "Enter card to discard or 0 when done:  ";
           getline(cin, a);
           if (a[0] == '0')
              break;
           tmpCard = thePlayer->findCard(a, tCards);
           if (tmpCard == NULL)
           {
              cout << "Invalid Card" << endl;
              continue;
           }
           thePlayer->discard(thePlayer->getCards(1), tmpCard);
           tCards.erase( find(tCards.begin(), tCards.end(), tmpCard) );
        }
        if (tCards.size() == 0)
           break;
        if (tCards.size() == 1)
        {
           cout << tCards[0]->getCardName() << " will be placed on the top of your deck." << endl;
           break;
        }
        tmpCard = NULL;
        while (tmpCard == NULL)
        {
           cout << "Which card do you want on the top of your deck?" << endl;
           getline(cin, a);
           tmpCard = thePlayer->findCard(a, thePlayer->getCards(1));
           if (tmpCard == thePlayer->getCards(1)[1])
           {
              thePlayer->getCards(1)[1] = thePlayer->getCards(1)[0];
              thePlayer->getCards(1)[0] = tmpCard;
              break;
           }
           else
              break;
           cout << "Invalid Card" << endl;
        }
        break; // End Sentry
        
    case 25: // Witch
      for (int i = 0; i < players.size(); i++)
      {
        if (players[i]->getId() == thePlayer->getId())
          continue;
        if (players[i]->defense())
        {
           cout << players[i]->getName() << " has a moat." << endl;
           continue;
        }
        players[i]->gain( myKingdom->giveCard("Curse") );
      }
      break; // End Witch
        
     case 26: // Artisan
        myKingdom->showKingdom();
        while (true)
        {
           cout << "You may get a card costing up to 5 money." << endl << "Which card would you like:  ";
           getline(cin, a);
           if (myKingdom->validCard(a) && myKingdom->findCard(a)->getCost() <= 5)
           {
              thePlayer->gain( myKingdom->giveCard(a) );
              break;
           }
           cout << "Invalid Card." << endl;
        }
        tmpCard = NULL;
        while (true)
        {
           thePlayer->lookAtHand();
           cout << "Choose a card from your hand to place on the top of your deck:  ";
           getline(cin, a);
           tmpCard = thePlayer->findCard(a,thePlayer->getCards());
           if (tmpCard == NULL)
              continue;
           thePlayer->getCards(1).push_back(tmpCard);
           thePlayer->getCards(1)[thePlayer->getCards(1).size()-1] = thePlayer->getCards(1)[0];
           thePlayer->getCards(1)[0] = tmpCard;
           thePlayer->getCards().erase( find( thePlayer->getCards().begin(), thePlayer->getCards().end(), tmpCard) );
        }
        break; // End Artisan
        
  }
  if (!acted)
    acted = thePlayer->playAction(theCard);
  return acted;
}

// Buy Phase
void Dominion::buys(Player *thePlayer)
{
  bool bought = false;
  string in;
  
  myKingdom->showKingdom();
  thePlayer->lookAtHand();
  
  while (!bought)
  {
    cout << "What would you like to buy? Enter 0 to skip or 1 to go back." << endl;
    getline(cin, in);
    
    if (in == "0")
      thePlayer->skipBuys();
    if (in == "0" || in == "1")
      return;
    
    if (
         myKingdom->validCard(in) &&
         (thePlayer->moneyRemaining() >= myKingdom->findCard(in)->getCost()) &&
         myKingdom->numRemain( myKingdom->findCard(in) ) > 0
       )
    {
      bought = true;
      break;
    }
    
    cout << "Invalid Purchase." << endl << endl;
  }
  thePlayer->gain(myKingdom->giveCard(in));
  thePlayer->useBuy(myKingdom->findCard(in)->getCost());
  cout << "You bought a " << myKingdom->findCard(in)->getCardName() << endl << endl;
}
// End Buy Phase
// ----- End Turn and Turn Helpers -----

// ----- Game End and Helpers -----
// Game Over
bool Dominion::gameOver()
{
  int playAgain = 0;
  Player *winner = findWinner();
  
  cout << winner->getName() << " Wins." << endl;
  
  cout << "Scoreboard" << endl;
  for (currPlayer = players.begin(); currPlayer != players.end(); currPlayer++)
    cout << (*currPlayer)->getName() << ": " << (*currPlayer)->getPoints() << endl;
  cout << endl;
  
  while (true)
  {
    cout << "Play Again?" << endl << "1. Yes" << endl << "2. No" << endl;
    string in; getline(cin, in);
    
    if ( isdigit(in[0]) )
      playAgain = (int)in[0] - '0';
    else if (in == "y" || in == "Y" || in == "yes" || in == "Yes")
      playAgain = 1;
    else if (in == "n" || in == "N" || in == "no" || in == "No")
      playAgain = 2;
    
    if (playAgain == 1 || playAgain == 2)
      break;
    cout << "Invalid Response." << endl;
  }
  
  if (playAgain == 1)
    return true;
  return false;
}
// End Game Over

// Find the Winner
Player* Dominion::findWinner()
{
  Player *winner;
  winner = players[0];
  
  for (int i = 1; i < players.size(); i++)
    if ( players[i]->getPoints() > winner->getPoints() )
      winner = players[i];
  
  return winner;
}
// End Find the Winner
// ----- End Game End and Helpers -----



#endif