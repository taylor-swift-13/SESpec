
/*@
  logic integer count_odds(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odds(a, lo, hi - 1) + (a[hi-1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer last_odd_at_odd_position(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi-1] % 2 != 0 && (count_odds(a, lo, hi) % 2 == 1) ? a[hi-1] : last_odd_at_odd_position(a, lo, hi - 1));
*/

/*@
  requires \valid_read(array + (0 .. array_len-1));
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  requires Array == \at(array_len,Pre);
  assigns \nothing;   
  ensures \forall integer k; 0 <= k < \at(array_len,Pre) ==> array[k] == \at(array[k],Pre);
*/
int foo266(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
            
        /*@
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < \at(array_len,Pre) ==> array[k] == \at(array[k],Pre);
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
