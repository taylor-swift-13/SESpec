
#include <stdlib.h>

/*@ logic integer foo287_seq_val(integer n) =
      n <= 0 ? 0 : (n == 1 ? 1 : foo287_seq_val(n - 1) + 2 * foo287_seq_val(n - 2)); */
/*@
  assigns \nothing;
  ensures \result == foo287_seq_val(c);
*/
int foo287(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= p <= c + 1;
          loop invariant j_len == c + 1;
          loop invariant \valid(j + (0..j_len-1));
          loop invariant 0 <= 0 < j_len && 0 <= 1 < j_len;
          loop invariant j[0] == 0;
          loop invariant j[1] == 1;
          loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k-1] + 2 * j[k-2];
          loop assigns p, j[..];
            */
            for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
            
		return j[c];
}
