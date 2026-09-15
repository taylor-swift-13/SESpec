
/*@
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
		
        /*@ 
          loop invariant 0 <= i <= arr_len;
          loop invariant 0 <= evenPairCount;
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant evenPairCount <= (i >= 1 ? (i * (i - 1)) / 2 : 0);
          loop assigns i, c, pair, odd, even, evenPairCount;
        */
        for (int i = 0; i < arr_len; i++) {
			
            /*@
              loop invariant i + 1 <= c;
              loop invariant c <= arr_len;
              loop invariant 0 <= evenPairCount;
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
              loop assigns i, evenPairCount, c;
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
