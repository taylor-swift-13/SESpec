
/*@ logic integer my_min(integer a, integer b) = a <= b ? a : b; */
/*@
  assigns \nothing;
  ensures (my_min(p, seed - p) <= 0) ==> \result == 1;
  ensures (1 <= my_min(p, seed - p) && my_min(p, seed - p) <= seed) ==> \result == binom(seed, my_min(p, seed - p));
  ensures (my_min(p, seed - p) >= seed + 1) ==> \result == 0;
*/
int foo377(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant seed == seed;
          loop invariant p == p;
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
