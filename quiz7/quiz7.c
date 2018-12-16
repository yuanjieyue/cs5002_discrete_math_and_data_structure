#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

#include "quiz7.h"

#define PRINT_DEBUG 1

// Implement the Hand and other functions in here


//----------------------------------------
// Hand functions
//----------------------------------------

// Creates a Hand struct and initializes any necessary fields. 
// Returns a pointer to the new Hand, which has been allocated on the heap. 
Hand* createHand(){
  Hand* newHand = (Hand*)malloc(sizeof(Hand));
  newHand->firstCard = NULL;
  newHand->num_cards_in_hand = 0;

  return newHand;
}

// Creates a CardNode struct and initialiszes any necessary fields.
// Returns a pointer to the new CardNode, which has been allocated on the heap.
CardNode* createCardNode(Card* card){
  CardNode* newCardNode = (CardNode*)malloc(sizeof(CardNode));
  newCardNode->thisCard = card;
  newCardNode->prevCard = NULL;
  newCardNode->nextCard = NULL;

  return newCardNode;
}

// Adds a card to the hand. 
void addCardToHand(Card *card, Hand *hand){
  CardNode* newCardNode = createCardNode(card);

  if(hand->firstCard != NULL){
    newCardNode->nextCard = hand->firstCard;
    hand->firstCard->prevCard = newCardNode;
  }
  hand->firstCard = newCardNode;

  hand->num_cards_in_hand++;
}


// Removes a card from the hand. 
Card* removeCardFromHand(Card *card, Hand *hand){

  CardNode* curNode;
  curNode = hand->firstCard;
  if(hand->num_cards_in_hand == 0)
    return card;
	

  while(curNode->thisCard != card)
    curNode = curNode->nextCard;

  if(curNode->prevCard == NULL && curNode->nextCard == NULL){
    hand->firstCard = NULL;
  }
  else if(curNode->prevCard == NULL){
    hand->firstCard  = curNode->nextCard;
    hand->firstCard->prevCard = NULL;
  }
  else if(curNode->nextCard == NULL){
    curNode->prevCard->nextCard  = NULL;
  }
  else{
    curNode->prevCard->nextCard = curNode->nextCard;
    curNode->nextCard->prevCard = curNode->prevCard;
  }
  hand->num_cards_in_hand--;
  free(curNode);
  return card;
}

// Determines if there are any cards in the hand. 
// Return 0 if the hand is empty; 1 otherwise. 
int isHandEmpty(Hand* hand){
  if(hand->num_cards_in_hand == 0)
    return 0;
  else
    return 1;
}

// Destroys the hand, freeing any memory allocated for it. 
void destroyHand(Hand* hand){
  while(hand->firstCard != NULL){
    CardNode* temp = hand->firstCard;
    hand->firstCard = hand->firstCard->nextCard;
    free(temp);
  }
  free(hand);
}




//----------------------------------------
// Game functions
//----------------------------------------


// Shuffle the deck. 
// Put them in a random order. 
void shuffle(Deck *aDeck){
  Card* temp = (Card*)malloc(sizeof(Card));
  temp = NULL;

  int i, k;
  for(i = NUM_CARDS_IN_HAND - 1; i > 0; i--){
    k = random()%(i + 1);
    temp = aDeck->cards[i]; 
    aDeck->cards[i] = aDeck->cards[k]; 
    aDeck->cards[k] = temp;
  }
}

// Given a deck (assume that it is already shuffled), 
// take the top card from the deck and alternately give 
// it to player 1 and player 2, until they both have 
// NUM_DECKS_IN_HAND. 
void deal(Deck *aDeck, Hand *p1hand, Hand *p2hand){

  while(p1hand->num_cards_in_hand != NUM_CARDS_IN_HAND || p2hand->num_cards_in_hand != NUM_CARDS_IN_HAND){
    if(p1hand->num_cards_in_hand < NUM_CARDS_IN_HAND)
      addCardToHand(popCardFromDeck(aDeck), p1hand);

    if(p2hand->num_cards_in_hand < NUM_CARDS_IN_HAND)
      addCardToHand(popCardFromDeck(aDeck), p2hand);
  }	
}

// Create a Deck for this game, and add any 
// needed cards to the deck. 
// Return a pointer to the deck to be used for the game 
Deck* populateDeck(){
  Deck* aDeck = createDeck();

  Suit s = HEARTS;
  Name n = NINE;
  for(; s <= DIAMONDS; s++){
    for(n = NINE; n <= ACE; n++){
      Card* newCard = (Card*)malloc(sizeof(Card));
      newCard->suit = s;
      newCard->name = n;
      aDeck = pushCardToDeck(newCard, aDeck);
    }
  }

  return aDeck;
}


// Given a lead card, a players hand, and the card the player wants 
// to play, is it legal? 
// If the player has a card of the same suit as the ledCard, they 
// must play a card of the same suit. 
// If the player does not have a card of the same suit, they can 
// play any card. 
int isLegalMove(Hand *hand, Card *leadCard, Card *playedCard){
  if(playedCard->suit == leadCard->suit)
    return 1;

  while(hand->firstCard != NULL){
    if(hand->firstCard->thisCard->suit == leadCard->suit)
      return 0;

    hand->firstCard = hand->firstCard->nextCard;
  }

  return 1;
}


// Given two cards that are played in a hand, which one wins? 
// If the suits are the same, the higher card value wins. 
// If the suits are not the same, player 1 wins, unless player 2 played trump. 
// Returns 1 if the person who led won, 0 if the person who followed won. 
int whoWon(Card *leadCard, Card *followedCard, Suit trump){
  int res = 0;
  if(followedCard->suit == leadCard->suit){
    if(followedCard->name > leadCard->name)
      res = 0;
    else
      res = 1;
  }
  else{
    if(followedCard->suit == trump)
      res = 0;
    else
      res = 1;
  }
  return res;
}

// Take all the cards out of a given hand, and put them 
// back into the deck. 
void returnHandToDeck(Hand *hand, Deck *deck){
  //	Card* card = (Card*)malloc(sizeof(Card));

  while(hand->firstCard != NULL){
    pushCardToDeck(removeCardFromHand(hand->firstCard->thisCard, hand), deck);

    hand->firstCard = hand->firstCard->nextCard;
  }
}

//----------------------------------------
// Challenge functions
//----------------------------------------

// Considering this for a challenge problem. 
Card* getBestMove(Hand *myHand, Card *ledCard, Suit trump);

// Sort the given hand in descending order of power. 
// 
// The sort order should be: all cards of the given trump should 
// be the "highest", and A high down to 9; 
// The other suits can be in random order, but the card values must go 
// from high to low. 
void sortHand(Hand *hand, Suit trump);




void shuffleHand(Hand* hand);


//----------------------------------------
// Helper functions
//----------------------------------------

void printCard(Card *aCard);

void printHand(Hand *aHand); 

void printDeck(Deck *aDeck); 

char *getName(Name aCardName); 

char *getSuit(Suit aCardSuit);

 
