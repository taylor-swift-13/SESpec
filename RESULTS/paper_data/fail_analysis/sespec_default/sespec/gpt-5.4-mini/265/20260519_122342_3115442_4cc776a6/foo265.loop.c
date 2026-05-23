
/*@ 
  logic integer odd_prefix_count(int *ints, integer lo, integer hi) =
    lo >= hi ? 0 :
    odd_prefix_count(ints, lo, hi - 1) + ((ints[hi - 1] % 2) != 0 ? 1 : 0);
*/

int foo265(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index < \at(array,Pre)) ==> (0 <= start <= index + 1);
          loop invariant (index < \at(array,Pre)) ==> (0 <= start);
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k], Pre);
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
