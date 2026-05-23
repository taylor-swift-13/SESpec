
/*@
  logic integer fib_like(int *j, integer lo, integer hi) =
    lo >= hi ? 0 :
    (hi - lo == 1 ? j[lo] : fib_like(j, lo, hi - 1) + 2 * fib_like(j, lo, hi - 2));
*/

int foo287(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant p >= 2;
          loop invariant j[0] == 0;
          loop invariant j[1] == 1;
          loop invariant \forall integer i; 2 <= i < p ==> j[i] == j[i - 1] + 2 * j[i - 2];
          loop assigns p, j[0..c];
            */
            for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
            
		return j[c];
}
