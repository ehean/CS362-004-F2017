/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 4
 *-randomtestcard1.c
 *-Random tester for the council room card
 *-11/5/17*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int allPassed = 1;
/*compares two ints, printing "FAIL" if not equal, "PASS" if equal, then prints their values.
If failed, then all tests have not passed so value for allPassed set to 0.*/
void newAssert(int expected, int actual){
	if(expected != actual){
		printf("FAIL: expected - %d, actual - %d.\n", expected, actual);
		allPassed = 0;
	}else{
		printf("PASS: expected - %d, actual - %d.\n", expected, actual);
	}
}
int main(){
	//start timer, seed random number generator, and set up variables for players, kingdomCards, for loop counters, and game state
	time_t start, end;
	time(&start);
	srand(time(NULL));
	int numPlayers, kingdomCards[10], h, i, j;
	struct gameState curState, oldState;
	//function for creating a semi-random state 
	void randomizeState(struct gameState *state){
		//set the first kingdom card to council room and each subseqent card to random cards
		kingdomCards[0] = council_room;
		for(i = 1; i < 10; i++){
			while(1){
				kingdomCards[i] = rand() % (treasure_map + 1 - adventurer) + adventurer;
				for(j = 0; j < i; j++){
					if(kingdomCards[i] == kingdomCards[j]){
						break;
					}
				}
				if (j == i){
					break;
				}
			}
		}
		//set the number of players to a random int 2-4
		numPlayers = (rand() % 3) + 2;
		state->numPlayers = numPlayers;
		//set each card's supply to be a random int 0-49, unless not in the game, where it equals -1
		for(i = curse; i <= treasure_map; i++){	
			if(i >= adventurer && i <= treasure_map){
				for(j = 1; j < 10; j++){
					if(i == kingdomCards[j]){
						break;
					}
				}
				if(j == 10){
					state->supplyCount[i] = -1;
				}else{
					state->supplyCount[i] = rand() % 50;
				}
			}
			state->supplyCount[i] = rand() % 50;
		}
		//set hand,discard, and deck to sizes of 10-50 filling each with random valid cards
		for(i = 0; i < numPlayers; i++){
			state->coins = 0;
			state->handCount[i] = (rand() % 41) + 10;
			for(j = 0; j < state->handCount[i]; j++){
				do{
					state->hand[i][j] = rand() % (treasure_map + 1 - curse) + curse;
				}while(state->supplyCount[state->hand[i][j]] == - 1);
			}
			state->discardCount[i] = (rand() % 41) + 10;
			for(j = 0; j < state->discardCount[i]; j++){
				do{
					state->discard[i][j] = rand() % (treasure_map + 1 - curse) + curse;
				}while(state->supplyCount[state->discard[i][j]] == - 1);
			}
			state->deckCount[i] = (rand() % 41) + 10;
			for(j = 0; j < state->deckCount[i]; j++){
				do{
					state->deck[i][j] = rand() % (treasure_map + 1 - curse) + curse;
				}while(state->supplyCount[state->deck[i][j]] == - 1);
			}
		}
	}
	printf("Commence random testing of council room -- randomtestcard1.c -->\n\n");
	for(h = 0; h < 70000; h++){
		printf("Creating a random valid game state. Iteration %d/70000.\n", h+1);
		//randomize the current state, set the current player to random, and give that player council room as a random card in hand
		randomizeState(&curState);
		int curPlayer = rand() % numPlayers; 
		curState.whoseTurn = curPlayer;
		int cardIndex = rand() % curState.handCount[curPlayer];
		curState.hand[curPlayer][cardIndex] = council_room;
		//update coins for current player, and give them a random amount of buys and actions 0-49
		curState.numBuys = rand() % 50;
		curState.numActions = rand() % 50;
		updateCoins(curPlayer, &curState, 0);
		//store curState before playing council room in oldState
		memcpy(&oldState, &curState, sizeof(struct gameState));
		int bonus = 0;
		printf("Player %d is playing council room in a %d player game.\n", curPlayer + 1, numPlayers);
		cardEffect(council_room, 0, 0, 0, &curState, cardIndex, &bonus);
		//For current player draw four expected - 1 discard(council room), and +1 buy
		printf("TESTING four cards added to hand (-1 from council room discard).\n");
		newAssert(oldState.handCount[curPlayer] + 3, curState.handCount[curPlayer]);
		printf("TESTING four cards taken from deck.\n");
		newAssert(oldState.deckCount[curPlayer] - 4, curState.deckCount[curPlayer]);
		printf("TESTING discard count increased by 1 from council room.\n");
		newAssert(oldState.discardCount[curPlayer] + 1, curState.discardCount[curPlayer]);
		printf("TESTING number of buys has increased by 1 after council room played.\n");
    newAssert(oldState.numBuys + 1, curState.numBuys);
    printf("TESTING number of actions has stayed the same after council room played.\n");
    newAssert(oldState.numActions, curState.numActions);
		//Other players expected to draw 1 card apiece, +1 hand size (taken from top of deck), -1 deck size, discard unaffected
		printf("TESTING each other player has drawn a card.\n");
		for(j = 0; j < numPlayers; j++){
			if(j != curPlayer){
				printf("TESTING player %d hand count has increased by 1.\n", j + 1);
				newAssert(oldState.handCount[j] + 1, curState.handCount[j]);
				printf("TESTING player %d deck count has decreased by 1.\n", j + 1);
				newAssert(oldState.deckCount[j] - 1, curState.deckCount[j]);
				printf("TESTING new card in player %d's hand is the top card of previous deck.\n", j + 1);
				newAssert(oldState.deck[j][oldState.deckCount[j] - 1], curState.hand[j][curState.handCount[j] - 1]);
				printf("TESTING player %d discard count has remained the same.\n", j + 1);
				newAssert(oldState.discardCount[j], curState.discardCount[j]);
			}
		}
		//card supplies unaffected after playing
		printf("TESTING supplies of each card not changed.\n");
		for(j = curse; j <= treasure_map; j++){
			newAssert(oldState.supplyCount[j], curState.supplyCount[j]);
		}
		//empty the structs after each iteration
		memset(&curState, 0, sizeof(struct gameState));
		memset(&oldState, 0, sizeof(struct gameState));
	}
	//print to the user if all tests have passed with "SUCCESS" or "FAILURE" otherwise
	if(allPassed){
		printf("SUCCESS - ALL TESTS PASSED.\n\n");
	}else{
		printf("FAILURE - SOME TEST(S) FAILED.\n\n"); 
	}
	//end the timer and print the test duration
	time(&end);
	double duration = difftime(end, start);
	printf("Test ran in %fs.\n", duration);
	return 0;
}
