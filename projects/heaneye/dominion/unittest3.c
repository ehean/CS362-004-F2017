/***********************************************************************
 ** Unit Test 3
 ** This performs a unit test of the buyCard function in dominion.c
 ** Conditions:
 **       whoseTurn:
 **            1, 2, 3, or 4
 **       numBuys:
 **            < 1: print message, return -1
 **       supplyCount:
 **            < 1: print message, return -1
 **       coins:
 **            < cardCost: print message, return -1
 **       if numBuys >= 1 AND supplyCount >= 1 AND coins >= cardCost:
 **            phase = 1
 **            discardCount += 1
 **            numBuys -= 1
 **            supplyCount -= 1
 **            coins -= cardCost
 **            print message
 **       
 ***********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
     int numPlayers = 4; 
     int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
     int randomSeed = 1000;
     struct gameState controlGame, testGame;
     int handPos = 0;
     int passCount = 0;
     int failCount = 0;
     int thisPlayer = 0;

     // initialie control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.numBuys = 0;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tnumBuy == 0\n\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (copper) = %d, expected = %d\n", testGame.supplyCount[copper], controlGame.supplyCount[copper]);
     if (testGame.supplyCount[copper] == controlGame.supplyCount[copper]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     int r;
     r = buyCard(copper, &testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\treturn value = %d, expected = %d\n", r, -1);
     if (r == -1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }
     // if (DEBUG) {
     //      printf("\tDEBUG message = %s, expected = %s\n", r, "You do not have any buys left\n");
     //      if (stdout == "You do not have any buys left\n") {
     //           printf("\tPASS\n\n");
     //           passCount++;
     //      }
     //      else {
     //           printf("\tFAIL\n\n");
     //           failCount++;
     //      }
     //}

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (copper) = %d, expected = %d\n", testGame.supplyCount[copper], controlGame.supplyCount[copper]);
     if (testGame.supplyCount[copper] == controlGame.supplyCount[copper]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


      // initialie control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.supplyCount[copper] = 0;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tsupplyCount == 0\n\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (copper) = %d, expected = %d\n", testGame.supplyCount[copper], controlGame.supplyCount[copper]);
     if (testGame.supplyCount[copper] == controlGame.supplyCount[copper]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     r = buyCard(copper, &testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\treturn value = %d, expected = %d\n", r, -1);
     if (r == -1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }
     // if (DEBUG) {
     //      printf("\tDEBUG message = %s, expected = %s\n", r, "You do not have any buys left\n");
     //      if (stdout == "You do not have any buys left\n") {
     //           printf("\tPASS\n\n");
     //           passCount++;
     //      }
     //      else {
     //           printf("\tFAIL\n\n");
     //           failCount++;
     //      }
     //}

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (copper) = %d, expected = %d\n", testGame.supplyCount[copper], controlGame.supplyCount[copper]);
     if (testGame.supplyCount[copper] == controlGame.supplyCount[copper]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }



        // initialie control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.coins = 1;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tcoins < cardCostn\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (estate) = %d, expected = %d\n", testGame.supplyCount[estate], controlGame.supplyCount[estate]);
     if (testGame.supplyCount[estate] == controlGame.supplyCount[estate]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     r = buyCard(estate, &testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\treturn value = %d, expected = %d\n", r, -1);
     if (r == -1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }
     // if (DEBUG) {
     //      printf("\tDEBUG message = %s, expected = %s\n", r, "You do not have any buys left\n");
     //      if (stdout == "You do not have any buys left\n") {
     //           printf("\tPASS\n\n");
     //           passCount++;
     //      }
     //      else {
     //           printf("\tFAIL\n\n");
     //           failCount++;
     //      }
     //}

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (estate) = %d, expected = %d\n", testGame.supplyCount[estate], controlGame.supplyCount[estate]);
     if (testGame.supplyCount[estate] == controlGame.supplyCount[estate]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


             // initialie control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.coins = 2;
     controlGame.supplyCount[estate] = 1;
     controlGame.numBuys = 1;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 4:\n\tnumBuys == 1 AND supplyCount == 1 AND coins == cardCostn\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys);
     if (testGame.numBuys == controlGame.numBuys) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (estate) = %d, expected = %d\n", testGame.supplyCount[estate], controlGame.supplyCount[estate]);
     if (testGame.supplyCount[estate] == controlGame.supplyCount[estate]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins);
     if (testGame.coins == controlGame.coins) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     r = buyCard(estate, &testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tphase = %d, expected = %d\n", testGame.phase, controlGame.phase);
     if (testGame.phase == 1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tdiscardCount = %d, expected = %d\n", testGame.discardCount[thisPlayer], controlGame.discardCount[thisPlayer]+1);
     if ( testGame.discardCount[thisPlayer] == controlGame.discardCount[thisPlayer]+1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tnumBuys = %d, expected = %d\n", testGame.numBuys, controlGame.numBuys-1);
     if (testGame.numBuys == controlGame.numBuys-1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\treturn value = %d, expected = %d\n", r, 0);
     if (r == 0) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }
     // if (DEBUG) {
     //      printf("\tDEBUG message = %s, expected = %s\n", r, "You do not have any buys left\n");
     //      if (stdout == "You do not have any buys left\n") {
     //           printf("\tPASS\n\n");
     //           passCount++;
     //      }
     //      else {
     //           printf("\tFAIL\n\n");
     //           failCount++;
     //      }
     //}

     printf("\twhoseTurn = %d, expected = %d\n", testGame.whoseTurn, controlGame.whoseTurn);
     if (testGame.whoseTurn == controlGame.whoseTurn) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount (estate) = %d, expected = %d\n", testGame.supplyCount[estate], controlGame.supplyCount[estate]-1);
     if (testGame.supplyCount[estate] == controlGame.supplyCount[estate]-1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tcoins = %d, expected = %d\n", testGame.coins, controlGame.coins - getCost(estate));
     if (testGame.coins == controlGame.coins- getCost(estate)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("BUYCARD PASS COUNT:\t%d\n", passCount);
     printf("BUYCARD FAIL COUNT:\t%d\n", failCount);
}