
/*@
  logic integer odd_count(int* array, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(array, lo, hi - 1) + ((array[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@
  logic integer selected_ret(int* array, integer lo, integer hi) =
    lo >= hi ? 0
             : (((odd_count(array, lo, hi - 1) + (((array[hi - 1] % 2 != 0)) ? 1 : 0)) % 2 != 0 && (array[hi - 1] % 2 != 0))
                 ? array[hi - 1]
                 : selected_ret(array, lo, hi - 1));
*/

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        
int foo266(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
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
