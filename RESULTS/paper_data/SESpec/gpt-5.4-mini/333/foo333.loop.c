
/*@
  logic integer tenprod(integer a, integer b) =
    b <= a ? 1 : ((tenprod(a, b - 1) * ((b - 1) % 10)) % 10);
*/

int foo333(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            /*@
              loop invariant n == \at(n,Pre);
              loop invariant c == \at(c,Pre);
              loop invariant result == tenprod(n + 1, var);
              loop invariant n < c ==> n + 1 <= var && var <= c + 1;
              loop invariant c < n ==> var == n + 1;
              loop assigns var, result;
            */
            for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
