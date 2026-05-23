
#include <stdlib.h>

/*@ logic integer pow2(integer n) =
      n <= 0 ? 1 : 2 * pow2(n - 1); */

/*@ logic integer step(int *a, integer i) = 0; */

/*@
  requires j >= 1;
  ensures j == 0 ==> \result == 0;
  ensures j == 1 ==> \result == 1;
*/
int foo288(int j) {

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
		
        /*@
          loop invariant 2 <= p;
          loop invariant ret[0] == 0;
          loop invariant ret[1] == 1;
          loop invariant \forall integer k; 0 <= k < 2 ==> ret[k] == (k==0 ? 0 : 1);
          loop invariant \exists integer k; 0 <= k < p && ret[k] == ret[p-1];
          loop invariant (p <= j) ==> (0 <= p < ret_len && step(ret, p-1) == 0);
          loop assigns p, ret[0..j];
        */
        for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
            
		return ret[j];
}
