/*-James Todd
 *-toddjam
 *-CS_362_400
 *-Assignment 3
 *-unittest2.c
 *- Unit test for getCost()
 *-10/22/17*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Card costs from http://wiki.dominionstrategy.com/

//int acting as a boolean to determine if all tests have passed at the end of test code
int allTestsPassed = 1;

/*Compares expected integer value with actual integer value,
 * printing failure if not equal, passed if equal, and printing their values.*/
void myAssert(int expected, int actual){
	//assert failure
	if(expected != actual){
		printf("TEST FAILED: expected = %d, actual = %d.\n", expected, actual);
		allTestsPassed = 0;
	}else{
		//assert pass
		printf("TEST PASSED: expected = %d, actual = %d.\n", expected, actual);
	}
}

int main(){
	printf("TESTING getCost()  -- unittest2.c -- :\n\n");
	//test 'curse'
	printf("TESTING the cost of 'curse', expected value 0.\n");
	myAssert(0, getCost(curse));
	//test 'estate'
	printf("TESTING the cost of 'estate', expected value 2.\n");
	myAssert(2, getCost(estate));
	//test 'duchy'
	printf("TESTING the cost of 'duchy', expected value 5.\n");
	myAssert(5, getCost(duchy));
	printf("TESTING the cost of 'province', expected value 8.\n");
	myAssert(8, getCost(province));
	//test 'copper'
	printf("TESTING the cost of 'copper', expected value 0.\n");
	myAssert(0, getCost(copper));
	//test 'silver'
	printf("TESTING the cost of 'silver', expected value 3.\n");
	myAssert(3, getCost(silver));
	//test 'gold'
	printf("TESTING the cost of 'gold', expected value 6.\n");
	myAssert(6, getCost(gold));
	//test 'adventurer'
	printf("TESTING the cost of 'adventurer', expected value 6.\n");
	myAssert(6, getCost(adventurer));
	//test 'council_room'
	printf("TESTING the cost of 'council_room', expected value 5.\n");
	myAssert(5, getCost(council_room));
	//test 'feast'
	printf("TESTING the cost of 'feast', expected value 4.\n");
	myAssert(4, getCost(feast));
	//test 'gardens'
	printf("TESTING the cost of 'gardens', expected value 4.\n");
	myAssert(4, getCost(gardens));
	//test 'mine'
	printf("TESTING the cost of 'mine', expected value 5.\n");
	myAssert(5, getCost(mine));
	//test 'remodel'
	printf("TESTING the cost of 'remodel', expected value 4.\n");
	myAssert(4, getCost(remodel));
	//test 'smithy'
	printf("TESTING the cost of 'smithy', expected value 4.\n");
	myAssert(4, getCost(smithy));
	//test 'village'
	printf("TESTING the cost of 'village', expected value 3.\n");
	myAssert(3, getCost(village));
	//test 'baron'
	printf("TESTING the cost of 'baron', expected value 4.\n");
	myAssert(4, getCost(baron));
	//test 'great_hall'
	printf("TESTING the cost of 'great_hall', expected value 3.\n");
	myAssert(3, getCost(great_hall));
	//test 'minion'
	printf("TESTING the cost of 'minion', expected value 5.\n");
	myAssert(5, getCost(minion));
	//test 'steward'
	printf("TESTING the cost of 'steward', expected value 3.\n");
	myAssert(3, getCost(steward));
	//test 'tribute'
	printf("TESTING the cost of 'tribute', expected value 5.\n");
	myAssert(5, getCost(tribute));
	//test 'ambassador'
	printf("TESTING the cost of 'ambassador', expected value 3.\n");
	myAssert(3, getCost(ambassador));
	//test 'cutpurse'
	printf("TESTING the cost of 'cutpurse', expected value 4.\n");
	myAssert(4, getCost(cutpurse));
	//test 'embargo'
	printf("TESTING the cost of 'embargo', expected value 2.\n");
	myAssert(2, getCost(embargo));
	//test 'outpost'
	printf("TESTING the cost of 'outpost', expected value 5.\n");
	myAssert(5, getCost(outpost));
	//test 'salvager'
	printf("TESTING the cost of 'salvager', expected value 4.\n");
	myAssert(4, getCost(salvager));
	//test 'sea_hag'
	printf("TESTING the cost of 'sea_hag', expected value 4.\n");
	myAssert(4, getCost(sea_hag));
	//test 'treasure_map'
	printf("TESTING the cost of 'treasure_map', expected value 4.\n");
	myAssert(4, getCost(treasure_map));
	//test invalid input
	printf("TESTING invalid card number of -1000, expected value -1.\n");
	myAssert(-1, getCost(-1000));
	if(allTestsPassed){
		printf("TEST SUCCESSFULLY COMPLETED.\n");
	}else{
    printf("TEST HAS FAILED.\n\n");
  }

	return 0;
}
