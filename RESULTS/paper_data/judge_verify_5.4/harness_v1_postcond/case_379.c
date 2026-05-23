#include <limits.h>


/*@
  logic integer even_sum(integer a, integer b) =
    a > b ? 0 :
    (a % 2 == 0 ? a : 0) + even_sum(a + 1, b);
*/

/*@requires l <= r + 1;
  assigns \nothing;*/
int stub_A(int l, int r);

/*@loop invariant sum % 2 == 0 ==> i >= l;
        loop invariant sum >= 0 || i <= r + 1;
        loop invariant sum >= 0 ==> i >= l;
        loop invariant sum == 0 || sum % 2 == 0;
        loop invariant sum % 2 == 0;
        loop invariant sum % 2 == 0 || sum % 2 == 1;
        loop invariant l <= i;
        loop invariant i == l ==> sum == 0;
        loop invariant i == l + (i - l);
        loop invariant i <= r + 1 || 0 <= sum;
        loop invariant i <= r + 1 || 0 <= i - l;
        loop invariant i <= r + 1 ==> i - l <= r - l + 1;
        loop invariant i <= r + 1 ==> (sum % 2 == 0 || sum % 2 == 1);
        loop invariant i % 2 == 0 ==> sum % 2 == 0;
        loop invariant \forall integer k; l <= k < i ==> (sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 == 1 ==> sum == sum);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum == sum);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; l <= k < i && k % 2 == 1 ==> sum % 2 == 0;
        loop invariant \forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0;
        loop invariant \forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant \forall integer k; l <= k < i && k % 2 != 0 ==> sum == sum;
        loop invariant \forall integer k; l <= k < i && k % 2 != 0 ==> sum % 2 == 0;
        loop invariant \exists integer k; l <= k <= i ==> (k % 2 == 0 ==> sum >= 0);
        loop invariant \exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= k;
        loop invariant \exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= 0;
        loop invariant \exists integer k; l <= k < i && k % 2 == 0 ==> sum >= k;
        loop invariant \exists integer k; l <= k < i && k % 2 == 0 ==> sum >= 0;
        loop invariant 0 <= sum || i <= r+1;
        loop invariant 0 <= sum || i <= r + 1;
        loop invariant 0 <= sum || i - l <= r - l + 1;
        loop invariant 0 <= sum || 0 <= (i - l);
        loop invariant 0 <= i - l;
        loop invariant 0 <= i - l || i <= r+1;
        loop invariant 0 <= i - l || 0 <= sum;
        loop invariant 0 <= (i - l);
        loop invariant 0 <= (i - l) || i <= r + 1;
        loop invariant 0 <= (i - l) || i - l <= r - l + 1;
        loop assigns sum;
        loop assigns i;*/
int stub_B(int l, int r);

/*@loop invariant sum % 2 == 0 ==> i >= l;
        loop invariant sum >= 0 || i <= r + 1;
        loop invariant sum >= 0 ==> i >= l;
        loop invariant sum == 0 || sum % 2 == 0;
        loop invariant sum % 2 == 0;
        loop invariant sum % 2 == 0 || sum % 2 == 1;
        loop invariant l <= i;
        loop invariant i == l ==> sum == 0;
        loop invariant i == l + (i - l);
        loop invariant i <= r + 1 || 0 <= sum;
        loop invariant i <= r + 1 || 0 <= i - l;
        loop invariant i <= r + 1 ==> i - l <= r - l + 1;
        loop invariant i <= r + 1 ==> (sum % 2 == 0 || sum % 2 == 1);
        loop invariant i % 2 == 0 ==> sum % 2 == 0;
        loop invariant \forall integer k; l <= k < i ==> (sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 == 1 ==> sum == sum);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum == sum);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0);
        loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; l <= k < i && k % 2 == 1 ==> sum % 2 == 0;
        loop invariant \forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0;
        loop invariant \forall integer k; l <= k < i && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant \forall integer k; l <= k < i && k % 2 != 0 ==> sum == sum;
        loop invariant \forall integer k; l <= k < i && k % 2 != 0 ==> sum % 2 == 0;
        loop invariant \exists integer k; l <= k <= i ==> (k % 2 == 0 ==> sum >= 0);
        loop invariant \exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= k;
        loop invariant \exists integer k; l <= k <= i && k % 2 == 0 ==> sum >= 0;
        loop invariant \exists integer k; l <= k < i && k % 2 == 0 ==> sum >= k;
        loop invariant \exists integer k; l <= k < i && k % 2 == 0 ==> sum >= 0;
        loop invariant 0 <= sum || i <= r+1;
        loop invariant 0 <= sum || i <= r + 1;
        loop invariant 0 <= sum || i - l <= r - l + 1;
        loop invariant 0 <= sum || 0 <= (i - l);
        loop invariant 0 <= i - l;
        loop invariant 0 <= i - l || i <= r+1;
        loop invariant 0 <= i - l || 0 <= sum;
        loop invariant 0 <= (i - l);
        loop invariant 0 <= (i - l) || i <= r + 1;
        loop invariant 0 <= (i - l) || i - l <= r - l + 1;
        loop assigns sum;
        loop assigns i;*/
int check_A_implies_B(int l, int r) {
    return stub_A(l, r);
}

/*@requires l <= r + 1;
  assigns \nothing;*/
int check_B_implies_A(int l, int r) {
    return stub_B(l, r);
}
