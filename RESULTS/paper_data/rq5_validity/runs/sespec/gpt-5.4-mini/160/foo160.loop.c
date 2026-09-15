
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/
/*@ 
  logic integer count_mismatch_prefix(int* positions, integer n, integer i) =
    i <= 0 ? 0 :
    count_mismatch_prefix(positions, n, i - 1) +
    (positions[i - 1] != i ? 1 : 0);
*/

/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
*/

int foo160(int * positions, int positions_len, int array) {

		int ret = 0;
		
            
        /*@
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant positions == \at(positions,Pre);
        */
            while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int index = positions[ret];
				positions[ret] = positions[index - 1];
				positions[index - 1] = index;
			}
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
          loop invariant \forall integer k; 0 <= k < ret ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1;
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
