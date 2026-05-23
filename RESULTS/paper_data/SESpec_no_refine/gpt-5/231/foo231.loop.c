
/*@
  logic integer pair_neq_up_to(int* a, integer n, integer i) =
    i <= 0 ? 0
           : pair_neq_up_to(a, n, i - 1)
             + (\sum integer j; 0 <= j < i && j < n ? (a[j] != a[i] ? 1 : 0) : 0);
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
          loop invariant 0 <= total && total == p_len;
          loop invariant 0 <= count;
          loop invariant 0 <= index <= total - 1 ==> count == pair_neq_up_to(p, total, index);
          loop invariant \forall integer k; 0 <= k < total ==> p[k] == \at(p[k], Pre);
          loop assigns index, c, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= total - 1;
          loop assigns index, count, p[..];
            */
            for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
