#include <string.h>

/*@ 
    requires \valid_read(jewels + (0 .. strlen(jewels)));
    requires \valid_read(stones + (0 .. strlen(stones)));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (int)strlen(stones);
*/
int numJewelsInStones(const char * jewels, const char * stones);

 /*@ 
    requires \valid_read(jewels + (0 .. strlen(jewels)));
    requires \valid_read(stones + (0 .. strlen(stones)));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (int)strlen(stones);
*/
int numJewelsInStones(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        /*@
        loop invariant 0 <= i <= stonesLength;
        loop invariant 0 <= jewelsCount <= i;
        loop assigns i, jewelsCount, j, stone, jewel;
        loop variant stonesLength - i;
        */
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i);
            /*@
            loop invariant 0 <= j <= jewelsLength;
            loop invariant 0 <= jewelsCount <= i + 1;
            loop assigns j, jewelsCount, jewel;
            loop variant jewelsLength - j;
            */
            for (int j = 0; j < jewelsLength; j++) {
                char jewel = jewels[j);
                if (stone == jewel) {
                    jewelsCount++;
                    break;
                }
            }
        }
        return jewelsCount;
}
