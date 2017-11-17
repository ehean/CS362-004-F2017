/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 3
 *-unittest4.c
 *- Unit test for getWinners()
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

/*Compares expected integer array with actual integer arrays,
 * returning 0 if not equal, 1 if equal and printing their values.*/
int myArrayAssert(int expected[], int actual[], int length){
	//assert failure
	int i;
	for(i = 0; i < length; i++){
		if(expected[i] != actual[i]){
			printf("TEST FAILED: expected[%d] = %d, actual[%d] = %d.\n", i, expected[i], i, actual[i]);
			allTestsPassed = 0;
			return 0;
		}
	}
	//assert pass
	printf("TEST PASSED: expected and actual arrays equal.\n");
	return 1;
}

int main(){
	printf("TESTING getWinners() -- unittest4.c -- :\n\n");
  //set up an initial 4 player game with a random seed of 10 and 10 arbitrary kingdom cards, into state
  int kingdomCards[10] = {adventurer, council_room, feast, ambassador, cutpurse, remodel, smithy, village, embargo, outpost};
  struct gameState state;
	//create int arrays to hold the expected and actual results for who has won the game and return values for functions
  int numPlayers = 4, randomSeed = 10, expectedResults[MAX_PLAYERS] = {1,1,1,1}, actualResults[MAX_PLAYERS], returnVal;
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	//set all players to equal turn counts
	state.whoseTurn = 3;
	returnVal = getWinners(actualResults, &state);	
	printf("TESTING a 4 player game with equal victory points and turn counts, expected score array {1,1,1,1}.\n");
	myArrayAssert(expectedResults, actualResults, MAX_PLAYERS);
	//give player 1 an extra turn
	expectedResults[0] = 0;
	state.whoseTurn = 0;
	returnVal = getWinners(actualResults, &state);	
	printf("TESTING a 4 player game with equal victory points but player 1 has one more turn, expected score array {0,1,1,1}.\n");
	myArrayAssert(expectedResults, actualResults, MAX_PLAYERS);
	//give player 1 extra victory points
	expectedResults[0] = 1;
	expectedResults[1] = 0;
	expectedResults[2] = 0;
	expectedResults[3] = 0;
	printf("TESTING a 4 player game where player 1 has extra victory points over 2,3,4 by gaining an estate in discard, expected score array {1,0,0,0}.\n");
	//make sure player 1 successfully gains estate
	if((returnVal = gainCard(estate, &state, 0, 0))!= 0){
		printf("Failed to gain estate to player 1's discard.\n");
		allTestsPassed = 0;
	}else{
		returnVal = getWinners(actualResults, &state);
		myArrayAssert(expectedResults, actualResults, MAX_PLAYERS);
	}
	//test a 2 player game to see that unitialized player's win states handled correctly
	struct gameState otherState;
	numPlayers = 2;
  initializeGame(numPlayers, kingdomCards, randomSeed, &otherState);
	//set all players to equal turn counts
	otherState.whoseTurn = 1;
	returnVal = getWinners(actualResults, &otherState);	
	printf("TESTING a 2 player game with equal victory points and turn counts, expected score array {1,1,-9999,-9999}.\n");
	expectedResults[1] = 1;
	expectedResults[2] = -9999;
	expectedResults[3] = -9999;
	myArrayAssert(expectedResults, actualResults, MAX_PLAYERS);
	if(allTestsPassed){
		printf("TEST SUCCESSFULLY COMPLETED.\n\n");
	}else{
    printf("TEST HAS FAILED.\n\n");
  }

	return 0;
}
