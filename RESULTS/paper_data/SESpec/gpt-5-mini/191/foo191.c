
#include <stdlib.h>

/*@
  logic integer W_seq(integer n) =
    n == 0 ? 1
    : n == 1 ? 0
    : W_seq(n-2) + 2 * C_seq(n-1);

  logic integer C_seq(integer n) =
    n == 0 ? 0
    : n == 1 ? 1
    : W_seq(n-1) + C_seq(n-2);
*/

/*@
  requires count >= 0;
  assigns \nothing;
  ensures \result == W_seq(count);
*/
int foo191(int count) {

		int *W = (int *)malloc(sizeof(int) * (count + 1));
int W_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= w <= count + 1 || (w == 2 && count < 2);
          loop invariant \forall integer k; 0 <= k < w ==> W[k] == W_seq(k);
          loop invariant \forall integer k; 0 <= k < w ==> C[k] == C_seq(k);
          loop assigns w, W[..], C[..];
            */
            for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
            
		return W[count];
}
