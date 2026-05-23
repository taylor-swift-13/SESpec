int computeLastDigit(int n, int c);

/*@ 
  requires 0 <= n <= c;
  assigns \nothing;
  ensures 0 <= \result <= 9;

  behavior equal:
    assumes n == c;
    ensures \result == 1;

  behavior long:
    assumes c - n >= 5;
    ensures \result == 0;

  behavior short:
    assumes 1 <= c - n < 5;
    ensures \result == (\product integer k; n < k <= c; (k % 10)) % 10;

  complete behaviors equal, long, short;
  disjoint behaviors equal, long, short;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			  loop invariant n + 1 <= var <= c + 1;
			  loop invariant 0 <= result <= 9;
			  loop invariant result == (\product integer k; n < k < var; (k % 10)) % 10;
			  loop assigns var, result;
			  loop variant c - var + 1;
			*/
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
