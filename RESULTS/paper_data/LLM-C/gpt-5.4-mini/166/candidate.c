#include <stddef.h>

/*@
    requires a == \null || \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures a == \null ==> \result == -1;
    ensures a != \null && a_len == 1 ==> \result == 0;
    ensures a != \null && a_len > 1 ==> \result >= 0;
*/
int findEvenPair(int * a, int a_len, int n);

int findEvenPair(int * a, int a_len, int n) {

        if (a == NULL) {
            return -1;
        }
        if (a_len == 1) {
            return 0;
        }

        int evenPairCount = 0;
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant evenPairCount >= 0;
            loop assigns i, evenPairCount, j;
            loop variant a_len - i;
        */
        for (int i = 0; i < a_len; i++) {
            /*@
                loop invariant i + 1 <= j <= a_len;
                loop invariant evenPairCount >= 0;
                loop assigns j, evenPairCount;
                loop variant a_len - j;
            */
            for (int j = i + 1; j < a_len; j++) {
                int x = a[i];
                int y = a[j];
                int v = x ^ y;
                if ((v & 1) == 0) {
                    evenPairCount++;
                }
            }
        }
        return evenPairCount;
}
