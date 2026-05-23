
/*@
  logic integer sum_pairs_with_index(int* a, integer idx, integer upto, integer p) =
    upto <= idx + 1 ? 0
                    : sum_pairs_with_index(a, idx, upto - 1, p)
                      + (a[idx] + a[upto - 1] == p ? 1 : 0);

  logic integer cnt_pairs_prefix(int* a, integer upto, integer num, integer p) =
    upto <= 0 ? 0
              : cnt_pairs_prefix(a, upto - 1, num, p)
                + (upto - 1 < num ? sum_pairs_with_index(a, upto - 1, num, p) : 0);
*/
        
/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
*/

int foo244(int * array, int array_len, int num, int p) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant ret == cnt_pairs_prefix(array, index, num, p);
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer t; 0 <= t < array_len ==> 0 <= array[t] <= 100;
          loop assigns index, j, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= j <= num;
          loop invariant ret == cnt_pairs_prefix(array, index, num, p)
                                + sum_pairs_with_index(array, index, j, p);
          loop invariant ret >= 0;
          loop assigns ret, j;
            */
            for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
