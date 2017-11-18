/***********************************************************************
 ** Unit Test 2
 ** This performs a unit test of the handCard function in dominion.c
 **
 ** Include the following lines in your makefile:
 **
 ** cardtest2: cardtest2.c dominion.o rngs.o
 **      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
     int numPlayers = 2; 
     int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
     int randomSeed = 1000;
     struct gameState controlGame, testGame;
     int handPos = 0;
     int passCount = 0;
     int failCount = 0;
     int thisPlayer = 0;

     // initialie control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\t Player 1\n");

     int i;
     for (i = 0; i < testGame.handCount[thisPlayer]; i++) {
          printf("\thandCard %d = %d, expected %d\n", i, handCard(i, &testGame), handCard(i, &controlGame));
          if (handCard(i, &testGame) == handCard(i, &controlGame)) {
               printf("\tPASS\n\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n\n");
               failCount++;
          }
     }

     printf("TEST 2:\n\t Player 2\n");
     endTurn(&testGame);
     endTurn(&controlGame);
     thisPlayer++;

     for (i = 0; i < testGame.handCount[thisPlayer]; i++) {
          printf("\thandCard %d = %d, expected %d\n", i, handCard(i, &testGame), handCard(i, &controlGame));
          if (handCard(i, &testGame) == handCard(i, &controlGame)) {
               printf("\tPASS\n\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n\n");
               failCount++;
          }
     }

  

     printf("HANDCARD PASS COUNT:\t%d\n", passCount);
     printf("HANDCARD FAIL COUNT:\t%d\n", failCount);
}