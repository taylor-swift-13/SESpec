#include <limits.h>


/*@
  logic integer common_divisor_count(integer x, integer y, integer n) =
    n <= 0 ? 0 :
    common_divisor_count(x, y, n - 1) +
    ((x % n == 0 && y % n == 0) ? 1 : 0);
*/

/*@assigns \nothing;
  
  ensures \result >= 0;*/
int stub_A(int x, int y);

/*@loop invariant count >= 0 && count <= i - 1;
        loop invariant count > 0 ==> i > 1;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count >= 0;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 ==> i == 1;
        loop invariant count <= i;
        loop invariant count <= i - 1;
        loop invariant count <= i - 1 || count == i;
        loop invariant count <= i - 1 || count <= i;
        loop invariant count <= i + 1;
        loop invariant count <= i && count >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> (x % k != 0 || y % k != 0 || count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> count >= 1;
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 || y % d == 0 || count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 1);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i - 1);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d != 0 || y % d != 0 || count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 1);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i - 1);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d != 0 || y % d != 0) || count >= 0);
        loop invariant \forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1;
        loop invariant \forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0;
        loop invariant \exists integer d; 1 <= d <= i && x % d == 0 && y % d == 0;
        loop invariant \exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1;
        loop invariant \exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 0;
        loop invariant \exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns i;
        loop assigns count;*/
int stub_B(int x, int y);

/*@loop invariant count >= 0 && count <= i - 1;
        loop invariant count > 0 ==> i > 1;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count >= 0;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 ==> i == 1;
        loop invariant count <= i;
        loop invariant count <= i - 1;
        loop invariant count <= i - 1 || count == i;
        loop invariant count <= i - 1 || count <= i;
        loop invariant count <= i + 1;
        loop invariant count <= i && count >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> (x % k != 0 || y % k != 0 || count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> count >= 1;
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 || y % d == 0 || count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 1);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i - 1);
        loop invariant \forall integer d; 1 <= d < i ==> (x % d != 0 || y % d != 0 || count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 1);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 0);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i - 1);
        loop invariant \forall integer d; 1 <= d < i ==> ((x % d != 0 || y % d != 0) || count >= 0);
        loop invariant \forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1;
        loop invariant \forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0;
        loop invariant \exists integer d; 1 <= d <= i && x % d == 0 && y % d == 0;
        loop invariant \exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1;
        loop invariant \exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 0;
        loop invariant \exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns i;
        loop assigns count;*/
int check_A_implies_B(int x, int y) {
    return stub_A(x, y);
}

/*@assigns \nothing;
  
  ensures \result >= 0;*/
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
