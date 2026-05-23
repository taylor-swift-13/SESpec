
int foo233(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		
            
        /*@
          loop invariant result >= arr[0];
          loop invariant num <= arr[0];
          loop invariant \forall integer i; 0 <= i < n ==> arr[i] <= result;
          loop invariant \forall integer i; 0 <= i < n ==> num <= arr[i];
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
          loop assigns n, result, num;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
            
		return result - num;
}
