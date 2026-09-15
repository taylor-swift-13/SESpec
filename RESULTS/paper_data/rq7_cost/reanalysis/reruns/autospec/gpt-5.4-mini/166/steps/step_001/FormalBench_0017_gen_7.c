#include <stddef.h>

int findEvenPair(int * a, int a_len, int n);

int findEvenPair(int * a, int a_len, int n) {

        if (a == NULL) {
            return -1;
        }
        if (a_len == 1) {
            return 0;
        }

        int evenPairCount = 0;
        for (int i = 0; i < a_len; i++) {
            /*@
            loop invariant 0 <= i <= a_len;
            loop invariant evenPairCount >= 0;
            loop invariant evenPairCount <= i * a_len;
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < a_len ==> ((a[p] ^ a[q]) & 1) == 0 ==> evenPairCount >= 1;
            loop assigns i;
            loop assigns evenPairCount;
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
