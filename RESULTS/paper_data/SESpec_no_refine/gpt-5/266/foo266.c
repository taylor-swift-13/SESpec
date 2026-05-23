
/*@
  logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);

  // Value of the last odd element in a[0..idx-1], or 0 if none
  logic integer last_odd_val(int* a, integer idx) =
    idx <= 0 ? 0 :
    (a[idx-1] % 2 != 0 ? a[idx-1] : last_odd_val(a, idx-1));
*/

/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo266(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant (index < \at(Array,Pre)) ==> ((start == 0) || (start > 0));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < Array ==> array[k] == \at(array[k],Pre) ;
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
