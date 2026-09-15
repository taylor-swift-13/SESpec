
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/* No extra predicate needed */

/*@ 
  requires \valid(positions + (0 .. positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns positions[0..positions_len-1];
  ensures (\exists integer k; 0 <= k < (array < positions_len ? array : positions_len) && positions[k] != k+1) ==>
            (\result >= 1 && \result <= array &&
             positions[\result-1] != (\result-1)+1 &&
             \forall integer j; 0 <= j < \result-1 ==> positions[j] == j+1);
            (\result == array + 1);
*/
int foo161(int * positions, int positions_len, int array) {

		int ret = 0;
		
            
        /*@
          loop invariant 0 <= ret;
          loop invariant array == \at(array,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
                           0 <= v <= 100 ==>
                             count_eq(positions, 0, positions_len, v) 
                             == count_eq{Pre}(positions, 0, positions_len, v));
          loop assigns ret, positions[0..positions_len-1];
            */
            while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int j = positions[ret];
				positions[ret] = positions[j - 1];
				positions[j - 1] = j;
			}
		}
            
		
            
        /*@
          loop invariant 0 <= ret;
          loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
