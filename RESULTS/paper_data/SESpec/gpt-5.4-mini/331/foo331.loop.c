
/*@
  logic integer prod_mod(integer a, integer b) =
    a > b ? 1 : ((prod_mod(a, b - 1) * (b % 10)) % 10);
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
          loop invariant result == prod_mod(n + 1, index - 1);
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant index <= c + 1 ==> result == prod_mod(n + 1, index - 1);
          loop assigns index, result;
            */
            for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
            
			return result % 10;
		}
}
