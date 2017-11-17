/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 3
 *-unittest3.c
 *- Unit test for buyCard()
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
	 printf("TESTING buyCard()  -- unittest3.c -- :\n\n");
  //set up an initial 4 player game with a random seed of 10 and 10 arbitrary kingdom cards, into curState
  int kingdomCards[10] = {adventurer, council_room, feast, ambassador, cutpurse, remodel, smithy, village, embargo, outpost};
  struct gameState curState, prevState;
  int numPlayers = 4, randomSeed = 10;
  initializeGame(numPlayers, kingdomCards, randomSeed, &curState);
	/*set up conditions for player 1 to buy with 2 buys, 4 coins, a supply of 1 estate, 1 duchy, 1 curse, and copy curState into 
	prevState*/
	curState.supplyCount[estate] = 1;
	curState.supplyCount[duchy] = 1;
	curState.supplyCount[curse] = 1;
	curState.numBuys = 2;
	curState.coins = 4;
	curState.whoseTurn = 0;
	memcpy(&prevState, &curState, sizeof(struct gameState));
	printf("TESTING a buy of a 2 cost card with 4 coins and 2 buys, expected return value 0.\n");
	myAssert(0, buyCard(estate, &curState));
	printf("TESTING coins decrease by 2 after buying a 2 cost card, expected return value 2.\n");
	myAssert(prevState.coins - 2, curState.coins);
	printf("TESTING buy count decreased by 1 after buying, expected return value 1.\n");
	myAssert(prevState.numBuys - 1, curState.numBuys);
	printf("TESTING supply of bought card decreasing by one after buy, expected return value 0.\n");
	myAssert(prevState.supplyCount[estate] - 1, curState.supplyCount[estate]);
	printf("TESTING player discard pile increased by one after buying card, expected return value 1.\n");
	myAssert(prevState.discardCount[0] + 1, curState.discardCount[0]);
	printf("TESTING new discard card for player 1 is bought card (estate).\n");
	myAssert(estate, curState.discard[0][0]);
	printf("TESTING buy a 2 cost card with 2 coins, 1 buy, but no supply, expected return value -1.\n");
	myAssert(-1, buyCard(estate, &curState));
	printf("TESTING buy a 5 cost card with 2 coins, 1 buy, supply of 1, expected return value -1.\n");
	myAssert(-1, buyCard(duchy, &curState));
	curState.numBuys = 0;
	printf("TESTING buy 0 cost card with 2 coins, 0 buys, supply of 1, expected return value -1.\n");
	myAssert(-1, buyCard(curse, &curState));
	if(allTestsPassed){
		printf("TEST SUCCESSFULLY COMPLETED.\n\n");
	}else{
    printf("TEST HAS FAILED.\n\n");
  }

	return 0;
}
