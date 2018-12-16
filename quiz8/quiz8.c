#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "quiz8.h"

#define DEBUG 0

// ------------------- FREQ TABLE --------------

/**
 * 	populate the array with the number of instances
 * 	of each character in the given input string.
 *
 */
FreqTable *createFreqTable(char *input){
  // Allocate Memory on the heap for the new frequence table
  FreqTable *newTable = (FreqTable*)malloc(sizeof(FreqTable));

  // Initialize every char on the  ascii table
  int i = 0;
  for(i = 0; i < strlen(input); i++){
    newTable->charCount[input[i]]++;
  }
  // Return the newly created table
  return newTable;
}

void destroyFreqTable(FreqTable *aTable){
  // Free the allocated frequence table on the heap
  free(aTable);
}

/**
 * Print out the frequency table.
 * For conciseness, only print out entries that
 * have counts greater than 0.
 *
 * Example output:
 *
 * -----------
 * A: 1
 * D: 3
 * E: 2	
 * ___________
 */
void printFreqTable(FreqTable *aTable){
  // Loop over the acsii table and print
  int i = 0;
  while(i < NUM_ASCII_CHARS){
    // Print the slots with the value more than 0
    if(aTable->charCount[i] > 0){
      printf("%c:  %d\n", i, aTable->charCount[i]);
    }
    i++;
  }
  printf("\n");
}




// ------------------- BIT SEQ --------------




BitSeq* createBitSeq(){
  // Allocate memory on the heap for the bit sequence
  BitSeq* newBitSeq = (BitSeq*)malloc(sizeof(BitSeq));
  // Initialize the field in bit seq	
  newBitSeq->numBitsInSeq = 0;
  // Return the newly created bit seq
  return newBitSeq;
}

void destroyBitSeq(BitSeq* aBitSeq){
  // Free the allocated memory of the bit sequence
  free(aBitSeq);
}

void printBitSeq(BitSeq *aBitSeq){
  int i;
  // Loop over the bit seq and print
  for(i = 0; i < MAX_BIT_SEQ_LENGTH; i++){
    printf("%d\n", aBitSeq->bits[i]);
  }
}
void packBits(BitSeq *bits, char* newBitsAsChars){
  // Declare a display mask for the bits
  unsigned short displayMask;
  int i;
  // Loop over the bit seq to find the location to pack the bits
  for(i = 0; i < strlen(newBitsAsChars); i++){
    // Find the precies position of the current bit in the current slot
    int offset = bits->numBitsInSeq % 16;
    // Find the current slot to pack
    int current = bits->numBitsInSeq / 16;
    
    displayMask = 0b1000000000000000;
    if(newBitsAsChars[i] == '1'){
      bits->bits[current] ^= (displayMask>>offset);
    }
    // Update the number of bits in the seq
    bits->numBitsInSeq++;
  }
	
}
/*void packBits(BitSeq *bits, char* newBitsAsChars){
  unsigned c;
  char display mask = 1 << 7; 
  int count = 0;// Take 1, shift it all the way to the left.
  for(c=1; c<=8; c++){
  if(newBitsAsChars & displayMask)
  break;	    
  newBitsAsChars <<= 1;
  }
  int a = bits->numBitsInSeq / 16; // get the slot where should the new bits insert
  int b = bits->numBitsInSeq % 16; // get the location in the slot where the new bits should start insert
  unsigned d = newBitsAsChars;
  if(16 - b >= 8){
  d = d <<= (16 - b) - 8;
  bits->bits[a] = bits->bits[a] | d;
  }
  else{
  unsigned temp1 = newBitsAsChars;
  unsigned temp2 = newBitsAsChars;
  temp1 >>= 8 - (16 - b);
  temp2 <<= 16 - (8 - (16 - b));
  bits->bits[a] = bits->bits[a] | temp1;
  bits->bits[a + 1] = temp2;
  }
  }
*/
void displayBits(unsigned short value, int numBits){
  unsigned c;
  // Take 1, shift it all the way to the left.
  unsigned displayMask = 1 << 15;   
  printf("%3c%7u = ", value, value);  
  for(c=1; c<=numBits; c++){
    // putchar prints a character on the screen
    // ‘value & displayMask’ gets the relevant bit
    putchar(value & displayMask ? '1' : '0');    
    // Shift value over one
    value <<= 1;    
    // Put a space in for easy reading
    if (c % 8 == 0){
      putchar(' ');
    }
  }
  putchar('\n');
}


