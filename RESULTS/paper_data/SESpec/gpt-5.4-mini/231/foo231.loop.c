
/*@
  logic integer count_diff_pairs(int* p, integer n) =
    n <= 1 ? 0 : count_diff_pairs(p, n - 1) + (p[n - 2] != p[n - 1] ? 1 : 0);
*/
        
/*@
  requires \valid(&p[0] + (0..p_len-1));
  requires \forall integer i; 0 <= i < p_len ==> 0 <= p[i] <= 100;
  requires p_len > 0;
  requires p_len < 100;
*/

int foo231(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= total - 1;
          loop invariant total == \at(p_len,Pre);
          loop invariant p_len == \at(p_len,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant count >= 0;
          loop invariant count == count_diff_pairs(p, index + 1);
          loop assigns index, c, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= index <= total - 1;
              loop invariant count >= 0;
              loop assigns index, count;
              loop variant total - 1 - index;
            */
            for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
