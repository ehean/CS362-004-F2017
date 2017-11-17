/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 4
 *-randomtestcard2.c
 *-Random tester for the smithy card
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
		//set the first kingdom card to smithy and each subseqent card to random cards
		kingdomCards[0] = smithy;
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
	printf("Commence random testing of smithy -- randomtestcard2.c -->\n\n");
	for(h = 0; h < 70000; h++){
		printf("Creating a random valid game state. Iteration %d/70000\n", h+1);
		//randomize the current state, set the current player to random, and give that player smithy as a random card in hand
		randomizeState(&curState);
		int curPlayer = rand() % numPlayers; 
		curState.whoseTurn = curPlayer;
		int cardIndex = rand() % curState.handCount[curPlayer];
		curState.hand[curPlayer][cardIndex] = smithy;
		//update coins for current player, and give them a random amount of buys and actions 0-49
		curState.numBuys = rand() % 50;
		curState.numActions = rand() % 50;
		updateCoins(curPlayer, &curState, 0);
		//store curState before playing smithy in oldState;
		memcpy(&oldState, &curState, sizeof(struct gameState));
		int bonus = 0;
		printf("Player %d is playing smithy in a %d player game.\n", curPlayer + 1, numPlayers);
		cardEffect(smithy, 0, 0, 0, &curState, cardIndex, &bonus);
		//expected to draw 3 cards (2 net for smithy discard), discard count increases for smithy
		printf("TESTING three cards added to hand (-1 from smithy discard).\n");
		newAssert(oldState.handCount[curPlayer] + 2, curState.handCount[curPlayer]);
		printf("TESTING three cards taken from deck.\n");
		newAssert(oldState.deckCount[curPlayer] - 3, curState.deckCount[curPlayer]);
		printf("TESTING discard count increased by 1 from smithy added.\n");
		newAssert(oldState.discardCount[curPlayer] + 1, curState.discardCount[curPlayer]);
		printf("TESTING number of buys has stayed the same after smithy played.\n");
		newAssert(oldState.numBuys, curState.numBuys);
		printf("TESTING number of actions has stayed the same after smithy played.\n");
		newAssert(oldState.numActions, curState.numActions);
		//other players' hands, decks, and discard piles remain unaffected
		printf("TESTING no other state changes made in other players\n"); 
		for(j = 0; j < numPlayers; j++){
			if(j != curPlayer){
				printf("TESTING player %d hand count has remained the same.\n", j + 1);
				newAssert(oldState.handCount[j], curState.handCount[j]);
				printf("TESTING player %d deck count has remained the same.\n", j + 1);
				newAssert(oldState.deckCount[j], curState.deckCount[j]);
				printf("TESTING player %d discard count has remained the same.\n", j + 1);
				newAssert(oldState.discardCount[j], curState.discardCount[j]);
			}
		}
		//supplies should not be changed
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
