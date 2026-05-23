
#include <stddef.h>

/*@ 
  logic integer sp(int* a, integer p, integer q) =
    (((a[p] ^ a[q]) & 1) == 0) ? 1 : 0;
*/

/*@
  logic integer count_q_from(int* a, integer p, integer loq, integer hiq) =
    loq >= hiq ? 0 : count_q_from(a, p, loq, hiq - 1) + sp(a, p, hiq - 1);
*/

/*@
  logic integer count_p_lt(int* a, integer n, integer i) =
    i <= 0 ? 0 : count_p_lt(a, n, i - 1) + count_q_from(a, i - 1, i, n);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/

int foo164(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant \forall integer p,q; 0 <= p < i && p < q < arr_len ==> sp(arr,p,q) >= 0;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= c <= arr_len;
          loop assigns evenPairCount, c;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
