
/*@
  logic integer lucas_term(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    lucas_term(k - 1) + lucas_term(k - 2);
*/

#include <stdlib.h>

/*@
  requires n >= 1;
  assigns \nothing;
  ensures \result == lucas_term(n);
*/
int foo306(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
        int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        
            
        /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant lucas[0] == 2;
          loop invariant lucas[1] == 1;
          loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas_term(k);
          loop assigns i, lucas[0..n];
        */
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
            
        return lucas[n];
}
