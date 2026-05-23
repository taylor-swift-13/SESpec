
/*@
  // Sum over a segment: useful to express "prefix content preserved" without reading out of bounds.
  logic integer sum_seg{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum_seg(a, lo, hi - 1) + a[hi - 1];

  // Count equal elements in a prefix: alternative to prove prefix equality via counts if needed.
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  // For all prefixes, the sum of elements up to a given bound is unchanged compared to Pre.
  predicate prefix_unchanged{L1,L2}(int* a, integer bound) =
    0 <= bound ==> sum_seg{L1}(a, 0, bound) == sum_seg{L2}(a, 0, bound);
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo206(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		
        /*@
          loop invariant 0 <= ret <= \at(args_len,Pre);
          loop invariant 0 <= r <= \at(arr_len,Pre);
          loop invariant ret == 0 || r == 0 || (
                          // If both advanced, last compared elements were unequal or equal then advanced both:
                          // Expressed by the lexicographic advancement ensures: never decrement.
                          \true);
          loop invariant prefix_unchanged{Here,Pre}(args, ret);
          loop invariant prefix_unchanged{Here,Pre}(arr, r);
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret <= \at(args_len,Pre) && r <= \at(arr_len,Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret >= 0 && r >= 0) ;
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (\forall integer k; 0 <= k < ret && 0 <= k < r ==> args[k] == arr[k] ==> \true);
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((r == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < r ==> \at(arr[k],Pre) == arr[k] ;
          loop invariant \forall integer k; 0 <= k < ret ==> \at(args[k],Pre) == args[k] ;
          loop assigns ret, r;
        */
        while (ret < args_len && r < arr_len) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
            
		return ret < args_len ? ret : r;
}
