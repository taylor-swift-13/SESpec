
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo14(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant 0 <= evenPairCount;
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns i, evenPairCount;
            */
            /*@
          loop invariant (!(i < arr_len)) ==> (0 <= evenPairCount);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, evenPairCount;
            */
            for (int i = 0; i < arr_len; i++) {
			
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant 0 <= evenPairCount;
              loop assigns i, evenPairCount;
              loop invariant evenPairCount >= 0;
            */
            for (int c = i + 1; c < arr_len; c++) {
				int odd = arr[i];
				int b = arr[c];
				int even = odd ^ b;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
            
		return evenPairCount;
}
