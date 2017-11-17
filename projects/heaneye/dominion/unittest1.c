/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 3
 *-unittest1.c
 *- Unit test for function isGameOver() in dominion.c
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
 * returning failure statment if not equal, passed statement if equal and printing their values.*/
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
	printf("TESTING isGameOver()  -- unittest1.c -- :\n\n"); 
	//set up an initial 2 player game with a random seed of 10 and 10 arbitrary kingdom cards, into state
	int kingdomCards[10] = {adventurer, council_room, feast, ambassador, cutpurse, remodel, smithy, village, embargo, outpost};
	struct gameState state;
	int numPlayers = 2, randomSeed = 10;
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	//Test the initial game state to see if it is game over
	printf("TESTING a new 2 player game, expecting return value of 0.\n");
	myAssert(0, isGameOver(&state));
	//set the province supply pile to 0
	state.supplyCount[province] = 0;
	printf("TESTING a 2 player game with only an empty province supply pile, expecting return value 1.\n");
	myAssert(1, isGameOver(&state));
	//set province supply pile to 8 and adventurer supply pile to 0
	state.supplyCount[province] = 8;
	state.supplyCount[adventurer] = 0;
	printf("TESTING a 2 player game with only one empty non-province supply pile, expecting return value 0.\n");
	myAssert(0, isGameOver(&state));
	//set estate supply pile to 0
	state.supplyCount[estate] = 0;
	printf("TESTING a 2 player game with only two empty non-province supply piles, expecting return value 0.\n");
	myAssert(0, isGameOver(&state));
	//set curse supply pile to 0
	state.supplyCount[curse] = 0;
	printf("TESTING a 2 player game with only three empty non-province supply piles, expecting return value 1.\n");
	myAssert(1, isGameOver(&state));
	if(allTestsPassed){
		printf("TEST SUCCESSFULLY COMPLETED.\n\n");
	}else{
		printf("TEST HAS FAILED.\n\n");
	}
	return 0;
}
