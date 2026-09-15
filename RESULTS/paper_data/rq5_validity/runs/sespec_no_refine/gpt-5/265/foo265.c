
/*@
  // count of odd elements in a[lo..hi-1]
  logic integer cntodd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cntodd(a, lo, hi - 1) + ((a[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@
  requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires ints_len > 0;
  requires ints_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo265(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < index ==> ints[k] == \at(ints[k], Pre) ;
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
