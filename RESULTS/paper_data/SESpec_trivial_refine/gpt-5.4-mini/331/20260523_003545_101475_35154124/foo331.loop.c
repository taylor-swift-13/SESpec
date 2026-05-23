
/*@
axiomatic ProductMod10 {
  logic integer prod_mod10(integer a, integer b) =
    (a >= b ? 1 : ((a % 10) * prod_mod10(a + 1, b)) % 10);
}
*/
        
int foo331(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n + 1 <= index;
          loop invariant -9 <= result <= 9;
          loop assigns index, result;
            */
            for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
            
			return result % 10;
		}
}
