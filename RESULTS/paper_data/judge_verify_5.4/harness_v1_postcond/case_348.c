#include <limits.h>


/*@ logic integer nondiv_count(integer a, integer l, integer u) =
      u < l ? 0 : nondiv_count(a, l, u - 1) + ((u % a) != 0 ? 1 : 0);
*/

/*@requires a != 0;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= r;
  ensures \result != -1 ==> nondiv_count(a, l, \result) == n;
  ensures \result == -1 || (l <= \result && \result <= r);
  ensures \result == -1 || (nondiv_count(a, l, \result) == n);*/
int stub_A(int a, int n, int l, int r);

/*@loop invariant l <= i;
        loop invariant i - l - count <= i - l;
        loop invariant i - l - count <= i - l + 1;
        loop invariant count >= 0 && i >= l;
        loop invariant count > 0 ==> \exists integer k; l <= k < i && k % a != 0;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 || count <= i - l + 1;
        loop invariant count == 0 || \exists integer k; l <= k < i && k % a != 0;
        loop invariant count == 0 ==> \forall integer k; l <= k < i ==> k % a == 0;
        loop invariant count <= i - l;
        loop invariant count <= i - l + 1;
        loop invariant count - 1 <= i - l;
        loop invariant count - (i - l) <= 1;
        loop invariant \forall integer k; l <= k < i ==> count >= 0;
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 || k % a != 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 || count >= 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 || count > 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 ==> count >= 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 1);
        loop invariant \forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a != 0 ==> count > 0);
        loop invariant \forall integer k; l <= k < i && k % a == 0 ==> count <= i - l + 1;
        loop invariant \forall integer k; l <= k < i && k % a != 0 ==> count >= 1;
        loop invariant 0 <= i - l - count;
        loop invariant 0 <= count;
        loop invariant -1 <= i - l - count;
        loop assigns i;
        loop assigns count;*/
int stub_B(int a, int n, int l, int r);

/*@loop invariant l <= i;
        loop invariant i - l - count <= i - l;
        loop invariant i - l - count <= i - l + 1;
        loop invariant count >= 0 && i >= l;
        loop invariant count > 0 ==> \exists integer k; l <= k < i && k % a != 0;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 || count <= i - l + 1;
        loop invariant count == 0 || \exists integer k; l <= k < i && k % a != 0;
        loop invariant count == 0 ==> \forall integer k; l <= k < i ==> k % a == 0;
        loop invariant count <= i - l;
        loop invariant count <= i - l + 1;
        loop invariant count - 1 <= i - l;
        loop invariant count - (i - l) <= 1;
        loop invariant \forall integer k; l <= k < i ==> count >= 0;
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 || k % a != 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 || count >= 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 || count > 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a == 0 ==> count >= 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 1);
        loop invariant \forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 0);
        loop invariant \forall integer k; l <= k < i ==> (k % a != 0 ==> count > 0);
        loop invariant \forall integer k; l <= k < i && k % a == 0 ==> count <= i - l + 1;
        loop invariant \forall integer k; l <= k < i && k % a != 0 ==> count >= 1;
        loop invariant 0 <= i - l - count;
        loop invariant 0 <= count;
        loop invariant -1 <= i - l - count;
        loop assigns i;
        loop assigns count;*/
int check_A_implies_B(int a, int n, int l, int r) {
    return stub_A(a, n, l, r);
}

/*@requires a != 0;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= r;
  ensures \result != -1 ==> nondiv_count(a, l, \result) == n;
  ensures \result == -1 || (l <= \result && \result <= r);
  ensures \result == -1 || (nondiv_count(a, l, \result) == n);*/
int check_B_implies_A(int a, int n, int l, int r) {
    return stub_B(a, n, l, r);
}
