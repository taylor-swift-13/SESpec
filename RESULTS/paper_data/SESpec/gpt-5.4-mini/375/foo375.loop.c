
/*@
  logic integer binomial(integer n, integer k) =
    k < 0 || k > n ? 0 :
    k == 0 || k == n ? 1 :
    binomial(n - 1, k - 1) + binomial(n - 1, k);
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo375(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		
            
            /*@
          loop invariant 1 <= r;
          loop invariant p < 1 || r <= p + 1;
          loop invariant num == \at(num,Pre);
          loop invariant p == \at(p,Pre) || p == \at(num,Pre) - \at(p,Pre);
          loop invariant p < 0 || r - 1 <= p;
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
            
		return b;
}
