#include <limits.h>


/*@ logic integer gcd(integer a, integer b) =
      b == 0 ? a : gcd(b, a % b); */

/*@requires n > 0 && y > 0;
  assigns \nothing;
  ensures (\old(n) <= 0 || \old(y) <= 0) ==> \result == \old(n) * \old(y);
  ensures (\old(n) > 0 && \old(y) > 0) ==> \result > 0;*/
int stub_A(int n, int y);

/*@loop invariant y % ret == 0 || ret == 1;
		loop invariant ret == 1 || ret <= y;
		loop invariant ret == 1 || ret <= n;
		loop invariant ret == 1 || ret <= l;
		loop invariant ret == 1 || (n % ret == 0 && y % ret == 0);
		loop invariant ret == 1 || (1 <= ret && ret <= y);
		loop invariant ret == 1 || (1 <= ret && ret <= n);
		loop invariant ret == 1 || (1 <= ret && ret <= l);
		loop invariant ret <= l;
		loop invariant n <= y;
		loop invariant n % ret == 0 || ret == 1;
		loop invariant n % ret == 0 && y % ret == 0;
		loop invariant \forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant \forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret);
		loop invariant \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret;
		loop invariant \forall integer k; 1 <= k < l && (n % k == 0 && y % k == 0) ==> k <= ret;
		loop invariant 1 <= ret;
		loop invariant 1 <= l;
		loop assigns ret;
		loop assigns l;*/
int stub_B(int n, int y);

/*@loop invariant y % ret == 0 || ret == 1;
		loop invariant ret == 1 || ret <= y;
		loop invariant ret == 1 || ret <= n;
		loop invariant ret == 1 || ret <= l;
		loop invariant ret == 1 || (n % ret == 0 && y % ret == 0);
		loop invariant ret == 1 || (1 <= ret && ret <= y);
		loop invariant ret == 1 || (1 <= ret && ret <= n);
		loop invariant ret == 1 || (1 <= ret && ret <= l);
		loop invariant ret <= l;
		loop invariant n <= y;
		loop invariant n % ret == 0 || ret == 1;
		loop invariant n % ret == 0 && y % ret == 0;
		loop invariant \forall integer k; 1 <= k < l ==> (n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant \forall integer k; 1 <= k < l ==> (n % k != 0 || y % k != 0 || k <= ret);
		loop invariant \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret;
		loop invariant \forall integer k; 1 <= k < l && (n % k == 0 && y % k == 0) ==> k <= ret;
		loop invariant 1 <= ret;
		loop invariant 1 <= l;
		loop assigns ret;
		loop assigns l;*/
int check_A_implies_B(int n, int y) {
    return stub_A(n, y);
}

/*@requires n > 0 && y > 0;
  assigns \nothing;
  ensures (\old(n) <= 0 || \old(y) <= 0) ==> \result == \old(n) * \old(y);
  ensures (\old(n) > 0 && \old(y) > 0) ==> \result > 0;*/
int check_B_implies_A(int n, int y) {
    return stub_B(n, y);
}
