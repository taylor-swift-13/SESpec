#include <limits.h>


/*@
logic integer gcd(integer a, integer b) =
  b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b);
*/

/*@requires n > y;
  requires n >= 0;
  requires y >= 0;
  assigns \nothing;
  ensures \true;
  ensures \result >= 0;*/
int stub_A(int n, int y);

/*@loop invariant ret == 1 || ret >= 1;
		loop invariant ret == 1 || ret > 0;
		loop invariant ret == 1 || ret == j - 1 || ret < j;
		loop invariant ret == 1 || ret <= y;
		loop invariant ret == 1 || ret <= n;
		loop invariant ret == 1 || ret <= j;
		loop invariant ret == 1 || ret <= j - 1;
		loop invariant ret == 1 || ret % 1 == 0;
		loop invariant ret == 1 || \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant ret == 1 || \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret;
		loop invariant ret == 1 || \exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k;
		loop invariant ret == 1 || 1 <= ret <= y;
		loop invariant ret == 1 || 1 <= ret <= n;
		loop invariant ret == 1 || (ret >= 1 && ret <= j);
		loop invariant ret == 1 || (ret == j || ret < j);
		loop invariant ret == 1 || (ret == j - 1 || ret < j);
		loop invariant ret == 1 || (ret <= n && ret <= y);
		loop invariant ret == 1 || (n % ret == 0 && y % ret == 0);
		loop invariant ret == 1 || (n % ret == 0 && y % ret == 0 && ret < j);
		loop invariant ret == 1 || (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret));
		loop invariant ret == 1 || (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant ret == 1 || (\exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k);
		loop invariant ret == 1 || (1 <= ret <= j);
		loop invariant ret == 1 || (1 <= ret < j);
		loop invariant ret <= j;
		loop invariant ret <= j || ret == 1;
		loop invariant n % ret == 0 && y % ret == 0;
		loop invariant \forall integer k; 1 <= k < j ==> ret >= 1;
		loop invariant \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> ret >= k);
		loop invariant \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant \forall integer k; 1 <= k < j ==> (n % k != 0 || y % k != 0 || k <= ret);
		loop invariant \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret;
		loop invariant \forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> k <= ret;
		loop invariant \exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0;
		loop invariant \exists integer k; 1 <= k <= j && ret == k && n % k == 0 && y % k == 0;
		loop invariant \exists integer k; 1 <= k <= j && n % k == 0 && y % k == 0 && ret == k;
		loop invariant 1 <= ret;
		loop invariant 1 <= j;
		loop invariant 0 <= ret;
		loop invariant 0 < ret;
		loop invariant (ret == 1) || (n % ret == 0 && y % ret == 0);
		loop assigns ret;
		loop assigns j;*/
int stub_B(int n, int y);

/*@loop invariant ret == 1 || ret >= 1;
		loop invariant ret == 1 || ret > 0;
		loop invariant ret == 1 || ret == j - 1 || ret < j;
		loop invariant ret == 1 || ret <= y;
		loop invariant ret == 1 || ret <= n;
		loop invariant ret == 1 || ret <= j;
		loop invariant ret == 1 || ret <= j - 1;
		loop invariant ret == 1 || ret % 1 == 0;
		loop invariant ret == 1 || \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant ret == 1 || \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret;
		loop invariant ret == 1 || \exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k;
		loop invariant ret == 1 || 1 <= ret <= y;
		loop invariant ret == 1 || 1 <= ret <= n;
		loop invariant ret == 1 || (ret >= 1 && ret <= j);
		loop invariant ret == 1 || (ret == j || ret < j);
		loop invariant ret == 1 || (ret == j - 1 || ret < j);
		loop invariant ret == 1 || (ret <= n && ret <= y);
		loop invariant ret == 1 || (n % ret == 0 && y % ret == 0);
		loop invariant ret == 1 || (n % ret == 0 && y % ret == 0 && ret < j);
		loop invariant ret == 1 || (\forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret));
		loop invariant ret == 1 || (\forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant ret == 1 || (\exists integer k; 1 <= k < j && n % k == 0 && y % k == 0 && ret == k);
		loop invariant ret == 1 || (1 <= ret <= j);
		loop invariant ret == 1 || (1 <= ret < j);
		loop invariant ret <= j;
		loop invariant ret <= j || ret == 1;
		loop invariant n % ret == 0 && y % ret == 0;
		loop invariant \forall integer k; 1 <= k < j ==> ret >= 1;
		loop invariant \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> ret >= k);
		loop invariant \forall integer k; 1 <= k < j ==> (n % k == 0 && y % k == 0 ==> k <= ret);
		loop invariant \forall integer k; 1 <= k < j ==> (n % k != 0 || y % k != 0 || k <= ret);
		loop invariant \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret;
		loop invariant \forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < j && (n % k == 0 && y % k == 0) ==> k <= ret;
		loop invariant \exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0;
		loop invariant \exists integer k; 1 <= k <= j && ret == k && n % k == 0 && y % k == 0;
		loop invariant \exists integer k; 1 <= k <= j && n % k == 0 && y % k == 0 && ret == k;
		loop invariant 1 <= ret;
		loop invariant 1 <= j;
		loop invariant 0 <= ret;
		loop invariant 0 < ret;
		loop invariant (ret == 1) || (n % ret == 0 && y % ret == 0);
		loop assigns ret;
		loop assigns j;*/
int check_A_implies_B(int n, int y) {
    return stub_A(n, y);
}

/*@requires n > y;
  requires n >= 0;
  requires y >= 0;
  assigns \nothing;
  ensures \true;
  ensures \result >= 0;*/
int check_B_implies_A(int n, int y) {
    return stub_B(n, y);
}
