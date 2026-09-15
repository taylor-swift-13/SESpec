
#include <stdlib.h>

/*@
  assigns \nothing;
  ensures \result == seq(c);
*/
int foo291(int c) {

        int *j = (int *)malloc(sizeof(int) * (c + 1));
        int j_len = c + 1;
        j[0] = 2;
        j[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= p <= c + 1;
              loop invariant j_len == c + 1;
              loop invariant \valid(j + (0..j_len-1));
              loop invariant j[0] == 2 && j[1] == 1;
              loop invariant \forall integer k; 0 <= k < p ==> j[k] == seq(k);
              loop assigns p, j[..];
            */
            for (int p = 2; p <= c; p++) {
                        j[p] = j[p - 1]
                                        + 2 * j[p - 2];
                }
            
                return j[c];
}
