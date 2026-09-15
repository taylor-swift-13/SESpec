
/*@
  logic integer count_odds(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odds(a, lo, hi - 1) + ((a[hi-1] % 2 != 0) ? 1 : 0);

  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ( a[hi-1] % 2 != 0 ? a[hi-1] : last_odd(a, lo, hi-1) );
*/

/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  requires \valid_read(array + (0 .. \at(array_len,Pre) - 1));
  assigns \nothing;
  ensures array == \at(array,Pre);
  ensures array_len == \at(array_len,Pre);
  ensures Array == \at(Array,Pre);
*/
int foo143_c266(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
            
        /*@
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
          loop assigns index, ret, start;
        */
            for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
            
		return ret;
}
