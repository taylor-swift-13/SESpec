
/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  ensures \result <= array ==> positions[\result - 1] != \result;
*/
int foo161(int * positions, int positions_len, int array) {

		int ret = 0;
		
            /*@
          loop invariant positions == \at(positions,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] <= 0 || positions[k] > array || (1 <= positions[k] && positions[k] <= array);
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
          loop invariant positions == \at(positions,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] <= 0 || positions[k] > array || (1 <= positions[k] && positions[k] <= array);
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
