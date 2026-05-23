#include <limits.h>


/*@ logic integer count_divisors(integer n, integer start, integer end) =
      end <= start ? 0 :
      ((n % (end - 1) == 0)
         ? count_divisors(n, start, end - 1) + 1
         : count_divisors(n, start, end - 1));
*/

/*@assigns \nothing;
  ensures \result != \null;*/
const char * stub_A(int n);

/*@loop invariant i - count <= n || i - count <= i;
        loop invariant i - count <= i;
        loop invariant i - count <= i || i <= n + 1;
        loop invariant count == 0 || count > 0;
        loop invariant count <= i;
        loop invariant count <= i-1;
        loop invariant count <= i - 1;
        loop invariant count <= i - 1 || i == 1;
        loop invariant count <= i - 1 || count == i;
        loop invariant count <= i + 1;
        loop invariant count <= i && count >= 0;
        loop invariant count - i <= 0;
        loop invariant count % 2 == i % 2 || count % 2 == (i - 1) % 2;
        loop invariant count % 2 == i % 2 || count % 2 == (i + 1) % 2;
        loop invariant count % 2 == 0 || count % 2 == 1;
        loop invariant count % 2 == (i - 1) % 2 || count % 2 == i % 2;
        loop invariant \forall integer k; 1 <= k < i ==> count >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i && n % k == 0 ==> count >= 1;
        loop invariant \forall integer k; 1 <= k < i && n % k != 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 1;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 1 <= i - count;
        loop invariant 0 <= i - count;
        loop invariant 0 <= i - count || i <= n + 1;
        loop invariant 0 <= count;
        loop invariant 0 < i - count;
        loop assigns i;
        loop assigns count;*/
const char * stub_B(int n);

/*@loop invariant i - count <= n || i - count <= i;
        loop invariant i - count <= i;
        loop invariant i - count <= i || i <= n + 1;
        loop invariant count == 0 || count > 0;
        loop invariant count <= i;
        loop invariant count <= i-1;
        loop invariant count <= i - 1;
        loop invariant count <= i - 1 || i == 1;
        loop invariant count <= i - 1 || count == i;
        loop invariant count <= i + 1;
        loop invariant count <= i && count >= 0;
        loop invariant count - i <= 0;
        loop invariant count % 2 == i % 2 || count % 2 == (i - 1) % 2;
        loop invariant count % 2 == i % 2 || count % 2 == (i + 1) % 2;
        loop invariant count % 2 == 0 || count % 2 == 1;
        loop invariant count % 2 == (i - 1) % 2 || count % 2 == i % 2;
        loop invariant \forall integer k; 1 <= k < i ==> count >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 1);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0 ==> count >= 0);
        loop invariant \forall integer k; 1 <= k < i && n % k == 0 ==> count >= 1;
        loop invariant \forall integer k; 1 <= k < i && n % k != 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 1;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count >= 0;
        loop invariant \exists integer k; 1 <= k < i && n % k == 0 ==> count > 0;
        loop invariant 1 <= i;
        loop invariant 1 <= i - count;
        loop invariant 0 <= i - count;
        loop invariant 0 <= i - count || i <= n + 1;
        loop invariant 0 <= count;
        loop invariant 0 < i - count;
        loop assigns i;
        loop assigns count;*/
const char * check_A_implies_B(int n) {
    return stub_A(n);
}

/*@assigns \nothing;
  ensures \result != \null;*/
const char * check_B_implies_A(int n) {
    return stub_B(n);
}
