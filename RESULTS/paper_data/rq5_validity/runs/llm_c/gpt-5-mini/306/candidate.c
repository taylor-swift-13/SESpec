#include <stdlib.h>

/*@
    logic integer lucas_spec(integer n) =
        n == 0 ? 2 :
        n == 1 ? 1 :
        lucas_spec(n-1) + lucas_spec(n-2);
*/

/*@
    requires n >= 1;
    assigns \nothing;
    ensures \result == lucas_spec(n);
*/
int findLucas(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
        int lucas_len = n + 1;
        /*@ assert lucas != \null && \valid(lucas + (0 .. n)); */
        lucas[0] = 2;
        lucas[1] = 1;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant \valid(lucas + (0 .. n));
            loop invariant lucas[0] == 2;
            loop invariant lucas[1] == 1;
            loop invariant \forall integer j; 2 <= j < i ==> lucas[j] == lucas[j-1] + lucas[j-2];
            loop assigns i, lucas[2 .. n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}