// ------------------- HTREE --------------

////////////////////////////////////////////////////////////////////////////


stackOfHTrees* createStack(){
  // Allocate space on the heap
  stackOfHTrees* treeStack = 
    (stackOfHTrees*)malloc(sizeof(stackOfHTrees)); 
  // Initialize anything
  treeStack->HTreeAtTop = -1; 

  // Return pointer to new stack
  return treeStack; 
} 

int isStackEmpty(stackOfHTrees* treeStack){
  // If the htree at top equals -1, returns 1;
  // Otherwise, returns 0;
  return treeStack->HTreeAtTop == -1;
}


stackOfHTrees* pushTreeToStack(HTree* newTree, stackOfHTrees* treeStack){
  // If the stack is full, we do not push and return the given stack
  if(treeStack->HTreeAtTop == MAX_MESSAGE_LENGTH-1){
    return treeStack;
  }
  // If the stack is not full, we push to new tree at the top and update the top field.
  treeStack->HTreeAtTop++; 
  treeStack->trees[treeStack->HTreeAtTop] = newTree;
  // Return the new stack after we push
  return treeStack; 
} 


HTree* popTreeFromStack(stackOfHTrees* treeStack){
  // If the stack is empty, return null
  if(treeStack->HTreeAtTop == -1){
    return NULL;
  }
  // If the Stack is not empty, we pop the top tree in the stack, and 
  HTree* popTree = treeStack->trees[treeStack->HTreeAtTop];
  // Update the top field as well;
  treeStack->HTreeAtTop--;

  return popTree;
} 


void printHTreeStack(stackOfHTrees* treeStack){
  printf("Printing the stack of trees:\n"); 
  int i; 
  // Loop over the stack and print 
  for (i=treeStack->HTreeAtTop; i>=0; i--){
    printf("\t[%c: %25d ]\n", treeStack->trees[i]->c, treeStack->trees[i]->freq);
  }
}


void destroyStack(stackOfHTrees* treeStack){
  // Free anything that hasn’t been freed
  while(!isStackEmpty(treeStack)){
    HTree* temp = popTreeFromStack(treeStack);
    free(temp);
  } 	
  // Free the stack
  free(treeStack); 
}


/////////////////////////////////////////////////////////////////////////////////
stackOfHTrees* sortStack(stackOfHTrees* treeStack){
  int i, j;
  for (i = 0; i <= treeStack->HTreeAtTop; i++){
    for(j = i; j > 0; j--){
      // If the latter tree has a big freq than the former one, swap them
      if(treeStack->trees[j]->freq > treeStack->trees[j-1]->freq){
	HTree* temp = treeStack->trees[j];
	treeStack->trees[j] = treeStack->trees[j-1];
        treeStack->trees[j-1] = temp;
      }
      // If the latter tree and the former tree have the same freq, then swap them if the latter is bigger alphabetically than the former one.
      else if(treeStack->trees[j]->freq == treeStack->trees[j-1]->freq && treeStack->trees[j]->c - treeStack->trees[j-1]->c > 0){
	HTree* temp = treeStack->trees[j];
	treeStack->trees[j] = treeStack->trees[j-1];
        treeStack->trees[j-1] = temp;
      }
      else{
	break;
      }	
    }
  }
  return treeStack;
}
     

/**
 *	Given a Frequency Table,
 * 	create an Huffman tree.
 * 	Return a pointer to the root of the final tree.
 */
HTree* createEncodingTree(FreqTable *aTable){
  // Allocate memory for a new Huffman tree
  HTree* newTree = (HTree*)malloc(sizeof(HTree));
  // Create a new stack to store huffman tree node
  stackOfHTrees* newTreeStack = createStack();
  
  int i;
  // Loop over the freq table
  for(i = 0; i < NUM_ASCII_CHARS; i++){
    // Create tree node for every character than has freq more than 0
    if(aTable->charCount[i] > 0){
      HTree* newTreeNode = (HTree*)malloc(sizeof(HTree));
      // Initialize every tree node 
      newTree->c = i;
      newTree->freq = aTable->charCount[i];
      newTree->p0 = NULL;
      newTree->p1 = NULL;

      // Push every newly created tree node to the stack
      pushTreeToStack(newTreeNode, newTreeStack);
    }
		
  }
  // Only if the stack is empty that we stop push and pop
  while(newTreeStack->HTreeAtTop > 0){
    // Once a new node is pushed into the stack, we sort the stack to make the node with lowest freq on top
    sortStack(newTreeStack);
    // Pop the two node on the top of the stack and make a new node with them.
    HTree* firstNode = popTreeFromStack(newTreeStack);
    HTree* secondNode = popTreeFromStack(newTreeStack);
    HTree* parentNode = (HTree*)malloc(sizeof(HTree));
    // Initialize the new parent node
    parentNode->c = 0;
    parentNode->freq = firstNode->freq + secondNode->freq;
    parentNode->p0 = firstNode;
    parentNode->p1 = secondNode;
    // Then push it back to the stack
    pushTreeToStack(parentNode, newTreeStack);
  }
  // In the end there will be only one node in the stack, which is the root
  HTree* HTree = popTreeFromStack(newTreeStack);
  // Pop the root and return
  return HTree;
}

