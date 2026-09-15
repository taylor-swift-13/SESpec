#include <limits.h>

/*@ logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1); */

/*@ requires (1 <= loop <= num + 1) && (ret == fact(loop - 1));
    assigns \nothing;
*/
void check_A_implies_B(int k, int num, int *ret) {
    /*@ assert (loop == 1 || ret >= 1); */
    /*@ assert (0 <= loop - 1); */
    /*@ assert (ret >= 1 && loop >= 1); */
    /*@ assert (ret == 1 || ret >= loop - 1); */
    /*@ assert (ret == 1 || ret >= 1); */
    /*@ assert (ret == 1 || ret > 1); */
    /*@ assert (ret == 1 || ret > 0); */
    /*@ assert (ret == 1 || ret % 2 == 0); */
    /*@ assert (ret == 1 || ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (ret == (loop - 1) * ret || ret > 0); */
    /*@ assert (ret <= loop || loop <= num + 1); */
    /*@ assert (ret <= loop * ret); */
    /*@ assert (ret % 2 == loop % 2 || ret % 2 != loop % 2); */
    /*@ assert (ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (ret % 100 >= 0 && ret % 100 < 100); */
    /*@ assert (ret % 100 == ret % 100); */
    /*@ assert (ret % 100 == (ret % 100)); */
    /*@ assert (ret % 100 == (1 <= loop ? ret % 100 : ret % 100)); */
    /*@ assert (loop > 1 ==> ret >= loop - 1); */
    /*@ assert (loop > 1 ==> ret >= 1); */
    /*@ assert (loop > 1 ==> ret > 0); */
    /*@ assert (loop > 0 ==> ret >= loop - 1); */
    /*@ assert (loop > 0 ==> ret >= 1); */
    /*@ assert (loop > 0 ==> ret > 0); */
    /*@ assert (loop == 1 || ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (loop == 1 || loop > 1); */
    /*@ assert (loop == 1 ==> ret == 1); */
    /*@ assert (loop <= ret || loop <= num + 1); */
    /*@ assert (loop <= num + 1 || loop <= ret); */
    /*@ assert (loop - 1 <= ret); */
    /*@ assert (loop % 2 == 0 || loop % 2 == 1); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ret >= k); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ret >= 1); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ret > 0); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ret % 2 == (k % 2 == 0 ? ret % 2 : ret % 2)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ret % 100 == ret % 100); */
    /*@ assert (\exists integer k; 1 <= k <= loop && ret >= 1); */
    /*@ assert (\exists integer k; 1 <= k <= loop && ret > 0); */
    /*@ assert (1 <= ret); */
    /*@ assert (1 <= ret || loop == 1); */
    /*@ assert (1 <= loop); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= loop); */
    /*@ assert (0 < ret); */
    /*@ assert (0 < loop); */
}

/*@ requires (loop == 1 || ret >= 1) && (0 <= loop - 1) && (ret >= 1 && loop >= 1) && (ret == 1 || ret >= loop - 1) && (ret == 1 || ret >= 1) && (ret == 1 || ret > 1) && (ret == 1 || ret > 0) && (ret == 1 || ret % 2 == 0) && (ret == 1 || ret % 2 == 0 || ret % 2 == 1) && (ret == (loop - 1) * ret || ret > 0) && (ret <= loop || loop <= num + 1) && (ret <= loop * ret) && (ret % 2 == loop % 2 || ret % 2 != loop % 2) && (ret % 2 == 0 || ret % 2 == 1) && (ret % 100 >= 0 && ret % 100 < 100) && (ret % 100 == ret % 100) && (ret % 100 == (ret % 100)) && (ret % 100 == (1 <= loop ? ret % 100 : ret % 100)) && (loop > 1 ==> ret >= loop - 1) && (loop > 1 ==> ret >= 1) && (loop > 1 ==> ret > 0) && (loop > 0 ==> ret >= loop - 1) && (loop > 0 ==> ret >= 1) && (loop > 0 ==> ret > 0) && (loop == 1 || ret % 2 == 0 || ret % 2 == 1) && (loop == 1 || loop > 1) && (loop == 1 ==> ret == 1) && (loop <= ret || loop <= num + 1) && (loop <= num + 1 || loop <= ret) && (loop - 1 <= ret) && (loop % 2 == 0 || loop % 2 == 1) && (\forall integer k; 1 <= k < loop ==> ret >= k) && (\forall integer k; 1 <= k < loop ==> ret >= 1) && (\forall integer k; 1 <= k < loop ==> ret > 0) && (\forall integer k; 1 <= k < loop ==> ret % 2 == 0 || ret % 2 == 1) && (\forall integer k; 1 <= k < loop ==> ret % 2 == (k % 2 == 0 ? ret % 2 : ret % 2)) && (\forall integer k; 1 <= k < loop ==> ret % 100 == ret % 100) && (\exists integer k; 1 <= k <= loop && ret >= 1) && (\exists integer k; 1 <= k <= loop && ret > 0) && (1 <= ret) && (1 <= ret || loop == 1) && (1 <= loop) && (0 <= ret) && (0 <= loop) && (0 < ret) && (0 < loop);
    assigns \nothing;
*/
void check_B_implies_A(int k, int num, int *ret) {
    /*@ assert (1 <= loop <= num + 1); */
    /*@ assert (ret == fact(loop - 1)); */
}
