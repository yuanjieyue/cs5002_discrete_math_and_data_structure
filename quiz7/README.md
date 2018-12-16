# Quiz 7

## Instructions

Copy this directory in to the root of your repository. Your solutions will consist of the code you type into quiz7.c and deck.c.

## Commands

To compile tests: `make test`

To run tests: `./test`

To compile game: `make play`

To run game: `./play`

## Minor details

1. Implement functions in the order they are tested. This will help you since the tests are written such that they depend on the previous tests succeeding.
1. Do not copy the card to the hand - you only need to copy the pointer over.
1. Do not free the `Card` structure when removing it from a hand. You only need to free the `CardInHand` struct. 
1. Remember to free all the cards present in the deck when destroyDeck is called before free-ing the deck itself.
1. Hand is implemented as a Linked List where insertion of the card goes in the front of the list - this is what allows for O(1) insertion. If we were to insert the card in the back of the list then this would be an O(n) operation.
