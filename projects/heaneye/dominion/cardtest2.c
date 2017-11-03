/*
 * cardtest2.c
 *
 * To compile: make cardtest2
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {

     int numPlayers = 2; 
     int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
     int randomSeed = 1000;
     struct gameState controlGame, testGame;
     int thisPlayer = 0;
     int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
     int passCount = 0;
     int failCount = 0;

     // initialie control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tHand Count, pre-effect\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 0 discard+deck count = %d, expected = %d\n", testGame.discardCount[thisPlayer]+testGame.deckCount[thisPlayer], controlGame.discardCount[thisPlayer]+controlGame.deckCount[thisPlayer]);
     if (testGame.discardCount[thisPlayer]+testGame.deckCount[thisPlayer] == controlGame.discardCount[thisPlayer]+controlGame.deckCount[thisPlayer]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     // add 30 copper to current player's deck

     testGame.coins = 200;
     testGame.numBuys = 40;
     int i;
     for (i = 0; i < 20; i++) {
          buyCard(adventurer, &testGame);
     }
     for (i = 0; i < 20; i++) {
          buyCard(copper, &testGame);
     }

     
     endTurn(&testGame);
     endTurn(&testGame);
     int tmpTotalCardCount = testGame.handCount[thisPlayer] + testGame.deckCount[thisPlayer] + testGame.handCount[thisPlayer];


     cardEffect(adventurer, choice1, choice2, choice3, &testGame, handpos, &bonus);

     printf("TEST 2:\n\tHand Count, post-effect\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]+2);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]+2) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     
     tmpTotalCardCount = testGame.handCount[thisPlayer] + testGame.deckCount[thisPlayer] + testGame.handCount[thisPlayer];

     endTurn(&testGame);
     endTurn(&testGame);


     printf("TEST 3:\n\tHand Count, post-effect\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]+4) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

       printf("\tplayer 0 hand+deck+discard count = %d, expected = %d\n", testGame.discardCount[thisPlayer]+testGame.deckCount[thisPlayer]+testGame.handCount[thisPlayer], tmpTotalCardCount);
     if (testGame.discardCount[thisPlayer]+testGame.deckCount[thisPlayer]+testGame.handCount[thisPlayer] == tmpTotalCardCount) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     

     printf("ADVENTURER PASS COUNT:\t%d\n", passCount);
     printf("ADVENTURER FAIL COUNT:\t%d\n", failCount);
	return 0;
}

