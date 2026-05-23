
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr_len >= 0;
  assigns \nothing;
  ensures \result >= 0 ==> (\result < arr_len && arr[\result] == Array);
  ensures \result >= 0 ==> (\result == arr_len - 1 || arr[\result + 1] != Array);
  ensures \result >= 0 ==> (\exists integer k; 0 <= k <= \result && arr[k] == Array);
  ensures -1 <= \result < arr_len;
*/
int foo175(int * arr, int arr_len, int Array) {

	int i = 0;
	int hi = arr_len - 1;
	int end = 0;
	
	/*@
	  loop invariant 0 <= \at(arr_len,Pre) ==> 0 <= i && i <= \at(arr_len,Pre);
	  loop invariant 0 <= \at(arr_len,Pre) ==> -1 <= hi && hi < \at(arr_len,Pre);
	  loop invariant 0 <= \at(arr_len,Pre) ==> i <= hi + 1;
	  loop invariant Array == \at(Array,Pre);
	  loop invariant arr_len == \at(arr_len,Pre);
	  loop invariant arr == \at(arr,Pre);
	  loop invariant 0 <= \at(arr_len,Pre) ==>
	    (\forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre));
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
