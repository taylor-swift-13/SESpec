#include <limits.h>


/*@
  logic integer prod_mod(integer i, integer j) =
    i > j ? 1 : ((i % 10) * prod_mod(i + 1, j)) % 10;
*/

/*@requires n >= 0;
  requires c >= 0;
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  ensures \result >= 0 && \result <= 9;*/
int stub_A(int n, int c);

/*@loop invariant result == 1 || result < 10;
			loop invariant \forall integer k; n + 1 <= k < index ==> result < 10;
			loop invariant result == result % 10;
			loop invariant result == 1 || result == 0 || result < 10;
			loop invariant result == (result % 10);
			loop invariant result <= 9;
			loop invariant result < 10;
			loop invariant result % 2 == result % 2;
			loop invariant result % 10 == result;
			loop invariant n < index;
			loop invariant n + 1 <= index;
			loop invariant index >= n + 1 ==> result < 10;
			loop invariant index > n ==> result == result % 10;
			loop invariant index > n ==> result < 10;
			loop invariant index > n ==> result % 10 == result;
			loop invariant index == n + 1 || index > n;
			loop invariant index == n + 1 ==> result == 1;
			loop invariant index <= c + 1 || result < 10;
			loop invariant index <= c + 1 || 0 <= result;
			loop invariant index <= c + 1 || 0 <= index - n;
			loop invariant index <= c + 1 ==> result == result % 10;
			loop invariant index <= c + 1 ==> result < 10;
			loop invariant index - (n + 1) <= c - n || 0 <= result;
			loop invariant 1 <= result || index <= c + 1;
			loop invariant 1 <= result || index - (n + 1) <= c - n;
			loop invariant 1 <= result || 0 <= index - n;
			loop invariant 1 <= index - n;
			loop invariant 1 <= index - n || index <= c + 1;
			loop invariant 1 <= index - n || index - (n + 1) <= c - n;
			loop invariant 1 <= index - n || 1 <= result;
			loop invariant 1 <= index - n || 0 <= index;
			loop invariant 1 <= index - n || 0 <= index - n;
			loop invariant 0 <= result || index <= c + 1;
			loop invariant 0 <= result || index - (n + 1) <= c - n;
			loop invariant 0 <= result || 1 <= index - n;
			loop invariant 0 <= result || 0 <= index - n;
			loop invariant 0 <= index || 0 <= index - n;
			loop invariant 0 <= index - n;
			loop invariant 0 <= index - n || index - (n + 1) <= c - n;
			loop invariant 0 <= index - (n + 1);
			loop invariant 0 < index - n;
			loop invariant (n + 1 <= index <= c + 1) ==> result < 10;
			loop invariant (index > n) ==> result < 10;
			loop invariant (index > n) ==> result % 10 == result;
			loop invariant (index > n) ==> (result < 10);
			loop invariant (index == n + 1) || (index > n);
			loop invariant (index == n + 1) ==> result == 1;
			loop invariant (index <= c + 1) ==> result == result % 10;
			loop invariant (index <= c + 1) ==> (result < 10);
			loop assigns result;
			loop assigns index;*/
int stub_B(int n, int c);

/*@loop invariant result == 1 || result < 10;
			loop invariant \forall integer k; n + 1 <= k < index ==> result < 10;
			loop invariant result == result % 10;
			loop invariant result == 1 || result == 0 || result < 10;
			loop invariant result == (result % 10);
			loop invariant result <= 9;
			loop invariant result < 10;
			loop invariant result % 2 == result % 2;
			loop invariant result % 10 == result;
			loop invariant n < index;
			loop invariant n + 1 <= index;
			loop invariant index >= n + 1 ==> result < 10;
			loop invariant index > n ==> result == result % 10;
			loop invariant index > n ==> result < 10;
			loop invariant index > n ==> result % 10 == result;
			loop invariant index == n + 1 || index > n;
			loop invariant index == n + 1 ==> result == 1;
			loop invariant index <= c + 1 || result < 10;
			loop invariant index <= c + 1 || 0 <= result;
			loop invariant index <= c + 1 || 0 <= index - n;
			loop invariant index <= c + 1 ==> result == result % 10;
			loop invariant index <= c + 1 ==> result < 10;
			loop invariant index - (n + 1) <= c - n || 0 <= result;
			loop invariant 1 <= result || index <= c + 1;
			loop invariant 1 <= result || index - (n + 1) <= c - n;
			loop invariant 1 <= result || 0 <= index - n;
			loop invariant 1 <= index - n;
			loop invariant 1 <= index - n || index <= c + 1;
			loop invariant 1 <= index - n || index - (n + 1) <= c - n;
			loop invariant 1 <= index - n || 1 <= result;
			loop invariant 1 <= index - n || 0 <= index;
			loop invariant 1 <= index - n || 0 <= index - n;
			loop invariant 0 <= result || index <= c + 1;
			loop invariant 0 <= result || index - (n + 1) <= c - n;
			loop invariant 0 <= result || 1 <= index - n;
			loop invariant 0 <= result || 0 <= index - n;
			loop invariant 0 <= index || 0 <= index - n;
			loop invariant 0 <= index - n;
			loop invariant 0 <= index - n || index - (n + 1) <= c - n;
			loop invariant 0 <= index - (n + 1);
			loop invariant 0 < index - n;
			loop invariant (n + 1 <= index <= c + 1) ==> result < 10;
			loop invariant (index > n) ==> result < 10;
			loop invariant (index > n) ==> result % 10 == result;
			loop invariant (index > n) ==> (result < 10);
			loop invariant (index == n + 1) || (index > n);
			loop invariant (index == n + 1) ==> result == 1;
			loop invariant (index <= c + 1) ==> result == result % 10;
			loop invariant (index <= c + 1) ==> (result < 10);
			loop assigns result;
			loop assigns index;*/
int check_A_implies_B(int n, int c) {
    return stub_A(n, c);
}

/*@requires n >= 0;
  requires c >= 0;
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  ensures \result >= 0 && \result <= 9;*/
int check_B_implies_A(int n, int c) {
    return stub_B(n, c);
}
