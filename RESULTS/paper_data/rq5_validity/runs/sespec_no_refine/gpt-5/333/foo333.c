
/*@
  ensures (n == c) ==> \result == 1;
  ensures (n != c && (c - n) >= 5) ==> \result == 0;
  ensures (n != c && (c - n) < 5) ==> \result == prod_mod10(n + 1, c) % 10;
  assigns \nothing;
*/
int foo333(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant c == \at(c,Pre);
              loop invariant n == \at(n,Pre);
              loop invariant var >= \at(n,Pre) + 1;
              loop assigns var, result;
            */
            for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
