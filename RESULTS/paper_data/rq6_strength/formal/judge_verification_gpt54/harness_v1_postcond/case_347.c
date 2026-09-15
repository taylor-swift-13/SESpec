#include <limits.h>


/*@
  logic integer nb_divisors(integer x, integer n) =
    n <= 0 ? 0 : nb_divisors(x, n - 1) + (x % n == 0 ? 1 : 0);
*/

/*@assigns \nothing;
  ensures \old(y) >= 0 ==> \result == nb_divisors(x, \old(y));
  ensures \old(y) < 0 ==> \result == nb_divisors(x, -\old(y));
  ensures \result >= 0;
  ensures \result <= (\old(y) < 0 ? -\old(y) : \old(y));*/
int stub_A(int x, int y);

/*@loop invariant i > 1 ==> count <= i - 1;
        loop invariant i == 1 ==> count == 0;
        loop invariant i <= y + 1;
        loop invariant i <= y + 1 ==> count <= y;
        loop invariant count > 0 ==> \exists integer k; 1 <= k < i && x % k == 0;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 ==> \forall integer k; 1 <= k < i ==> x % k != 0;
        loop invariant count <= y;
        loop invariant count <= y + 1;
        loop invariant count <= i;
        loop invariant count <= i - 1;
        loop invariant count <= i + 1;
        loop invariant count < i;
        loop invariant count < i + 1;
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 || x % k != 0);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k != 0 || count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k != 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k == 0) ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k != 0) ==> count >= 0);
        loop invariant \exists integer k; 1 <= k < i && x % k == 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && x % k == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 0 <= y;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop invariant 0 < i;
        loop assigns i;
        loop assigns count;*/
int stub_B(int x, int y);

/*@loop invariant i > 1 ==> count <= i - 1;
        loop invariant i == 1 ==> count == 0;
        loop invariant i <= y + 1;
        loop invariant i <= y + 1 ==> count <= y;
        loop invariant count > 0 ==> \exists integer k; 1 <= k < i && x % k == 0;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 ==> \forall integer k; 1 <= k < i ==> x % k != 0;
        loop invariant count <= y;
        loop invariant count <= y + 1;
        loop invariant count <= i;
        loop invariant count <= i - 1;
        loop invariant count <= i + 1;
        loop invariant count < i;
        loop invariant count < i + 1;
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 || x % k != 0);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> count <= i);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k != 0 || count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k != 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k == 0) ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k != 0) ==> count >= 0);
        loop invariant \exists integer k; 1 <= k < i && x % k == 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && x % k == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 0 <= y;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop invariant 0 < i;
        loop assigns i;
        loop assigns count;*/
int check_A_implies_B(int x, int y) {
    return stub_A(x, y);
}

/*@assigns \nothing;
  ensures \old(y) >= 0 ==> \result == nb_divisors(x, \old(y));
  ensures \old(y) < 0 ==> \result == nb_divisors(x, -\old(y));
  ensures \result >= 0;
  ensures \result <= (\old(y) < 0 ? -\old(y) : \old(y));*/
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
