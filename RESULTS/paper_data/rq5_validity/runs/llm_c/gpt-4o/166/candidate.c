#include <stddef.h>

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0..a_len-1));
    ensures \result >= 0;
    ensures \result == -1 ==> a == \null;
    ensures \result == 0 ==> a_len <= 1 || (\forall integer i, j; 0 <= i < j < a_len ==> ((a[i] ^ a[j]) & 1) != 0);
    assigns \nothing;
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
            loop assigns i, evenPairCount;
            loop invariant \forall integer k, l; 0 <= k < l < i ==> ((a[k] ^ a[l]) & 1) != 0 || evenPairCount > 0;
        */
        for (int i = 0; i < a_len; i++) {
            /*@
                loop invariant i + 1 <= j <= a_len;
                loop invariant evenPairCount >= 0;
                loop assigns j, evenPairCount;
                loop invariant \forall integer k; i + 1 <= k < j ==> ((a[i] ^ a[k]) & 1) != 0 || evenPairCount > 0;
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
