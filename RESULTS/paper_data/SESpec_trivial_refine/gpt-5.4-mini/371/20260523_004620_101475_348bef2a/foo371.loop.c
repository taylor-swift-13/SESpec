
/*@
predicate dummy_predicate(integer x) = \true;
*/

int foo371(int value, int p, int z) {

		int result = 0;
		
            
        /*@
          loop invariant 1 <= c;
          loop invariant 0 <= result;
          loop invariant result == 0 || (1 <= result < c && (result % p) == z);
          loop invariant \forall integer i; 1 <= i < c && (i % p) == z ==> i <= result;
          loop assigns c, result;
        */
            for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
            
		return result;
}
