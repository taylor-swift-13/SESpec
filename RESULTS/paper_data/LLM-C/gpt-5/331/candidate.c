#include <limits.h>

int computeLastDigit(int n, int c);

/*@
  assigns \nothing;

  behavior empty_or_inverted_range:
    assumes c <= n;
    ensures \result == 1;

  behavior large_gap:
    assumes c > n && c - n >= 5;
    ensures \result == 0;

  behavior small_positive_gap:
    assumes c > n && c - n < 5;
    ensures \result == ((\product integer i; n+1 <= i <= c; (i % 10)) % 10);

  disjoint behaviors;
  complete behaviors;

  ensures -9 <= \result <= 9;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			  loop invariant index >= n + 1;
			  loop invariant (c < n) || (index <= c + 1);
			  loop invariant result == ((\product integer i; n+1 <= i < index; (i % 10)) % 10);
			  loop invariant -9 <= result <= 9;
			  loop assigns result, index;
			  loop variant c - index + 1;
			*/
			for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
}
