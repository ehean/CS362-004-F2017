/*
 * cardtest1.c
 *
 * To compile: make cardtest1
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

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
     int r = initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

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

     cardEffect(smithy, choice1, choice2, choice3, &testGame, handpos, &bonus);

     printf("TEST 2:\n\tHand Count, post-effect\n");

     // testGame.handCount[thisPlayer] = 20;
     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]+2);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]+2) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


     cardEffect(smithy, choice1, choice2, choice3, &testGame, handpos+1, &bonus);

     // thisPlayer++; 

     printf("TEST 3:\n\tHand Count, post-effect\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]+4);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]+4) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


     printf("SMITHY PASS COUNT:\t%d\n", passCount);
     printf("SMITHY FAIL COUNT:\t%d\n", failCount);
	return 0;
}

