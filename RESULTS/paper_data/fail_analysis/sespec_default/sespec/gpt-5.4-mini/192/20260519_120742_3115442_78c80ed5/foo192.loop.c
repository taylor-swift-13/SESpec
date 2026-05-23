
#include <stdlib.h>

/*@ logic integer seq_w(integer k) =
      k == 0 ? 1 :
      k == 1 ? 0 :
      seq_w(k - 2) + 2 * seq_C(k - 1);

    logic integer seq_C(integer k) =
      k == 0 ? 0 :
      k == 1 ? 1 :
      seq_w(k - 1) + seq_C(k - 2);
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
		
            
        /*@
          loop invariant 2 <= index <= count + 1;
          loop invariant \forall integer k; 0 <= k < index ==> 0 <= k < w_len;
          loop invariant \forall integer k; 0 <= k < index ==> 0 <= k < C_len;
          loop invariant \forall integer k; 0 <= k < index ==> w[k] == seq_w(k);
          loop invariant \forall integer k; 0 <= k < index ==> C[k] == seq_C(k);
          loop assigns index, w[0..count], C[0..count];
            */
            for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
            
		return w[count];
}
