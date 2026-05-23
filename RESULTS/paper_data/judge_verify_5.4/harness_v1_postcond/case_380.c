#include <limits.h>


/*@ logic integer proper_divisor_sum(integer n, integer i) =
      i <= 1 ? 0 :
      proper_divisor_sum(n, i - 1) +
      (((i - 1) != 0 && n % (i - 1) == 0) ? (i - 1) : 0);
*/

/*@assigns \nothing;
  
  ensures \result >= 0;*/
int stub_A(int number);

/*@loop invariant number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0;
        loop invariant sum == 0 || sum >= 1;
        loop invariant sum == 0 || sum > 0;
        loop invariant sum % i == 0 || sum % i != 0;
        loop invariant sum % 2 == 0 || sum % 2 == 1;
        loop invariant sum % 1 == 0;
        loop invariant number >= 1 ==> sum >= 0;
        loop invariant number >= 1 ==> sum <= number * i;
        loop invariant number >= 1 ==> sum <= i * number;
        loop invariant number >= 1 ==> sum + i >= 1;
        loop invariant number >= 1 ==> sum % i == 0 || sum % i != 0;
        loop invariant number >= 1 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant number >= 1 ==> i >= 1;
        loop invariant number >= 1 ==> i <= number;
        loop invariant number >= 1 ==> i <= number / 2 + 1;
        loop invariant number >= 1 ==> i <= number + 1;
        loop invariant number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k);
        loop invariant number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k);
        loop invariant number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0);
        loop invariant number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k;
        loop invariant number >= 1 ==> 1 <= i;
        loop invariant number >= 1 ==> 1 <= i <= number / 2 + 1;
        loop invariant number >= 1 ==> (sum == 0 || sum >= 1);
        loop invariant number >= 0 || i == 1;
        loop invariant number >= 0 ==> sum >= 0;
        loop invariant number >= 0 ==> i >= 1;
        loop invariant number >= 0 ==> i <= number + 1;
        loop invariant number % i == 0 || number % i != 0;
        loop invariant i > 1 ==> sum >= 0;
        loop invariant i == 1 ==> sum == 0;
        loop invariant \forall integer k; 1 <= k < i ==> sum >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> number % k == 0 || number % k != 0;
        loop invariant \forall integer k; 1 <= k < i ==> (sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 || number % k != 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum + k >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k != 0 ==> sum >= 0);
        loop invariant \forall integer k; 1 <= k < i && number % k == 0 ==> sum >= k;
        loop invariant \forall integer k; 1 <= k < i && number % k == 0 ==> sum >= 0;
        loop invariant \forall integer k; 1 <= k < i && number % k != 0 ==> sum >= 0;
        loop invariant \exists integer k; 1 <= k <= i ==> (number % k == 0 || number % k != 0);
        loop invariant \exists integer k; 1 <= k <= i && number % k == 0;
        loop invariant \exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k;
        loop invariant \exists integer k; 1 <= k <= i && (number % k == 0);
        loop invariant \exists integer k; 1 <= k < i && number % k == 0 ==> sum >= k;
        loop invariant \exists integer k; 0 <= k < i && (number % k == 0 ==> sum >= k);
        loop invariant 1 <= i;
        loop invariant 1 <= i || number <= 1;
        loop invariant 0 <= sum;
        loop invariant 0 <= sum + i;
        loop invariant 0 <= i;
        loop assigns sum;
        loop assigns i;*/
int stub_B(int number);

/*@loop invariant number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0;
        loop invariant sum == 0 || sum >= 1;
        loop invariant sum == 0 || sum > 0;
        loop invariant sum % i == 0 || sum % i != 0;
        loop invariant sum % 2 == 0 || sum % 2 == 1;
        loop invariant sum % 1 == 0;
        loop invariant number >= 1 ==> sum >= 0;
        loop invariant number >= 1 ==> sum <= number * i;
        loop invariant number >= 1 ==> sum <= i * number;
        loop invariant number >= 1 ==> sum + i >= 1;
        loop invariant number >= 1 ==> sum % i == 0 || sum % i != 0;
        loop invariant number >= 1 ==> sum % 2 == 0 || sum % 2 == 1;
        loop invariant number >= 1 ==> i >= 1;
        loop invariant number >= 1 ==> i <= number;
        loop invariant number >= 1 ==> i <= number / 2 + 1;
        loop invariant number >= 1 ==> i <= number + 1;
        loop invariant number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k);
        loop invariant number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k);
        loop invariant number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0);
        loop invariant number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k;
        loop invariant number >= 1 ==> 1 <= i;
        loop invariant number >= 1 ==> 1 <= i <= number / 2 + 1;
        loop invariant number >= 1 ==> (sum == 0 || sum >= 1);
        loop invariant number >= 0 || i == 1;
        loop invariant number >= 0 ==> sum >= 0;
        loop invariant number >= 0 ==> i >= 1;
        loop invariant number >= 0 ==> i <= number + 1;
        loop invariant number % i == 0 || number % i != 0;
        loop invariant i > 1 ==> sum >= 0;
        loop invariant i == 1 ==> sum == 0;
        loop invariant \forall integer k; 1 <= k < i ==> sum >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> number % k == 0 || number % k != 0;
        loop invariant \forall integer k; 1 <= k < i ==> (sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 || number % k != 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum + k >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (number % k != 0 ==> sum >= 0);
        loop invariant \forall integer k; 1 <= k < i && number % k == 0 ==> sum >= k;
        loop invariant \forall integer k; 1 <= k < i && number % k == 0 ==> sum >= 0;
        loop invariant \forall integer k; 1 <= k < i && number % k != 0 ==> sum >= 0;
        loop invariant \exists integer k; 1 <= k <= i ==> (number % k == 0 || number % k != 0);
        loop invariant \exists integer k; 1 <= k <= i && number % k == 0;
        loop invariant \exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k;
        loop invariant \exists integer k; 1 <= k <= i && (number % k == 0);
        loop invariant \exists integer k; 1 <= k < i && number % k == 0 ==> sum >= k;
        loop invariant \exists integer k; 0 <= k < i && (number % k == 0 ==> sum >= k);
        loop invariant 1 <= i;
        loop invariant 1 <= i || number <= 1;
        loop invariant 0 <= sum;
        loop invariant 0 <= sum + i;
        loop invariant 0 <= i;
        loop assigns sum;
        loop assigns i;*/
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@assigns \nothing;
  
  ensures \result >= 0;*/
int check_B_implies_A(int number) {
    return stub_B(number);
}
