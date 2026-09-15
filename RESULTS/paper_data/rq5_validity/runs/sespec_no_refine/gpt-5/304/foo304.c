
#include <stdlib.h>

/*@ logic integer pell_val(integer k) =
      k <= 0 ? 0 : (k == 1 ? 1 : (2 * pell_val(k - 1) + pell_val(k - 2)) % 1000000000); */
/*@
  assigns \nothing;
  ensures \result == pell_val(n);
*/
int foo304(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
        int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= i <= n+1;
              loop invariant pell_len == n + 1;
              loop invariant \valid(pell + (0 .. pell_len-1));
              loop invariant pell[0] == 0;
              loop invariant pell[1] == 1;
              loop invariant \forall integer k; 0 <= k < i ==> 
                               pell[k] == (k == 0 ? 0 : (k == 1 ? 1 : (2 * pell[k - 1] + pell[k - 2]) % 1000000000));
              loop invariant \forall integer k; i <= k < pell_len ==> \true;
              loop assigns i, pell[..];
            */
            for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
            
        return pell[n];
}
