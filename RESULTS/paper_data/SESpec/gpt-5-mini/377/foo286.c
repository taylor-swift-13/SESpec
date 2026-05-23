
/*@ 
  logic integer binom(integer n, integer k) =
    k < 0 || k > n ? 0 :
    k == 0 ? 1 :
    k == n ? 1 :
    binom(n-1,k-1) + binom(n-1,k);
*/

/*@
  requires 0 <= seed && 0 <= p;
  assigns \nothing;
*/
int foo286(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /*@
          loop invariant seed == \at(seed,Pre);
          loop assigns r, b;
        */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
