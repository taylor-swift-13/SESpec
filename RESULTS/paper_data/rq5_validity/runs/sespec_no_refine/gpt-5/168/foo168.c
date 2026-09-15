
/*@
  // no additional predicates or logic functions are needed
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (\result == 0)
          ||
          (0 <= \result <= arr_len - 1
           &&
           ((\result >= 1 && arr[\result - 1] > arr[\result])
             ||
            (\result <= arr_len - 2 && arr[\result] > arr[\result + 1])));
  ensures \result == 0 || (0 <= \result && \result <= arr_len - 1);
*/
int foo168(int * arr, int arr_len) {

		int ret = 0;
		int count = arr_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant arr_len == \at(arr_len, Pre);
              loop invariant arr == \at(arr, Pre);
              loop invariant 0 <= \at(arr_len, Pre) - 1 ==> (0 <= ret && ret <= count && count <= \at(arr_len, Pre) - 1);
              loop invariant !(0 <= \at(arr_len, Pre) - 1) ==> (ret == 0 && count == \at(arr_len, Pre) - 1);
              loop assigns ret, count, r;
            */
            while (ret <= count) {
			int r = ret + (count - ret) / 2;
			if (r < count
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				count = r - 1;
			}
		}
            
		return 0;
}
