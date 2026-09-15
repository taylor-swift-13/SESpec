#include <string.h>

/*@
    requires jewels != \null && stones != \null;
    requires \valid_read(jewels + (0 .. \strlen(jewels)));
    requires \valid_read(stones + (0 .. \strlen(stones)));
    assigns \nothing;
    ensures 0 <= \result <= (int)\strlen(stones);
    ensures \result == \sum integer idx; 0 <= idx < (int)\strlen(stones); 
                ((\exists integer j; 0 <= j < (int)\strlen(jewels) && jewels[j] == stones[idx]) ? 1 : 0);
*/
int numJewelsInStones(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = (int)strlen(jewels), stonesLength = (int)strlen(stones);
        /*@
            loop invariant 0 <= i <= stonesLength;
            loop invariant 0 <= jewelsCount <= stonesLength;
            loop invariant jewelsCount == \sum integer k; 0 <= k < i; 
                                ((\exists integer j; 0 <= j < jewelsLength && jewels[j] == stones[k]) ? 1 : 0);
            loop assigns i, jewelsCount;
            loop variant stonesLength - i;
        */
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            /*@
                loop invariant 0 <= j <= jewelsLength;
                loop invariant (\forall integer k; 0 <= k < j ==> jewels[k] != stones[i]);
                loop assigns j, jewelsCount;
                loop variant jewelsLength - j;
            */
            for (int j = 0; j < jewelsLength; j++) {
                char jewel = jewels[j];
                if (stone == jewel) {
                    jewelsCount++;
                    break;
                }
            }
        }
        return jewelsCount;
}
