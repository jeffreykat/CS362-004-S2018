#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include "rngs.h"

void smithyTest(){
   int i, result, s = 99, numPlayers = 2;
   struct gameState testgame;
   int k[10] = {adventurer, feast, mine, village, baron, gardens, embargo, tribute, minion, council_room};
   memset(&testgame, 23, sizeof(struct gameState));
   initializeGame(numPlayers, k, s, &testgame);

   int player1 = 0;
   int testresult, expectedresult;
   for(i = 0; i < testgame[player1]; i++){
      printf("");
   }
   smithyAction(player1, &testgame, testgame.handCount[player1][i]);
   for(i = 0; i < testgame.handCount[player1]; i++){
      printf("");
   }
}

int main () {
   smithyTest();
   return 0; 
}

