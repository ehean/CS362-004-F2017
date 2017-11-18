/***********************************************************************
 ** Unit Test 4
 ** This performs a unit test of the isGameOver function in dominion.c
 ** Conditions:
 **       if supplyCount[province] == 0:
 **            return 1
 **       else if supplyCounts of 3 or more cards == 0:
 **            return 1
 **       else
 **            return 0
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

     // initialize control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.numBuys = 0;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tsupplyCount[province] == 1\n\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     int testEmptySupplyDecks = 0;
     int controlEmptySupplyDecks = 0;
     int i;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     int r;
     r = isGameOver(&testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tisGameOver = %d, expected = %d\n", r, 0);
     if (r == 0) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }



     // initialize control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.supplyCount[estate] = 0;
     controlGame.supplyCount[duchy] = 0;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tnumber of empty supply decks == 2\n\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     r = isGameOver(&testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tisGameOver = %d, expected = %d\n", r, 0);
     if (r == 0) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     // initialize control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.supplyCount[province] = 0;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 1:\n\tnumber of empty supply decks == 2\n\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     r = isGameOver(&testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tisGameOver = %d, expected = %d\n", r, 1);
     if (r == 1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }


     // initialize control game state
     initializeGame(numPlayers, kingdomCards, randomSeed, &controlGame);

     controlGame.supplyCount[estate] = 0;
     controlGame.supplyCount[duchy] = 0;
     controlGame.supplyCount[village] = 0;

     memcpy(&testGame, &controlGame, sizeof(struct gameState));

     printf("TEST 4:\n\tnumber of empty supply decks == 3\n\n");
     printf("PRE-CONDITION:\n\n");
     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     r = isGameOver(&testGame);

     printf("POST-CONDITION:\n\n");

     printf("\tisGameOver = %d, expected = %d\n", r, 1);
     if (r == 1) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     printf("\tsupplyCount[province] = %d, expected = %d\n", testGame.supplyCount[province], controlGame.supplyCount[province]);
     if (testGame.supplyCount[province] == controlGame.supplyCount[province]) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }

     /* Count the number of empty decks in test and control */
     testEmptySupplyDecks = 0;
     controlEmptySupplyDecks = 0;
     for (i = 0; i < 25; i++) {
          if (testGame.supplyCount[i] == 0) {
	          testEmptySupplyDecks++;
	     }
          if (controlGame.supplyCount[i] == 0) {
	          controlEmptySupplyDecks++;
	     }
     }

     printf("\tNum Empty Supply decks = %d, expected = %d\n", testEmptySupplyDecks, controlEmptySupplyDecks);
     if (testEmptySupplyDecks == controlEmptySupplyDecks) {
          printf("\tPASS\n\n");
          passCount++;
     }
     else {
          printf("\tFAIL\n\n");
          failCount++;
     }



     printf("ISGAMEOVER PASS COUNT:\t%d\n", passCount);
     printf("ISGAMEOVER FAIL COUNT:\t%d\n", failCount);
}