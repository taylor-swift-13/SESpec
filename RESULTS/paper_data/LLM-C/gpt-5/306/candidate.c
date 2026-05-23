#include <stdlib.h>

/*@ axiomatic LucasAxioms {
    logic integer Lucas(integer n);

    axiom Lucas_base0: Lucas(0) == 2;
    axiom Lucas_base1: Lucas(1) == 1;
    axiom Lucas_rec: \forall integer k; k >= 2 ==> Lucas(k) == Lucas(k-1) + Lucas(k-2);
} */

int findLucas(int n);

/*@ 
  requires n >= 1;
  ensures \result == Lucas(n);
*/
int findLucas(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
/*@ assert lucas != \null; */
/*@ assert \valid(lucas + (0 .. n)); */
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        /*@ 
          loop invariant 2 <= i <= n+1;
          loop invariant \valid(lucas + (0 .. n));
          loop invariant lucas[0] == 2 && lucas[1] == 1;
          loop invariant \forall integer k; 0 <= k < i ==> lucas[k] == Lucas(k);
          loop assigns i, *(lucas + (2 .. n));
          loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}
