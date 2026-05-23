
/*@
*/

/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */
/*@ logic integer gcd_int(integer a, integer b) =
      b == 0 ? abs_int(a) : gcd_int(b, a % b); */
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \old(n) <= \old(y) && \old(n) > 0 ==> \result == (abs_int(\old(n)) * abs_int(\old(y))) / gcd_int(abs_int(\old(n)), abs_int(\old(y)));
  ensures \old(n) > \old(y) && \old(y) > 0 ==> \result == (abs_int(\old(n)) * abs_int(\old(y))) / gcd_int(abs_int(\old(n)), abs_int(\old(y)));
  ensures (\old(n) <= 0 || \old(y) <= 0) ==> \result == \old(n) * \old(y);
  ensures \old(n) == \old(y) ==> \result == abs_int(\old(n));
*/
int foo320(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l <= n + 1;
          loop invariant ret >= 1;
          loop invariant n % ret == 0 && y % ret == 0;
          loop assigns l, ret;
            */
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		g = (n * y) / ret;
		return g;
}
