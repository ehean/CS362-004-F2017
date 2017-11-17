/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 3
 *-cardtest3.c
 *- Unit test for adventurer card
 *-10/22/17*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Game rules from http://riograndegames.com/uploads/Game/Game_278_gameRules.pdf

//int acting as a boolean to determine if all tests have passed at the end of test code
int allTestsPassed = 1;

/*Compares expected integer value with actual integer value,
 * printing failure if not equal, pass if equal and printing their values.*/
void myAssert(int expected, int actual){
	//assert failure
	if(expected != actual){
		printf("TEST FAILED: expected = %d, actual = %d.\n", expected, actual);
		allTestsPassed = 0;
	}else{
		//assert pass
		printf("TEST PASSED: expected = %d, actual = %d.\n", expected, actual);
	}
}

int main(){
	printf("TESTING adventurer  -- cardtest3.c -- :\n\n"); 
  //set up an initial 4 player game with a random seed of 10 and 10 arbitrary kingdom cards, into curState
  int kingdomCards[10] = {adventurer, council_room, feast, ambassador, cutpurse, remodel, smithy, village, embargo, outpost};
  struct gameState curState, prevState;
  int numPlayers = 4, randomSeed = 10, discardCount = 1, drawCount = 2,
			choice1 = 0, choice2 = 0, choice3 = 0, handPos = 4, bonus, i, j;
  initializeGame(numPlayers, kingdomCards, randomSeed, &curState);
	/*set the fifth card in player 1's hand to be adventurer, top 3 cards in 
	 * player 1's deck to non-treasure cards, last 2 to be treasure, and save to prevState*/
	curState.hand[0][4] = adventurer;
	curState.deck[0][4] = adventurer;
	curState.deck[0][3] = adventurer;
	curState.deck[0][2] = adventurer;
	curState.deck[0][1] = copper;
	curState.deck[0][0] = copper;
	memcpy(&prevState, &curState, sizeof(struct gameState));
	//play adventurer
	cardEffect(adventurer, choice1, choice2, choice3, &curState, handPos, &bonus);
	printf("TESTING player 1's hand count increased by 2 after adventurer played, expected hand size 6 (after discarding adventurer).\n");
	myAssert(prevState.handCount[0] + drawCount - discardCount, curState.handCount[0]);
	printf("TESTING player 1's deck count decreased by 2 drawn + 3 non-treasure after adventurer played, expected deck size 0.\n");
	myAssert(prevState.deckCount[0] - drawCount - 3, curState.deckCount[0]);
	printf("TESTING the 2 cards added by adventurer were the bottom 2 cards of the previous deck.\n");
	//discard mechanic in dominion.c works by replacing the last card in hand with the discarded position, hence the ordering
	myAssert(prevState.deck[0][0], curState.hand[0][4]);
	myAssert(prevState.deck[0][1], curState.hand[0][5]);
	printf("TESTING player 1's discard count increased by 3 after adventurer played, expected size 3.\n");
	myAssert(prevState.discardCount[0] + 3, curState.discardCount[0]);
	printf("TESTING no changes in victory or kingdom card supplies.\n");
	for(i = curse; i < treasure_map; i++){
		myAssert(prevState.supplyCount[i], curState.supplyCount[i]);
	}
	printf("TESTING no state changes occured in other players.\n\n");
	printf("TESTING each other player's discard count remained the same.\n");
	for(i = 1; i < 4; i++){
		myAssert(prevState.discardCount[i], curState.discardCount[i]);
	}
	printf("TESTING each card in each other player's discard pile is the same.\n");
	for(i = 1; i < 4; i++){
		for(j = 0; j < prevState.discardCount[i]; j++){
			myAssert(prevState.discard[i][j], curState.discard[i][j]);
		}
	}
	printf("TESTING each other player's hand count remained the same.\n");
	for(i = 1; i < 4; i++){
		myAssert(prevState.handCount[i], curState.handCount[i]);
	}
	printf("TESTING each card in each other player's hand is the same.\n");
	for(i = 1; i < 5; i++){
		for(j = 0; j < prevState.handCount[1]; j++){
			myAssert(prevState.hand[1][j], curState.hand[1][j]);
		}
	}
	printf("TESTING each other player's deck count remained the same.\n");
	for(i = 1; i < 4; i++){
		myAssert(prevState.deckCount[i], curState.deckCount[i]);
	}
	printf("TESTING each card in each other player's deck is the same.\n");
	for(i = 1; i < 4; i++){
		for(j = 0; j < prevState.deckCount[i]; j++){
			myAssert(prevState.deck[i][j], curState.deck[i][j]);
		}
	}
	if(allTestsPassed){
		printf("TEST SUCCESSFULLY COMPLETED.\n\n");
	}else{
    printf("TEST HAS FAILED.\n\n");
  }

	return 0;
}
