
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate all_in_range(int* a, integer lo, integer hi, integer n) =
    \forall integer k; lo <= k < hi ==> (a[k] <= 0) || (a[k] > n) || (1 <= a[k] && a[k] <= n);
*/

        
/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires 0 <= array <= positions_len;
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  assigns positions[0 .. (array > 0 ? (array - 1) : -1)];
  ensures \result == array + 1 ==> \forall integer k; 0 <= k < array ==> positions[k] == k + 1;
  ensures \result == array + 1 ==> \forall integer k; array <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
  ensures 1 <= \result <= array ==> positions[\result - 1] != \result;
  ensures 1 <= \result <= array ==> \forall integer k; 0 <= k < \result - 1 ==> positions[k] == k + 1;
  ensures 1 <= \result <= array ==> \forall integer k; array <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
*/
int foo160(int * positions, int positions_len, int array) {

		int ret = 0;
        
            /*@
              loop invariant positions == \at(positions, Pre);
              loop invariant positions_len == \at(positions_len, Pre);
              loop invariant array == \at(array, Pre);
              loop invariant all_in_range(positions, 0, array, array);
              loop assigns ret, positions[0 .. array-1];
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
        
            /*@
              loop invariant positions == \at(positions, Pre);
              loop invariant positions_len == \at(positions_len, Pre);
              loop invariant array == \at(array, Pre);
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
