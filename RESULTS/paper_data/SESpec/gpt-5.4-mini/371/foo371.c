
/*@
  requires p != 0;
  assigns \nothing;
  ensures value < 1 || \result == 0 || (1 <= \result && \result <= value);
  ensures \result == 0 ==> \forall integer i; 1 <= i <= value ==> (i % p) != z;
  ensures \result != 0 ==> (\result % p) == z;
  ensures \result != 0 ==> \forall integer i; \result < i <= value ==> (i % p) != z;
  ensures \result != 0 ==> \forall integer i; 1 <= i <= value && (i % p) == z ==> i <= \result;
*/
int foo371(int value, int p, int z) {

		int result = 0;
		
        /*@
          loop invariant c >= 1;
          loop invariant value < 1 || c <= value + 1;
          loop invariant result == 0 || (1 <= result && result < c);
          loop invariant result == 0 || (result % p) == z;
          loop invariant \forall integer i; 1 <= i < c && (i % p) == z ==> i <= result;
          loop invariant value < 1 || (c <= value + 1 && (result == 0 || (1 <= result && result <= value)));
          loop assigns c, result;
        */
        for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
            
		return result;
}
