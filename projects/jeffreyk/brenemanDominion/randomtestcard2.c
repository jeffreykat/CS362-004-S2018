#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"

int mineTest(){
   int result, expected = 3, s = 99;
   int numPlayers = (rand() % 2);
   struct gameState testgame;
   int k[10] = {adventurer, feast, mine, village, baron, gardens, embargo, tribute, minion, council_room};
   memset(&testgame, 23, sizeof(struct gameState));
   initializeGame(numPlayers, k, s, &testgame);

   int player1 = (rand() % 2);
   int pos = rand() % (testgame.handCount[player1]);
   cardEffect(mine, 1, 1, 1, &testgame, pos, 0);
   result = testgame.handCount[player1];

   if(result == expected)
      return 0;
   return 1;
}

int main () {
   srand(time(NULL));
   int test = 0;
   int i;
   for(i = 0; i < 250; i++){
      test += mineTest();
   }
   printf("FAILS: %d\n", test);
   return 0; 
}

