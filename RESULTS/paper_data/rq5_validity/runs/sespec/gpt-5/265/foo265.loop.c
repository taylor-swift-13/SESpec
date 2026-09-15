
/*@
  logic integer cntodd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cntodd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);

  logic integer last_odd_idx(int* a, integer lo, integer hi) =
    lo >= hi ? -1
             : (a[hi - 1] % 2 != 0 ? (hi - 1) : last_odd_idx(a, lo, hi - 1));
*/

/*@ requires array >= 0;
    requires \valid_read(ints + (0..ints_len-1));
    requires 0 <= array <= ints_len;
    ensures \true;
*/
int foo265(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= array;
          loop invariant 0 <= start <= index;
          loop invariant start == cntodd(ints, 0, index);
          loop invariant (last_odd_idx(ints, 0, index) == -1) ==> ret == 0;
          loop invariant (last_odd_idx(ints, 0, index) != -1) ==> (0 <= last_odd_idx(ints, 0, index) < index);
          loop invariant \forall integer k; 0 <= k < index ==> (ints[k] == \at(ints[k], Pre));
          loop invariant (index == array) ==> (start == cntodd(ints, 0, array));
          loop invariant (index < \at(array,Pre)) ==> (0 <= index < array);
          loop invariant (index < \at(array,Pre)) ==> (start == 0 ==> ret == 0);
          loop invariant (index < \at(array,Pre)) ==> (start >= 1 ==> last_odd_idx(ints,0,index) != -1);
          loop invariant (index < \at(array,Pre)) ==> (cntodd(ints,0,index) == start);
          loop invariant (index < \at(array,Pre)) ==> (ints == \at(ints,Pre));
          loop invariant (index < \at(array,Pre)) ==> (ints_len == \at(ints_len,Pre));
          loop invariant (index < \at(array,Pre)) ==> (array == \at(array,Pre));
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
