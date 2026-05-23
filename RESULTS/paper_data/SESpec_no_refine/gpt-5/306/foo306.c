
#include <stdlib.h>

/*@ logic integer lucas_val(integer k) =
      k <= 0 ? 2 :
      k == 1 ? 1 :
      lucas_val(k - 1) + lucas_val(k - 2);
*/
/*@
  assigns \nothing;
  ensures n >= 1 ==> \result == lucas_val(n);
*/
int foo306(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
        int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= i <= n+1;
              loop invariant \valid(lucas + (0 .. n));
              loop invariant lucas_len == n + 1;
              loop invariant lucas[0] == 2 && lucas[1] == 1;
              loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k-1] + lucas[k-2];
              loop assigns i, lucas[..];
            */
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
            
        return lucas[n];
}
