#include <limits.h>


/*@
  logic integer prod(integer n, integer i) =
    i <= 0 ? 1 : prod(n, i - 1) * (n - i + 1) / i;
*/

/*@requires 0 <= n;
  requires 0 <= k <= n;
  assigns \nothing;
  ensures k == \old(k) || k == n - \old(k);
  ensures \old(k) > n - \old(k) ==> k == k;
  ensures \old(k) <= n - \old(k) ==> k == \old(k);
  ensures \result == \result;
  ensures \result >= 0;*/
int stub_A(int n, int k);

/*@loop invariant c == 1 || c >= 1;
        loop invariant c == 1 || c > 0;
        loop invariant c <= c * i;
        loop invariant \forall integer t; 1 <= t < i ==> t <= n;
        loop invariant \forall integer t; 1 <= t < i ==> t <= k;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= t;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= t - 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= i;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= i - t;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= i - t + 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= 0;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > t - 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > i - t;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > i - 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > 0;
        loop invariant \forall integer t; 1 <= t < i ==> i >= t;
        loop invariant \forall integer t; 1 <= t < i ==> i > t;
        loop invariant \forall integer t; 1 <= t < i ==> i <= k + 1;
        loop invariant \forall integer t; 1 <= t < i ==> i != t;
        loop invariant \forall integer t; 1 <= t < i ==> c >= 1;
        loop invariant \forall integer t; 1 <= t < i ==> c >= 0;
        loop invariant \forall integer t; 1 <= t < i ==> c * t >= 1;
        loop invariant \forall integer t; 1 <= t < i ==> (n - t + 1) >= t;
        loop invariant \forall integer t; 1 <= t < i ==> (n - t + 1) > 0;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= j;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= i;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= i - j;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= 1;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= 0;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 > j;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 > j - 1;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 > 0;
        loop invariant \forall integer j; 1 <= j < i ==> i >= j;
        loop invariant \forall integer j; 1 <= j < i ==> i > j;
        loop invariant \forall integer j; 1 <= j < i ==> i <= k + 1;
        loop invariant \forall integer j; 1 <= j < i ==> i != j;
        loop invariant \forall integer j; 1 <= j < i ==> i != 0;
        loop invariant \forall integer j; 1 <= j < i ==> c >= 1;
        loop invariant \forall integer j; 1 <= j < i ==> c >= 0;
        loop invariant \forall integer j; 1 <= j < i ==> c * j == c * j;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= j;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= i - j;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= 0;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) > 0;
        loop invariant 1 <= i;
        loop invariant 1 <= c;
        loop invariant 1 <= c * i;
        loop invariant 0 <= i;
        loop invariant 0 <= c;
        loop invariant 0 < i;
        loop invariant 0 < c;
        loop assigns i;
        loop assigns c;*/
int stub_B(int n, int k);

/*@loop invariant c == 1 || c >= 1;
        loop invariant c == 1 || c > 0;
        loop invariant c <= c * i;
        loop invariant \forall integer t; 1 <= t < i ==> t <= n;
        loop invariant \forall integer t; 1 <= t < i ==> t <= k;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= t;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= t - 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= i;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= i - t;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= i - t + 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= 0;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > t - 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > i - t;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > i - 1;
        loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 > 0;
        loop invariant \forall integer t; 1 <= t < i ==> i >= t;
        loop invariant \forall integer t; 1 <= t < i ==> i > t;
        loop invariant \forall integer t; 1 <= t < i ==> i <= k + 1;
        loop invariant \forall integer t; 1 <= t < i ==> i != t;
        loop invariant \forall integer t; 1 <= t < i ==> c >= 1;
        loop invariant \forall integer t; 1 <= t < i ==> c >= 0;
        loop invariant \forall integer t; 1 <= t < i ==> c * t >= 1;
        loop invariant \forall integer t; 1 <= t < i ==> (n - t + 1) >= t;
        loop invariant \forall integer t; 1 <= t < i ==> (n - t + 1) > 0;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= j;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= i;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= i - j;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= 1;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 >= 0;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 > j;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 > j - 1;
        loop invariant \forall integer j; 1 <= j < i ==> n - j + 1 > 0;
        loop invariant \forall integer j; 1 <= j < i ==> i >= j;
        loop invariant \forall integer j; 1 <= j < i ==> i > j;
        loop invariant \forall integer j; 1 <= j < i ==> i <= k + 1;
        loop invariant \forall integer j; 1 <= j < i ==> i != j;
        loop invariant \forall integer j; 1 <= j < i ==> i != 0;
        loop invariant \forall integer j; 1 <= j < i ==> c >= 1;
        loop invariant \forall integer j; 1 <= j < i ==> c >= 0;
        loop invariant \forall integer j; 1 <= j < i ==> c * j == c * j;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= j;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= i - j;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= 0;
        loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) > 0;
        loop invariant 1 <= i;
        loop invariant 1 <= c;
        loop invariant 1 <= c * i;
        loop invariant 0 <= i;
        loop invariant 0 <= c;
        loop invariant 0 < i;
        loop invariant 0 < c;
        loop assigns i;
        loop assigns c;*/
int check_A_implies_B(int n, int k) {
    return stub_A(n, k);
}

/*@requires 0 <= n;
  requires 0 <= k <= n;
  assigns \nothing;
  ensures k == \old(k) || k == n - \old(k);
  ensures \old(k) > n - \old(k) ==> k == k;
  ensures \old(k) <= n - \old(k) ==> k == \old(k);
  ensures \result == \result;
  ensures \result >= 0;*/
int check_B_implies_A(int n, int k) {
    return stub_B(n, k);
}
