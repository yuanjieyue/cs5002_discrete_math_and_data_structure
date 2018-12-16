#include <stdio.h>
#include <stdlib.h>

#include "quiz7.h"

#define PRINT_DEBUG 1
// Deck functions
//----------------------------------------
// Implement these functions in deck.c. 
// Creates the deck to be used for NEUchre. 
// Assume that the value of cards are: 
// Nine=9; Ten=10; Jack=11; and so on, up to Ace=14. 

// Creates the deck, initializing any fields necessary. 
// Returns a pointer to the deck, which has been allocated on the heap. 
Deck* createDeck(){
  Deck* newDeck = (Deck*)malloc(sizeof(Deck));

  newDeck->topCard = -1;
  int i;
  for(i = 0; i < NUM_CARDS_IN_DECK; i++){
    newDeck->cards[i] = NULL;
  }

  return newDeck;
}

// Adds a card to the top of the deck. 
// Returns a pointer to the deck. 
Deck* pushCardToDeck(Card* newCard, Deck* deck){
  if(deck->topCard < NUM_CARDS_IN_DECK - 1){
    deck->topCard++;
    deck->cards[deck->topCard] = newCard;
  }
	
  return deck;	
}

// Shows the top card, but does not remove it from the stack. 
// Returns a pointer to the top card. 
Card* peekAtTopCard(Deck* deck){
  if(!isDeckEmpty(deck)){
    return deck->cards[deck->topCard];
  }
  return NULL;
}

// Removes the top card from the deck and returns it. 
// Returns a pointer to the top card in the deck. 
Card* popCardFromDeck(Deck* deck){
  if(!isDeckEmpty(deck)){
    return deck->cards[deck->topCard--];
  }
  return NULL;
}

// Determines if the deck is empty. 
// Returns 0 if the Deck has any cards; 1 otherwise. 
int isDeckEmpty(Deck* deck){
  if(deck->topCard > -1)
    return 0;
  else
    return 1;
}

// Destroys the deck, freeing any memory allocated 
// for this deck (the cards and the deck). 
void destroyDeck(Deck* deck){
  free(deck);
}
