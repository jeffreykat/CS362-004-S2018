#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"

int smithyTest(){
   int result, expected = 3, s = 99;
   int numPlayers = (rand() % 2) + 1;
   struct gameState testgame;
   int k[10] = {adventurer, feast, mine, village, baron, gardens, embargo, tribute, minion, council_room};
   memset(&testgame, '\0', sizeof(struct gameState));
   initializeGame(numPlayers, k, s, &testgame);

   int player1 = (rand() % 2) + 1;
   int pos = (rand() % 9) + 1;
   cardEffect(smithy, 0, 0, 0, &testgame, pos, 0);
   result = testgame.handCount[player1];
   if(result == expected)
      return 0;
   return 1;
}

int main () {
   srand(time(NULL));
   int test = 0;
   int i;
   for(i = 0; i < 220; i++){
      test += smithyTest();
   }
   printf("FAILS: %d\n", test);
   return 0; 
}

