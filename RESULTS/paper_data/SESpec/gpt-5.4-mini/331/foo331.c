
/*@
  logic integer prod_mod(integer i, integer j) =
    i > j ? 1 : ((i % 10) * prod_mod(i + 1, j)) % 10;
*/

/*@
  requires n >= 0;
  requires c >= 0;
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  ensures \result >= 0 && \result <= 9;
*/
int foo331(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            /*@
          loop invariant n + 1 <= index;
          loop invariant 0 <= index;
          loop invariant 0 <= result && result <= 9;
          loop invariant -9 <= result && result <= 9;
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant index <= c + 1 ==> result >= 0 && result <= 9;
          loop assigns index, result;
            */
            for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
            
			return result % 10;
		}
}
