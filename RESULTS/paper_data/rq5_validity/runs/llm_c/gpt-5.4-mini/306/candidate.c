#include <stdlib.h>

/*@
    requires n >= 1;
    requires \valid((int *)malloc(sizeof(int) * (n + 1))); 
    assigns \nothing;
    ensures \result >= 1;
*/
int findLucas(int n);

int findLucas(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant \valid(lucas + (0 .. n));
            loop invariant lucas[0] == 2;
            loop invariant lucas[1] == 1;
            loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
            loop assigns i, lucas[2 .. n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}
