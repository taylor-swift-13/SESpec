#include <stddef.h>

/*@
    requires a == \null || \valid(a + (0 .. a_len-1));
    assigns \nothing;
    behavior null_array:
        assumes a == \null;
        ensures \result == -1;
    behavior short_array:
        assumes a != \null && a_len <= 1;
        ensures \result == 0;
    behavior general:
        assumes a != \null && a_len > 1;
        ensures \result >= 0;
        ensures \result == (
            \sum integer p; 0 <= p < a_len;
                \sum integer q; p < q < a_len;
                    (((a[p] ^ a[q]) & 1) == 0 ? 1 : 0)
        );
    complete behaviors null_array, short_array, general;
    disjoint behaviors null_array, short_array, general;
*/
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
            loop invariant evenPairCount == (
                \sum integer p; 0 <= p < i;
                    \sum integer q; p < q < a_len;
                        (((a[p] ^ a[q]) & 1) == 0 ? 1 : 0)
            );
            loop assigns i, evenPairCount;
            loop variant a_len - i;
        */
        for (int i = 0; i < a_len; i++) {
            /*@
                loop invariant i+1 <= j <= a_len;
                loop invariant evenPairCount == (
                    \sum integer p; 0 <= p < i;
                        \sum integer q; p < q < a_len;
                            (((a[p] ^ a[q]) & 1) == 0 ? 1 : 0)
                ) + (
                    \sum integer k; i+1 <= k < j;
                        (((a[i] ^ a[k]) & 1) == 0 ? 1 : 0)
                );
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
