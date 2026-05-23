#include <limits.h>


/*@ logic integer divcount(integer n, integer i) =
      i <= 1 ? 0 : divcount(n, i - 1) + ((n % (i - 1)) == 0 ? 1 : 0);
*/

/*@requires n >= 0;
  assigns \nothing;
  ensures \result == divcount(n, n + 1);
  ensures \result >= 0;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result >= 1;*/
int stub_A(int n);

/*@loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i + 1);
        loop invariant count >= 0 && i >= 1;
        loop invariant count >= 0 && count <= i;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count >= 0;
        loop invariant count == 0 || count > 0;
        loop invariant count <= i;
        loop invariant count <= i - 1;
        loop invariant count <= i - 1 || i <= n + 1;
        loop invariant count <= i - 1 || count == i;
        loop invariant count <= i + 1;
        loop invariant count <= i + 1 || i <= n + 1;
        loop invariant count <= i && count >= 0;
        loop invariant count <= i && 0 <= count;
        loop invariant count < i + 1;
        loop invariant \forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 || count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i + 1);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i + 1);
        loop invariant \exists integer k; 1 <= k <= i && (n % k == 0) ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 1;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop invariant 0 <= i - count;
        loop invariant 0 <= count;
        loop invariant 0 <= count <= i - 1 || i <= n + 1;
        loop assigns i;
        loop assigns count;*/
int stub_B(int n);

/*@loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i + 1);
        loop invariant count >= 0 && i >= 1;
        loop invariant count >= 0 && count <= i;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count >= 0;
        loop invariant count == 0 || count > 0;
        loop invariant count <= i;
        loop invariant count <= i - 1;
        loop invariant count <= i - 1 || i <= n + 1;
        loop invariant count <= i - 1 || count == i;
        loop invariant count <= i + 1;
        loop invariant count <= i + 1 || i <= n + 1;
        loop invariant count <= i && count >= 0;
        loop invariant count <= i && 0 <= count;
        loop invariant count < i + 1;
        loop invariant \forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 || count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i + 1);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i + 1);
        loop invariant \exists integer k; 1 <= k <= i && (n % k == 0) ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 1;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop invariant 0 <= i - count;
        loop invariant 0 <= count;
        loop invariant 0 <= count <= i - 1 || i <= n + 1;
        loop assigns i;
        loop assigns count;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@requires n >= 0;
  assigns \nothing;
  ensures \result == divcount(n, n + 1);
  ensures \result >= 0;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result >= 1;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
