
/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns positions[0 .. (array > 0 ? array-1 : -1)];
  ensures 1 <= \result <= array + 1;
  ensures \result <= array ==> positions[\result - 1] != \result;
  ensures \result <= array ==> \forall integer k; 0 <= k < \result - 1 ==> positions[k] == k + 1;
  ensures \result == array + 1 ==> \forall integer k; 0 <= k < array ==> positions[k] == k + 1;
  ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo160(int * positions, int positions_len, int array) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant positions_len == positions_len;
          loop invariant positions == positions;
          loop invariant array == array;
          loop invariant \valid(positions + (0 .. positions_len-1));
          loop invariant 0 <= ret ==> ret < positions_len;
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] >= -2147483648;
          loop assigns ret, positions[..];
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
          loop invariant 0 <= ret <= array;
          loop invariant 0 <= array <= positions_len;
          loop invariant \valid(positions + (0 .. positions_len-1));
          loop invariant \forall integer k; 0 <= k < array ==> 0 <= positions[k] <= 100;
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
