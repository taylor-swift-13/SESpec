#include <limits.h>

/*@ logic integer proper_divisor_sum(integer n, integer i) =
      i <= 1 ? 0 :
      proper_divisor_sum(n, i - 1) +
      (((i - 1) != 0 && n % (i - 1) == 0) ? (i - 1) : 0); */

/*@ requires (0 <= i) && (0 <= sum) && (number == \at(number,Pre)) && (sum <= (i - 1) * i / 2) && (sum == proper_divisor_sum(number, i)) && (\forall integer j; 1 <= j < i && number % j == 0 ==> sum >= j) && (\exists integer j; 0 <= j < i ==> (j == 0 || j < i)) && ((i <= \at(number,Pre) / 2) ==> (sum >= 0)) && ((i <= \at(number,Pre) / 2) ==> (sum == proper_divisor_sum(number, i))) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *i, int j, int k, int *number) {
    /*@ assert (number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0); */
    /*@ assert (sum == 0 || sum >= 1); */
    /*@ assert (sum == 0 || sum > 0); */
    /*@ assert (sum % i == 0 || sum % i != 0); */
    /*@ assert (sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (sum % 1 == 0); */
    /*@ assert (number >= 1 ==> sum >= 0); */
    /*@ assert (number >= 1 ==> sum <= number * i); */
    /*@ assert (number >= 1 ==> sum <= i * number); */
    /*@ assert (number >= 1 ==> sum + i >= 1); */
    /*@ assert (number >= 1 ==> sum % i == 0 || sum % i != 0); */
    /*@ assert (number >= 1 ==> sum % 2 == 0 || sum % 2 == 1); */
    /*@ assert (number >= 1 ==> i >= 1); */
    /*@ assert (number >= 1 ==> i <= number); */
    /*@ assert (number >= 1 ==> i <= number / 2 + 1); */
    /*@ assert (number >= 1 ==> i <= number + 1); */
    /*@ assert (number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k)); */
    /*@ assert (number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k)); */
    /*@ assert (number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0)); */
    /*@ assert (number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k); */
    /*@ assert (number >= 1 ==> 1 <= i); */
    /*@ assert (number >= 1 ==> 1 <= i <= number / 2 + 1); */
    /*@ assert (number >= 1 ==> (sum == 0 || sum >= 1)); */
    /*@ assert (number >= 0 || i == 1); */
    /*@ assert (number >= 0 ==> sum >= 0); */
    /*@ assert (number >= 0 ==> i >= 1); */
    /*@ assert (number >= 0 ==> i <= number + 1); */
    /*@ assert (number % i == 0 || number % i != 0); */
    /*@ assert (i > 1 ==> sum >= 0); */
    /*@ assert (i == 1 ==> sum == 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> sum >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> number % k == 0 || number % k != 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (sum >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k == 0 || number % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum + k >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (number % k != 0 ==> sum >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i && number % k == 0 ==> sum >= k); */
    /*@ assert (\forall integer k; 1 <= k < i && number % k == 0 ==> sum >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i && number % k != 0 ==> sum >= 0); */
    /*@ assert (\exists integer k; 1 <= k <= i ==> (number % k == 0 || number % k != 0)); */
    /*@ assert (\exists integer k; 1 <= k <= i && number % k == 0); */
    /*@ assert (\exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k); */
    /*@ assert (\exists integer k; 1 <= k <= i && (number % k == 0)); */
    /*@ assert (\exists integer k; 1 <= k < i && number % k == 0 ==> sum >= k); */
    /*@ assert (\exists integer k; 0 <= k < i && (number % k == 0 ==> sum >= k)); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= i || number <= 1); */
    /*@ assert (0 <= sum); */
    /*@ assert (0 <= sum + i); */
    /*@ assert (0 <= i); */
}

/*@ requires (number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0) && (sum == 0 || sum >= 1) && (sum == 0 || sum > 0) && (sum % i == 0 || sum % i != 0) && (sum % 2 == 0 || sum % 2 == 1) && (sum % 1 == 0) && (number >= 1 ==> sum >= 0) && (number >= 1 ==> sum <= number * i) && (number >= 1 ==> sum <= i * number) && (number >= 1 ==> sum + i >= 1) && (number >= 1 ==> sum % i == 0 || sum % i != 0) && (number >= 1 ==> sum % 2 == 0 || sum % 2 == 1) && (number >= 1 ==> i >= 1) && (number >= 1 ==> i <= number) && (number >= 1 ==> i <= number / 2 + 1) && (number >= 1 ==> i <= number + 1) && (number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k)) && (number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k)) && (number >= 1 ==> \forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0)) && (number >= 1 ==> \exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k) && (number >= 1 ==> 1 <= i) && (number >= 1 ==> 1 <= i <= number / 2 + 1) && (number >= 1 ==> (sum == 0 || sum >= 1)) && (number >= 0 || i == 1) && (number >= 0 ==> sum >= 0) && (number >= 0 ==> i >= 1) && (number >= 0 ==> i <= number + 1) && (number % i == 0 || number % i != 0) && (i > 1 ==> sum >= 0) && (i == 1 ==> sum == 0) && (\forall integer k; 1 <= k < i ==> sum >= 0) && (\forall integer k; 1 <= k < i ==> number % k == 0 || number % k != 0) && (\forall integer k; 1 <= k < i ==> (sum >= 0)) && (\forall integer k; 1 <= k < i ==> (number % k == 0 || number % k != 0)) && (\forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= k)) && (\forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum >= 0)) && (\forall integer k; 1 <= k < i ==> (number % k == 0 ==> sum + k >= 0)) && (\forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= k)) && (\forall integer k; 1 <= k < i ==> (number % k != 0 || sum >= 0)) && (\forall integer k; 1 <= k < i ==> (number % k != 0 ==> sum >= 0)) && (\forall integer k; 1 <= k < i && number % k == 0 ==> sum >= k) && (\forall integer k; 1 <= k < i && number % k == 0 ==> sum >= 0) && (\forall integer k; 1 <= k < i && number % k != 0 ==> sum >= 0) && (\exists integer k; 1 <= k <= i ==> (number % k == 0 || number % k != 0)) && (\exists integer k; 1 <= k <= i && number % k == 0) && (\exists integer k; 1 <= k <= i && number % k == 0 ==> sum >= k) && (\exists integer k; 1 <= k <= i && (number % k == 0)) && (\exists integer k; 1 <= k < i && number % k == 0 ==> sum >= k) && (\exists integer k; 0 <= k < i && (number % k == 0 ==> sum >= k)) && (1 <= i) && (1 <= i || number <= 1) && (0 <= sum) && (0 <= sum + i) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *i, int j, int k, int *number) {
    /*@ assert (0 <= i); */
    /*@ assert (0 <= sum); */
    /*@ assert (number == \at(number,Pre)); */
    /*@ assert (sum <= (i - 1) * i / 2); */
    /*@ assert (sum == proper_divisor_sum(number, i)); */
    /*@ assert (\forall integer j; 1 <= j < i && number % j == 0 ==> sum >= j); */
    /*@ assert (\exists integer j; 0 <= j < i ==> (j == 0 || j < i)); */
    /*@ assert ((i <= \at(number,Pre) / 2) ==> (sum >= 0)); */
    /*@ assert ((i <= \at(number,Pre) / 2) ==> (sum == proper_divisor_sum(number, i))); */
    /*@ assert (number == \at(number,Pre)); */
}
