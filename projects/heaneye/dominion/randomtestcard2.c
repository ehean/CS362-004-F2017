/****************************************************************
** randomtestcard1.c
** random test of the smithy card
*****************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


int const TEST_COUNT = 10000;

int const INCLUDE_NONDELTAS = 0;

int main()
{
     srand(time(NULL));
     int passCount = 0;
     int failCount = 0;
     clock_t begin = clock();

     int k;
     for (k = 0; k < TEST_COUNT; k++) {

          int numPlayers = (rand() % (MAX_PLAYERS-1)) + 2; 
          printf("num players = %d\n", numPlayers);
          int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
          int adventurerInGame = 0;
          int randomSeed = 1000;
          struct gameState testGame, preConditionState;

          int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

          int thisPlayer = 0;


          // initialize control game state

          printf("initialize game\n");
          initializeGame(numPlayers, kingdomCards, randomSeed, &testGame);
          initializeGame(numPlayers, kingdomCards, randomSeed, &preConditionState);


     
          printf("randomize values\n");

          int i;
          for (i = 0; i < treasure_map+1; ++i) {
               testGame.supplyCount[i] = rand() % 10;
               testGame.embargoTokens[i] = rand() % 10;

               preConditionState.supplyCount[i] = testGame.supplyCount[i];
               preConditionState.embargoTokens[i] = testGame.embargoTokens[i];
          }

          printf("supply count and embargo tokens randomized\n");

          testGame.outpostPlayed = rand() % 2;
          testGame.outpostTurn = rand() % 2;
          testGame.whoseTurn = rand() % testGame.numPlayers;
          testGame.phase = rand() % 2;
          testGame.numActions = rand() % 5;
          testGame.coins = rand() % 10;
          testGame.numBuys = rand() % 5;
          testGame.playedCardCount = rand() % 5;


          preConditionState.outpostPlayed = testGame.outpostPlayed;
          preConditionState.outpostTurn = testGame.outpostTurn;
          preConditionState.whoseTurn = testGame.whoseTurn;
          preConditionState.phase = testGame.phase;
          preConditionState.numActions = testGame.numActions;
          preConditionState.coins = testGame.coins;
          preConditionState.numBuys = testGame.numBuys;
          preConditionState.playedCardCount = testGame.playedCardCount;

          printf("randomized non-array values\n");

          int j;
          for (i = 0; i < testGame.numPlayers; i++) {

               testGame.handCount[i] = rand() % MAX_HAND + 1;

               preConditionState.handCount[i] = testGame.handCount[i];

               // MAKE SURE SMITHY IS IN EVERY PLAYER'S HAND
               testGame.hand[i][0] = smithy;
               preConditionState.hand[i][0] = testGame.hand[i][0];
               for (j = 0; j < testGame.handCount[i]; j++) {
                    testGame.hand[i][j] = rand() % treasure_map + 1;
                    preConditionState.hand[i][j] = testGame.hand[i][j];
               }

               testGame.deckCount[i] = rand() % MAX_DECK + 1;
               preConditionState.deckCount[i] = testGame.deckCount[i];
               for (j = 0; j < testGame.deckCount[i]; j++) {
                    testGame.deck[i][j] = rand() % treasure_map + 1;
                    preConditionState.deck[i][j] = testGame.deck[i][j];
               }

               testGame.discardCount[i] = rand() % MAX_DECK + 1;
               preConditionState.discardCount[i] = testGame.discardCount[i];
               for (j = 0; j < testGame.discardCount[i]; j++) {
                    testGame.discard[i][j] = rand() % treasure_map + 1;
                    preConditionState.discard[i][j] = testGame.discard[i][j];
               }
          }

          printf("randomized hand/deck/discard piles\n");


          testGame.playedCardCount = rand() % MAX_DECK + 1;
          preConditionState.playedCardCount = testGame.playedCardCount;
          for (i = 0; i < testGame.playedCardCount; i++) {
               testGame.playedCards[i] = rand() % treasure_map + 1;
               preConditionState.playedCards[i] = testGame.playedCards[i];
          }

          // save pre-condition values



          // TEST PRECONDITION STATE
          printf("TEST 1:\n\tHand Count, pre-effect\n");

          printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], preConditionState.handCount[thisPlayer]);
          if (testGame.handCount[thisPlayer] == preConditionState.handCount[thisPlayer]) {
               printf("\tPASS\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n");
               failCount++;
          }


          printf("\tplayer 0 deck count = %d, expected = %d\n", testGame.deckCount[thisPlayer], preConditionState.deckCount[thisPlayer]);
          if (testGame.deckCount[thisPlayer] ==  preConditionState.deckCount[thisPlayer]) {
               printf("\tPASS\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n");
               failCount++;
          }


          printf("\tplayer 0 numActions = %d, expected = %d\n", testGame.numActions, preConditionState.numActions);
          if (testGame.numActions ==  preConditionState.numActions) {
               printf("\tPASS\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n");
               failCount++;
          }


          // PLAY CARD
          cardEffect(smithy, choice1, choice2, choice3, &testGame, handpos, &bonus);


          // TEST POST-CONDITION STATE

          printf("TEST 2:\n\tHand Count, post-effect\n");

          

          printf("\tplayer 0 hand count = %d, expected = %d\n", testGame.handCount[thisPlayer], preConditionState.handCount[thisPlayer]+1);
          if (testGame.handCount[thisPlayer] == preConditionState.handCount[thisPlayer]+1) {
               printf("\tPASS\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n");
               failCount++;
          }


          printf("TEST 3:\n\tDeck Count, post-effect\n");

          printf("\tplayer 0 deck count = %d, expected = %d\n", testGame.deckCount[thisPlayer], preConditionState.deckCount[thisPlayer]-1);
          if (testGame.deckCount[thisPlayer] == preConditionState.deckCount[thisPlayer]-1) {
               printf("\tPASS\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n");
               failCount++;
          }


          printf("TEST 4:\n\tnumActions, post-effect\n");

          printf("\tplayer 0 numActions = %d, expected = %d\n", testGame.numActions, preConditionState.numActions+2);
          if (testGame.numActions ==  preConditionState.numActions+2) {
               printf("\tPASS\n");
               passCount++;
          }
          else {
               printf("\tFAIL\n");
               failCount++;
          }





// TEST THE VARIABLES THAT SHOULD NOT BE EFFECTED BY ADVENTURER CARD PLAY

          if (INCLUDE_NONDELTAS) {

               for (i = 0; i < treasure_map+1; i++) {
                    printf("\tplayer 0 supply count card %d = %d, expected = %d", i, testGame.supplyCount[i], preConditionState.supplyCount[i]);
                    if (testGame.supplyCount[i] == preConditionState.supplyCount[i]) {
                         printf("\t\tPASS\n");
                         passCount++;
                    }
                    else {
                         printf("\t\tFAIL\n");
                         failCount++;
                    }

                    printf("\tplayer 0 embargo tokens %d count = %d, expected = %d", i, testGame.embargoTokens[i], preConditionState.embargoTokens[i]);
                    if (testGame.embargoTokens[i] == preConditionState.embargoTokens[i]) {
                         printf("\t\tPASS\n");
                         passCount++;
                    }
                    else {
                         printf("\t\tFAIL\n");
                         failCount++;
                    }
               }
          
               for (i = 0; i < testGame.numPlayers; i++) {

                    printf("\tplayer %d hand count = %d, expected = %d", i, testGame.handCount[i], preConditionState.handCount[i]);
                    if (testGame.handCount[i] == preConditionState.handCount[i]) {
                         printf("\t\tPASS\n");
                         passCount++;
                    }
                    else {
                         printf("\t\tFAIL\n");
                         failCount++;
                    }

                    printf("\tplayer %d discard count = %d, expected = %d", i, testGame.discardCount[i], preConditionState.discardCount[i]);
                    if (testGame.discardCount[i] == preConditionState.discardCount[i]) {
                         printf("\t\tPASS\n");
                         passCount++;
                    }
                    else {
                         printf("\t\tFAIL\n");
                         failCount++;
                    }

                    printf("\tplayer %d deck count = %d, expected = %d", i, testGame.deckCount[i], preConditionState.deckCount[i]);
                    if (testGame.deckCount[i] == preConditionState.deckCount[i]) {
                         printf("\t\tPASS\n");
                         passCount++;
                    }
                    else {
                         printf("\t\tFAIL\n");
                         failCount++;
                    }
               
                    for (j = 0; j < testGame.handCount[i]; j++) {
                         printf("\tplayer %d hand card %d = %d, expected = %d", i, j, testGame.hand[i][j], preConditionState.hand[i][j]);
                         if (testGame.hand[i][j] == preConditionState.hand[i][j]) {
                              printf("\t\tPASS\n");
                              passCount++;
                         }
                         else {
                              printf("\t\tFAIL\n");
                              failCount++;
                         }
                    }

                    
                    for (j = 0; j < testGame.deckCount[i]; j++) {
                         printf("\tplayer %d deck card %d = %d, expected = %d", i, j, testGame.deck[i][j], preConditionState.deck[i][j]);
                         if (testGame.deck[i][j] == preConditionState.deck[i][j]) {
                              printf("\t\tPASS\n");
                              passCount++;
                         }
                         else {
                              printf("\t\tFAIL\n");
                              failCount++;
                         }
                    }

                    
                    for (j = 0; j < testGame.discardCount[i]; j++) {
                         printf("\tplayer %d discard card %d = %d, expected = %d", i, j, testGame.discard[i][j], preConditionState.discard[i][j]);
                         if (testGame.discard[i][j] == preConditionState.discard[i][j]) {
                              printf("\t\tPASS\n");
                              passCount++;
                         }
                         else {
                              printf("\t\tFAIL\n");
                              failCount++;
                         }
                    }
               }
          



               printf("\tplayer 0 played card count = %d, expected = %d", testGame.playedCardCount, preConditionState.playedCardCount);
               if (testGame.playedCardCount == preConditionState.playedCardCount) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 numBuys = %d, expected = %d", testGame.numBuys, preConditionState.numBuys);
               if (testGame.numBuys == preConditionState.numBuys) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 coins = %d, expected = %d", testGame.coins, preConditionState.coins);
               if (testGame.coins == preConditionState.coins) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 phase = %d, expected = %d", testGame.phase, preConditionState.phase);
               if (testGame.phase == preConditionState.phase) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 outpost turn = %d, expected = %d", testGame.outpostTurn, preConditionState.outpostTurn);
               if (testGame.outpostTurn == preConditionState.outpostTurn) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 outpost turn = %d, expected = %d", testGame.whoseTurn, preConditionState.whoseTurn);
               if (testGame.whoseTurn == preConditionState.whoseTurn) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 outpost Played count = %d, expected = %d", testGame.outpostPlayed, preConditionState.outpostPlayed);
               if (testGame.outpostPlayed == preConditionState.outpostPlayed) {
                    printf("\t\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\t\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 numPlayers count = %d, expected = %d\n", testGame.numPlayers, preConditionState.numPlayers);
               if (testGame.numPlayers == preConditionState.numPlayers) {
                    printf("\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\tFAIL\n");
                    failCount++;
               }

               printf("\tplayer 0 numActions count = %d, expected = %d\n", testGame.numActions, preConditionState.numActions);
               if (testGame.numActions == preConditionState.numActions) {
                    printf("\tPASS\n");
                    passCount++;
               }
               else {
                    printf("\tFAIL\n");
                    failCount++;
               }
          }

     }

	clock_t end = clock();
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     printf("test complete\n");
	printf("Running Time: %f\n\n", time_spent);
     printf("ADVENTURER PASS COUNT:\t%d\n", passCount);
     printf("ADVENTURER FAIL COUNT:\t%d\n", failCount);
	return 0;

}