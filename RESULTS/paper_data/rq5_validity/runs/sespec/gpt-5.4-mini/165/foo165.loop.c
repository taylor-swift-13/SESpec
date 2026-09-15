
#include <stddef.h>

 /*@
  requires arr_len >= 0;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/

int foo165(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i && i <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant evenPairCount <= i * arr_len;
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] && arr[k] <= 100;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant i == arr_len ==> evenPairCount >= 0;
          loop assigns i, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i && i < arr_len;
          loop invariant i + 1 <= c && c <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant evenPairCount <= i * arr_len + c;
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] && arr[k] <= 100;
          loop assigns c, evenPairCount;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int pair = arr[i];
				int odd = arr[c];
				int even = pair ^ odd;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
