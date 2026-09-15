#include <limits.h>


/*@ logic integer evendiv_sum(integer n, integer i) =
      i < 2 ? 0 :
      evendiv_sum(n, i - 1) + ((n % i == 0 && i % 2 == 0) ? i : 0);
*/

/*@assigns \nothing;
  
  ensures \result >= 0;
  ensures n < 2 ==> \result == 0;*/
int stub_A(int n);

/*@loop invariant sum >= 0 && i >= 2;
        loop invariant i == 2 || i > 2;
        loop invariant sum == 0 || sum >= 2;
        loop invariant sum == 0 || sum >= 0;
        loop invariant sum == 0 || sum > 0;
        loop invariant sum <= n * n || i <= n+1;
        loop invariant sum <= n * n || i <= n + 1;
        loop invariant sum % 2 == 0;
        loop invariant sum % 2 == 0 || sum % 2 == 1;
        loop invariant sum % 2 == 0 ==> sum >= 0;
        loop invariant sum % 2 == 0 ==> sum == 0 || sum % 2 == 0;
        loop invariant i >= 2 ==> sum >= 0;
        loop invariant i > 2 ==> sum >= 0;
        loop invariant i <= n+1 || sum <= n*(n+1)/2;
        loop invariant i <= n+1 || sum <= n * (n + 1) / 2;
        loop invariant i <= n + 1 || sum <= n*(n+1)/2;
        loop invariant i <= n + 1 || sum <= n * (n + 1) / 2;
        loop invariant i % 2 == 0 || i % 2 == 1;
        loop invariant \forall integer k; 2 <= k < i ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum == sum);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= k);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 2);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum == sum);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= k);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (k % 2 == 0 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 1 ==> sum % 2 == 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= k;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 2;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 != 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k != 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k != 0 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant \exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= k;
        loop invariant \exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= 0;
        loop invariant 2 <= i;
        loop invariant 0 <= sum;
        loop assigns sum;
        loop assigns i;*/
int stub_B(int n);

/*@loop invariant sum >= 0 && i >= 2;
        loop invariant i == 2 || i > 2;
        loop invariant sum == 0 || sum >= 2;
        loop invariant sum == 0 || sum >= 0;
        loop invariant sum == 0 || sum > 0;
        loop invariant sum <= n * n || i <= n+1;
        loop invariant sum <= n * n || i <= n + 1;
        loop invariant sum % 2 == 0;
        loop invariant sum % 2 == 0 || sum % 2 == 1;
        loop invariant sum % 2 == 0 ==> sum >= 0;
        loop invariant sum % 2 == 0 ==> sum == 0 || sum % 2 == 0;
        loop invariant i >= 2 ==> sum >= 0;
        loop invariant i > 2 ==> sum >= 0;
        loop invariant i <= n+1 || sum <= n*(n+1)/2;
        loop invariant i <= n+1 || sum <= n * (n + 1) / 2;
        loop invariant i <= n + 1 || sum <= n*(n+1)/2;
        loop invariant i <= n + 1 || sum <= n * (n + 1) / 2;
        loop invariant i % 2 == 0 || i % 2 == 1;
        loop invariant \forall integer k; 2 <= k < i ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum == sum);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= k);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 2);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum == sum);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 != 0 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= k);
        loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || k % 2 != 0 || sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i ==> (k % 2 == 1 ==> sum % 2 == 0 || sum % 2 == 1);
        loop invariant \forall integer k; 2 <= k < i ==> (k % 2 == 0 ==> sum >= 0);
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 1 ==> sum % 2 == 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= k;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 2;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 == 0 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant \forall integer k; 2 <= k < i && n % k == 0 && k % 2 != 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k != 0 ==> sum >= 0;
        loop invariant \forall integer k; 2 <= k < i && n % k != 0 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant \exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= k;
        loop invariant \exists integer k; 2 <= k <= i && n % k == 0 && k % 2 == 0 ==> sum >= 0;
        loop invariant 2 <= i;
        loop invariant 0 <= sum;
        loop assigns sum;
        loop assigns i;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@assigns \nothing;
  
  ensures \result >= 0;
  ensures n < 2 ==> \result == 0;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
