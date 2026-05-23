
/*@
  logic integer foo270_seq(integer m, integer n) =
    n == 0 ? 1 :
    n == 1 ? m :
    n == 2 ? m * m :
    ((m - 1) * (foo270_seq(m, n - 1) + foo270_seq(m, n - 2))) % 1000000007;
*/

int foo270(int count, int m) {
        /*@ requires count >= 2; */
		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant d >= 3;
          loop invariant div[0] == 1;
          loop invariant div[1] == m;
          loop invariant div[2] == m * m;
          loop assigns d, div[0..count];
            */
            for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
            
		return div[count];
}
