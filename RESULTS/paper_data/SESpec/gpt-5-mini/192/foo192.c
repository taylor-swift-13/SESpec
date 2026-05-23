
/*@
  logic integer w_seq(integer k) =
    k == 0 ? 1
    : k == 1 ? 0
    : w_seq(k-2) + 2 * C_seq(k-1);

  logic integer C_seq(integer k) =
    k == 0 ? 0
    : k == 1 ? 1
    : w_seq(k-1) + C_seq(k-2);
*/

#include <stdlib.h>

/*@
  assigns \nothing;
  ensures \result == w_seq(count);
*/
int foo192(int count) {

		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= index <= count + 1;
          loop invariant \forall integer k; 0 <= k < index ==> w[k] == w_seq(k);
          loop invariant \forall integer k; 0 <= k < index ==> C[k] == C_seq(k);
          loop assigns index, w[..], C[..];
            */
            for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
            
		return w[count];
}
