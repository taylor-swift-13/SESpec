#include <limits.h>


/*@
  logic integer tenprod(integer n, integer c) =
    n >= c ? 1 : ((n % 10) * tenprod(n + 1, c)) % 10;
*/

/*@ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  assigns \nothing;*/
int stub_A(int n, int c);

/*@loop invariant var <= c + 1 || result == 1;
			loop invariant var > n ==> result == result % 10;
			loop invariant var > n ==> result <= 9;
			loop invariant var > n ==> result < 10;
			loop invariant var == n + 1 || var > n;
			loop invariant var == n + 1 ==> result == 1;
			loop invariant var == n + 1 + (var - (n + 1));
			loop invariant var <= c + 1 || 1 <= result;
			loop invariant var <= c + 1 || 0 <= result;
			loop invariant var <= c + 1 ==> result == result % 10;
			loop invariant var <= c + 1 ==> result <= 9;
			loop invariant var <= c + 1 ==> result < 10;
			loop invariant var - (n + 1) <= c - n || 1 <= result;
			loop invariant var - (n + 1) <= c - n || 0 <= result;
			loop invariant result == result % 10;
			loop invariant result == 1 || var > n;
			loop invariant result == 1 || result < 10;
			loop invariant result == 1 || n + 1 <= var;
			loop invariant result == (result % 10);
			loop invariant result == ((result % 10));
			loop invariant result == ((n + 1 <= var) ? result : 1);
			loop invariant result <= 9;
			loop invariant result < 10;
			loop invariant result % 10 == result;
			loop invariant result != 0 ==> result < 10;
			loop invariant n <= var;
			loop invariant n < var;
			loop invariant n < var || var <= c + 1;
			loop invariant n < var || var - (n + 1) <= c - n;
			loop invariant n < var || result == 1;
			loop invariant n < var || 1 <= result;
			loop invariant n < var || 0 <= result;
			loop invariant n + 1 <= var;
			loop invariant \forall integer k; n + 1 <= k < var ==> result == result % 10;
			loop invariant \forall integer k; n + 1 <= k < var ==> result == (result % 10);
			loop invariant \forall integer k; n + 1 <= k < var ==> result <= 9;
			loop invariant \forall integer k; n + 1 <= k < var ==> result < 10;
			loop invariant \forall integer k; n + 1 <= k < var ==> (k % 10) != 0 ==> result % 10 == result;
			loop invariant \exists integer k; n + 1 <= k <= var ==> result == (k % 10) % 10;
			loop invariant 1 <= result || var > n;
			loop invariant 1 <= result || var <= c + 1;
			loop invariant 0 <= var - (n + 1);
			loop invariant 0 <= var - (n + 1) || var <= c;
			loop invariant 0 <= var - (n + 1) || var <= c + 1;
			loop invariant 0 <= var - (n + 1) || result == 1;
			loop invariant 0 <= var - (n + 1) || 1 <= result;
			loop invariant 0 <= result || var <= c + 1;
			loop invariant 0 <= result || 0 <= var - (n + 1);
			loop invariant (var == n + 1) || (var > n);
			loop invariant (var == n + 1) ==> result == 1;
			loop assigns var;
			loop assigns result;*/
int stub_B(int n, int c);

/*@loop invariant var <= c + 1 || result == 1;
			loop invariant var > n ==> result == result % 10;
			loop invariant var > n ==> result <= 9;
			loop invariant var > n ==> result < 10;
			loop invariant var == n + 1 || var > n;
			loop invariant var == n + 1 ==> result == 1;
			loop invariant var == n + 1 + (var - (n + 1));
			loop invariant var <= c + 1 || 1 <= result;
			loop invariant var <= c + 1 || 0 <= result;
			loop invariant var <= c + 1 ==> result == result % 10;
			loop invariant var <= c + 1 ==> result <= 9;
			loop invariant var <= c + 1 ==> result < 10;
			loop invariant var - (n + 1) <= c - n || 1 <= result;
			loop invariant var - (n + 1) <= c - n || 0 <= result;
			loop invariant result == result % 10;
			loop invariant result == 1 || var > n;
			loop invariant result == 1 || result < 10;
			loop invariant result == 1 || n + 1 <= var;
			loop invariant result == (result % 10);
			loop invariant result == ((result % 10));
			loop invariant result == ((n + 1 <= var) ? result : 1);
			loop invariant result <= 9;
			loop invariant result < 10;
			loop invariant result % 10 == result;
			loop invariant result != 0 ==> result < 10;
			loop invariant n <= var;
			loop invariant n < var;
			loop invariant n < var || var <= c + 1;
			loop invariant n < var || var - (n + 1) <= c - n;
			loop invariant n < var || result == 1;
			loop invariant n < var || 1 <= result;
			loop invariant n < var || 0 <= result;
			loop invariant n + 1 <= var;
			loop invariant \forall integer k; n + 1 <= k < var ==> result == result % 10;
			loop invariant \forall integer k; n + 1 <= k < var ==> result == (result % 10);
			loop invariant \forall integer k; n + 1 <= k < var ==> result <= 9;
			loop invariant \forall integer k; n + 1 <= k < var ==> result < 10;
			loop invariant \forall integer k; n + 1 <= k < var ==> (k % 10) != 0 ==> result % 10 == result;
			loop invariant \exists integer k; n + 1 <= k <= var ==> result == (k % 10) % 10;
			loop invariant 1 <= result || var > n;
			loop invariant 1 <= result || var <= c + 1;
			loop invariant 0 <= var - (n + 1);
			loop invariant 0 <= var - (n + 1) || var <= c;
			loop invariant 0 <= var - (n + 1) || var <= c + 1;
			loop invariant 0 <= var - (n + 1) || result == 1;
			loop invariant 0 <= var - (n + 1) || 1 <= result;
			loop invariant 0 <= result || var <= c + 1;
			loop invariant 0 <= result || 0 <= var - (n + 1);
			loop invariant (var == n + 1) || (var > n);
			loop invariant (var == n + 1) ==> result == 1;
			loop assigns var;
			loop assigns result;*/
int check_A_implies_B(int n, int c) {
    return stub_A(n, c);
}

/*@ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  assigns \nothing;*/
int check_B_implies_A(int n, int c) {
    return stub_B(n, c);
}
