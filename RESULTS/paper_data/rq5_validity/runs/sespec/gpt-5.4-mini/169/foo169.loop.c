
int foo169(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		
        /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (0 <= r <= arr_len);
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (-1 <= stop < arr_len);
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (stop + 1 >= r);
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (\forall integer k; 0 <= k < r ==> arr[k] == \at(arr[k], Pre));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (\forall integer k; stop < k < arr_len ==> arr[k] == \at(arr[k], Pre));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre));

          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (0 <= r <= arr_len && -1 <= stop < arr_len);
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((stop == \at(arr_len,Pre) - 1)&&(r == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= r <= arr_len));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((stop == \at(arr_len,Pre) - 1)&&(r == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= stop < arr_len));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((stop == \at(arr_len,Pre) - 1)&&(r == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre));
          loop assigns r, stop;
        */
        while (r <= stop) {
			int i = r + (stop - r) / 2;
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
            
		return 0;
}
