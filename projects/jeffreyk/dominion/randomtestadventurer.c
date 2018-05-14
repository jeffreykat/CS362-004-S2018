#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"

int adventurerTest(){
   //MAX_HAND and MAX_DECK are 500
   //MAX_PLAYERS is 4
   int r, i, j, result, expected;
   int z = 0;
   int numPlayers = 2;
   int player1 = 0;
   int player2 = 1;
   int seed = 99;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
   int drawnTreasure = 0;
   struct gameState G;
   memset(&G, 23, sizeof(struct gameState));
   r = initializeGame(numPlayers, k, seed, &G);
   
   G.deckCount[player1] = 10;
   int temphand[MAX_HAND];
   int cards[10] = {adventurer, gardens, smithy, gold, silver, copper, mine, feast, embargo, minion};
   for(int d = 0; d < 10; d++){
      G.deck[player1][d] = cards[rand() % 10];
   }
   int treasure1 = -1;
   int treasure2 = -1;
   for(int c = 9; c > -1; c--){
      if(G.deck[player1][c] == copper || G.deck[player1][c] == gold || G.deck[player1][c] == silver){
	 if(treasure1 == -1){
	    treasure1 = c;
	 }
	 else if(treasure2 == -1 && treasure1 != -1){
	    treasure2 = c;
	 }
	 else{
	    return 1;
	 }
      }
   }
   //adventurerAction(drawnTreasure, &G, player1, cardDrawn, player2, temphand, z);
   cardEffect(adventurer, 0, 0, z, &G, cardDrawn, 0);
   if(treasure2 <= 0){
      expected = 0;
   }
   else{
      expected = treasure2 - 1;
   }
   result = G.handCount[player1];
   return assertInt(result, expected);
}

int main() {
   srand(time(NULL));
   int test = 0;
   int i;
   for(i = 0; i < 298; i++){
      test += adventurerTest();
   }
   printf("FAILS: %d\n", test);
   return 0; 
}

