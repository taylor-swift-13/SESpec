
/*@
  logic integer odds_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odds_count(a, lo, hi - 1) + ((a[hi-1] % 2 != 0) ? 1 : 0);

  logic integer last_odd_at_odd_occurrence(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ( a[hi-1] % 2 != 0
                   ? ( (odds_count(a, lo, hi) % 2 == 1) ? a[hi-1]
                                                       : last_odd_at_odd_occurrence(a, lo, hi-1) )
                   : last_odd_at_odd_occurrence(a, lo, hi-1) );
*/

/*@
  requires \valid_read(ints + (0 .. \at(ints_len,Pre)-1));
  requires \at(ints_len,Pre) > 0 && \at(ints_len,Pre) < 100;
  requires array >= 0 && array <= \at(ints_len,Pre);
*/
int foo142_c265(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= array;
          loop invariant (index < \at(array,Pre)) ==> (start == odds_count(ints, 0, index));
          loop invariant (index < \at(array,Pre)) ==> (((start == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre))) || (ret == last_odd_at_odd_occurrence(ints, 0, index)));
          loop invariant (index < \at(array,Pre)) ==> (start >= 0);
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < \at(ints_len,Pre) ==> ints[k] == \at(ints[k],Pre);
          loop assigns index, ret, start;
            */
            for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
            
		return ret;
}
