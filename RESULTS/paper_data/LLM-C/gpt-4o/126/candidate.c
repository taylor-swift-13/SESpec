#include <string.h>

/*@
    requires \valid_read(jewels) && \valid_read(stones);
    requires \valid_read(jewels+(0..strlen(jewels)-1));
    requires \valid_read(stones+(0..strlen(stones)-1));
    ensures \result >= 0;
    assigns \nothing;
*/
int numJewelsInStones(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        /*@
            loop invariant 0 <= i <= stonesLength;
            loop invariant jewelsCount >= 0;
            loop assigns i, jewelsCount;
        */
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            /*@
                loop invariant 0 <= j <= jewelsLength;
                loop assigns j;
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
