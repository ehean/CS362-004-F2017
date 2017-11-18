/***********************************************************************
 ** Unit Test 1
 ** This performs a unit test of the whoseTurn function in dominion.c
 **
 ** Include the following lines in your makefile:
 **
 ** cardtest4: cardtest4.c dominion.o rngs.o
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

     int passCount = 0;
     int failCount = 0;

     // initialie control game state
     int r = initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\t2 players\n\tTurn 0\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame));
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 2:\n\t2 players\n\tTurn 1\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame)+1);
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)+1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 3:\n\t2 players\n\tTurn 2\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame));
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     numPlayers++;

     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 4:\n\t3 players\n\tTurn 0\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame));
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 5:\n\t3 players\n\tTurn 1\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame)+1);
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)+1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 6:\n\t3 players\n\tTurn 2\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame)+2);
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)+2) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 7:\n\t3 players\n\tTurn 3\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame));
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


     numPlayers++;

     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 8:\n\t3 players\n\tTurn 0\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame));
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 9:\n\t3 players\n\tTurn 1\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame)+1);
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)+1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 10:\n\t3 players\n\tTurn 2\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame)+2);
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)+2) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 11:\n\t3 players\n\tTurn 3\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame)+3);
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)+3) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     endTurn(&testGame);

     printf("TEST 12:\n\t3 players\n\tTurn 4\n");

     printf("\twhoseTurn = %d, expected %d\n", whoseTurn(&testGame), whoseTurn(&controlGame));
     if (whoseTurn(&testGame) == whoseTurn(&controlGame)) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


     printf("WHOSETURN PASS COUNT:\t%d\n", passCount);
     printf("WHOSETURN FAIL COUNT:\t%d\n", failCount);
}