void destroyHTree(HTree *tree){
  if(tree != NULL){
    HTree* p0 = tree->p0;
    HTree* p1 = tree->p1;
    free(tree);
    destroyHTree(p0);
    destroyHTree(p1);
  }
}

void printHTree(HTree *tree){
  if(tree->p0 != NULL){
    printHTree(tree->p0);
  }
  if(tree->p1 != NULL){
    printHTree(tree->p1);
  }
  if(tree != NULL){
    printf("%c\t%d\n", tree->c, tree->freq);
  }
}


// ------------- MAIN FUNCTIONS ----------------
char* lookuptable[NUM_ASCII_CHARS];;
char string[NUM_ASCII_CHARS];

void traverseTree (HTree* tree, char* s){
  // If the given huffman tree is null, return with nothing
  if(tree == NULL)
    return;
  // If the left child of the tree is not null, we traverse the left child with a string that appends "0" at its end
  if(tree->p0 != NULL){
    char* copy = (char*)malloc(sizeof(char));
    strcpy(copy, s);
    traverseTree(tree->p0, strcat(copy, "0"));
  }
  // If the right child of the tree is not null, we traverse the right child with a string that appends "1" at its end
  if(tree->p1 != NULL){
    char* copy = (char*)malloc(sizeof(char));
    strcpy(copy,s);
    traverseTree(tree->p1, strcat(copy, "1"));
  }
  // If both the tree's left and right child is null, then it is a leaf, we write the tracing string to the relevant slot in the lookup table.
  if(tree->p0 == NULL && tree->p1 == NULL){
    lookuptable[tree->c] = s;
  }
}



/**
 * Takes in a string and a pointer to a BitSeq to populate,
 * After encode, hTree should be pointing to the root of the final tree.
 */
HTree *encode(char *input, BitSeq *bitSeq){
  // Create a freq table with the input string and create the huffman tree with the freq table
  HTree* HTree = createEncodingTree(createFreqTable(input));
  strcpy(string, "");

  // Traverse the tree with an empty string to initialize the lookup table
  traverseTree(HTree, string);
  int i;
  // Use the lookup table to pack bits to the bit seq.
  for(i = 0; i < strlen(input); i++){
    packBits(bitSeq, lookuptable[input[i]]);
  }
  // Return the Huffman Tree
  return HTree;
}

/**
 *	Take in a BitSeq (sequence of bits),
 * 	and a Huffman tree.
 * 	Use the tree to decode the bit sequence.
 * 	Return a pointer to the decoded string.
 */
char *decode(BitSeq *bitSeq, HTree *tree){
  // Declare a mask
  unsigned mask = 1 << 15;
  HTree *curr =  tree;
  char* string = (char*)malloc(sizeof(char));
  int index = 0, count = 0;
  int i;
  // Loop over the bit seq to the number of bits in the seq
  for(i = 0; i <= bitSeq->numBitsInSeq; i++){
    // Reinitialize the mask at the start of every slot in the bit seq
    if(count % 16 == 0){
      mask = 1<<15;
    }
    // If the current tree is a leaf, write the character in the leaf to the string
    if(curr->p0 == NULL && curr->p1 == NULL){
      string[index++] = curr->c;
      curr = tree;
    }
    // If the bits is '1', we go to the right child of the tree
    if(bitSeq->bits[i/16] & mask){
      curr = curr->p1;
    }
    // If the bits is '0', we go to the left child of the tree
    else{
      curr = curr->p0;
    }
    // Shift the mask to the left for one bit
    mask >>= 1;
    count++;
  }
  // Return the decoding string
  return string;
}



