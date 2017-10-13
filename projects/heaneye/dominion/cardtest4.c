/***********************************************************************
** Card Test 4
** Village
** Pre-conditions:
**        hand[currentPlayer] = 5
**        numActions = x
** Post-conditions:
**        hand[currentPlayer] = 5
**        numActions += 2
************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"

int main() {

     int numPlayers = 4; 
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

     printf("TEST 1:\n\tAction Count, pre-condition\n");

     printf("\taction count = %d, expected = %d\n", testGame.numActions, controlGame.numActions);
     if (testGame.numActions == controlGame.numActions) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("TEST 2:\n\tHand Counts, pre-condition\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 1 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+1], controlGame.handCount[thisPlayer+1]);
     if (testGame.handCount[thisPlayer+1] == controlGame.handCount[thisPlayer+1]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 2 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+2], controlGame.handCount[thisPlayer+2]);
     if (testGame.handCount[thisPlayer+2] == controlGame.handCount[thisPlayer+2]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 3 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+3], controlGame.handCount[thisPlayer+3]);
     if (testGame.handCount[thisPlayer+3] == controlGame.handCount[thisPlayer+3]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     cardEffect(village, choice1, choice2, choice3, &testGame, handpos, &bonus);

     printf("TEST 3:\n\tAction Count, post-condition\n");

     printf("\tplayer 0 action count = %d, expected = %d\n", testGame.numActions, controlGame.numActions+1);
     if (testGame.numActions == controlGame.numActions+1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

      printf("TEST 4:\n\tHand Counts, post-condition\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 1 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+1], controlGame.handCount[thisPlayer+1]);
     if (testGame.handCount[thisPlayer+1] == controlGame.handCount[thisPlayer+1]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 2 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+2], controlGame.handCount[thisPlayer+2]);
     if (testGame.handCount[thisPlayer+2] == controlGame.handCount[thisPlayer+2]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 3 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+3], controlGame.handCount[thisPlayer+3]);
     if (testGame.handCount[thisPlayer+3] == controlGame.handCount[thisPlayer+3]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }



      cardEffect(village, choice1, choice2, choice3, &testGame, handpos, &bonus);

     printf("TEST 5:\n\tAction Count, post-condition\n");

     printf("\tplayer 0 action count = %d, expected = %d\n", testGame.numActions, controlGame.numActions+2);
     if (testGame.numActions == controlGame.numActions+2) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

      printf("TEST 6:\n\tHand Counts, post-condition\n");

     printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], controlGame.handCount[thisPlayer]);
     if (testGame.handCount[thisPlayer] == controlGame.handCount[thisPlayer]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 1 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+1], controlGame.handCount[thisPlayer+1]);
     if (testGame.handCount[thisPlayer+1] == controlGame.handCount[thisPlayer+1]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 2 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+2], controlGame.handCount[thisPlayer+2]);
     if (testGame.handCount[thisPlayer+2] == controlGame.handCount[thisPlayer+2]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tplayer 3 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer+3], controlGame.handCount[thisPlayer+3]);
     if (testGame.handCount[thisPlayer+3] == controlGame.handCount[thisPlayer+3]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }



     printf("VILLAGE PASS COUNT:\t%d\n", passCount);
     printf("VILLAGE FAIL COUNT:\t%d\n", failCount);
	return 0;
}

