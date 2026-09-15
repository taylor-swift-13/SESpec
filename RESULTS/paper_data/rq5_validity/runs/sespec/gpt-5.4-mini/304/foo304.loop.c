
#include <stdlib.h>

/*@ logic integer pell_rec(integer k) =
      k <= 0 ? 0 :
      k == 1 ? 1 :
      (2 * pell_rec(k - 1) + pell_rec(k - 2)) % 1000000000;
*/

/*@ requires n >= 1; */
int foo304(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
        int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant pell[i - 1] == pell_rec(i - 1);
          loop invariant pell[i - 2] == pell_rec(i - 2);
          loop invariant \forall integer k; 0 <= k < i ==> pell[k] == pell_rec(k);
          loop assigns i, pell[0..n];
            */
            for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
            
        return pell[n];
}
