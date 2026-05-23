
        /*@
        */
        
int foo173(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count >= 0;
          loop invariant (p < 0) || count <= p;
          loop invariant result >= 0;
          loop invariant tmp >= 0;
          loop invariant result + tmp == count;
          loop assigns count, result, tmp;
            */
            for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
            
		return -1;
}
