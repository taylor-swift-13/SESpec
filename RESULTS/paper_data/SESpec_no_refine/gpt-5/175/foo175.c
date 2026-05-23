
/*@
  // no additional predicates or logic functions needed
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (-1 <= \result < arr_len);
  ensures (\result == -1) <==> (\forall integer k; 0 <= k < arr_len ==> arr[k] != Array);
  ensures (\result != -1) ==> (arr[\result] == Array &&
                               (\result == arr_len - 1 || arr[\result + 1] != Array) &&
                               (\forall integer k; 0 <= k < arr_len && k > \result ==> arr[k] != Array));
  ensures (\result != -1) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == Array);
  ensures (\result != -1) ==> (\forall integer k; 0 <= k < arr_len && arr[k] == Array ==> k <= \result);
  ensures \result == (\exists integer k0; 0 <= k0 < arr_len && arr[k0] == Array ? 
                      (\max \lambda integer k; 0 <= k < arr_len && arr[k] == Array ? k : -1) : -1);
*/
int foo175(int * arr, int arr_len, int Array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= arr_len ==> 0 <= i <= arr_len;
          loop invariant -1 <= hi < arr_len;
          loop invariant i <= hi + 1;
          loop invariant 0 <= arr_len ==> 0 <= end < arr_len || (i > hi);
          loop invariant Array == Array;
          loop invariant arr_len == arr_len;
          loop invariant arr == arr;
          loop assigns end, i, hi;
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
