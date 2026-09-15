
/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  requires array >= 0;
  requires array <= positions_len;
  assigns positions[0..array-1];
  ensures (\forall integer k; 0 <= k < array ==> \at(positions[k],Pre) == k + 1) ==> 1 <= \result <= array + 1;
  ensures (\exists integer k; 0 <= k < array && \at(positions[k],Pre) != k + 1) ==> 1 <= \result <= array + 1;
*/

int foo161(int * positions, int positions_len, int array) {

		int ret = 0;
		
            
        /*@
          loop invariant array == \at(array,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant 0 <= ret;
          loop invariant (0 < \at(array,Pre)) ==> (ret <= \at(array,Pre));
          loop invariant (0 < \at(array,Pre)) ==> (ret >= 0);
          loop invariant (0 < \at(array,Pre)) ==> (ret == 0 || ret > 0);
          loop invariant (!(0 < \at(array,Pre))) ==> ((ret == 0)&&(array == \at(array,Pre))&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre)));
          loop assigns ret, positions[0..array-1];
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
          loop invariant positions == \at(positions,Pre);
          loop assigns ret;
        */
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
