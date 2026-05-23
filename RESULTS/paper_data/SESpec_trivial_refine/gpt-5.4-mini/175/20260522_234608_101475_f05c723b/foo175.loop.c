
        /*@
        predicate sorted{L}(int *arr, integer n) =
          \forall integer x, y; 0 <= x <= y < n ==> arr[x] <= arr[y];
        */
        
int foo175(int * arr, int arr_len, int Array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop assigns i, hi, end;
            */
            while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == Array) {
				if (end == arr_len - 1
						|| arr[end + 1] != Array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < Array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
