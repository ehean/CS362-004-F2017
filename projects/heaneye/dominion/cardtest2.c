/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 3
 *-cardtest2.c
 *- Unit test for council room card
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
 * printing failure if not equal, passed if equal and printing their values.*/
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
	printf("TESTING council room  -- cardtest2.c -- :\n\n"); 
  //set up an initial 4 player game with a random seed of 10 and 10 arbitrary kingdom cards, into curState
  int kingdomCards[10] = {adventurer, council_room, feast, ambassador, cutpurse, remodel, smithy, village, embargo, outpost};
  struct gameState curState, prevState;
  int numPlayers = 4, randomSeed = 10, i, discardCount = 1, drawCount = 4,
			choice1 = 0, choice2 = 0, choice3 = 0, handPos = 4, bonus;
  initializeGame(numPlayers, kingdomCards, randomSeed, &curState);
	//set the fifth card in player 1's hand to be council_room and save state to prevState
	curState.hand[0][4] = council_room;
	memcpy(&prevState, &curState, sizeof(struct gameState));
	//play council room
	cardEffect(council_room, choice1, choice2, choice3, &curState, handPos, &bonus);
	printf("TESTING player 1's hand count increased by 4, expected hand size 8 (after discarding council room).\n");
	myAssert(prevState.handCount[0] + drawCount - discardCount, curState.handCount[0]);
	printf("TESTING player 1's deck count decreased by 4 , expected deck size 1.\n");
	myAssert(prevState.deckCount[0] - drawCount, curState.deckCount[0]);
	printf("TESTING the 4 cards added to player 1's hand were the top 4 cards of the previous deck.\n");
	int deckCounter = prevState.deckCount[0];
	//discard mechanic in dominion.c works by replacing the last card in hand with the discarded position, hence the ordering
	myAssert(prevState.deck[0][deckCounter - 4], curState.hand[0][4]);
	myAssert(prevState.deck[0][deckCounter - 1], curState.hand[0][5]);
	myAssert(prevState.deck[0][deckCounter - 2], curState.hand[0][6]);
	myAssert(prevState.deck[0][deckCounter - 3], curState.hand[0][7]);
	printf("TESTING player 1's buy count increased by 1 , expected count 2.\n");
	myAssert(prevState.numBuys + 1, curState.numBuys);
	printf("TESTING no changes in victory or kingdom card supplies.\n");
	for(i = curse; i < treasure_map; i++){
		myAssert(prevState.supplyCount[i], curState.supplyCount[i]);
	}
	printf("TESTING each other player's hand count has increased by 1.\n");
	for(i = 1; i < 4; i++){
		myAssert(prevState.handCount[i] + 1, curState.handCount[i]);
	}
	printf("TESTING each other player's deck count decreased by 1, expected deck size 9.\n");
	for(i = 1; i < 4; i++){
		myAssert(prevState.deckCount[i] - 1, curState.deckCount[i]);
	}
	printf("TESTING the card added to each other player's hand was the top card of the previous deck.\n");
	for(i = 1; i < 4; i++){
		myAssert(prevState.deck[i][prevState.deckCount[i] - 1], curState.hand[i][0]);
	}
	if(allTestsPassed){
		printf("TEST SUCCESSFULLY COMPLETED.\n\n");
	}else{
    printf("TEST HAS FAILED.\n\n");
  }

	return 0;
}
