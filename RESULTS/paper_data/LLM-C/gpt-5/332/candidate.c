/*@ 
  logic integer prod_mod10(int a, int b) =
    (a > b) ? 1 : ((prod_mod10(a, b - 1) * (b % 10)) % 10);
*/

int computeLastDigit(int num, int c);

/*@
  requires \true;
  assigns \nothing;

  behavior equal:
    assumes num == c;
    ensures \result == 1;

  behavior biggap:
    assumes c - num >= 5;
    ensures \result == 0;

  behavior smallgap:
    assumes num != c && c - num < 5;
    ensures \result == prod_mod10(num + 1, c);

  ensures -9 <= \result <= 9;

  complete behaviors equal, biggap, smallgap;
  disjoint behaviors equal, biggap, smallgap;
*/
int computeLastDigit(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			/*@
			  loop invariant num + 1 <= var <= c + 1;
			  loop invariant result == prod_mod10(num + 1, var - 1);
			  loop invariant -9 <= result <= 9;
			  loop assigns result, var;
			  loop variant c + 1 - var;
			*/
			for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
