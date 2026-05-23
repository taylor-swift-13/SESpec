#include <limits.h>

/*@logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1);*/

/*@ requires (1 <= loop <= num + 1) && (ret == fact(loop - 1));
    assigns \nothing;
*/
void check_A_implies_B(int k, int num, int ret) {
    /*@ assert (num < 0 ==> loop == 1) && (loop > 1 ==> ret % 100 >= 0) && (ret >= 1 && loop >= 1) && (ret == ret % 100 || ret > 99) && (ret == loop == 1 ? 1 : ret) && (ret == 1 || ret >= loop - 1) && (ret == 1 || ret >= 1) && (ret == 1 || ret > 0) && (ret == 1 || loop > 1) && (ret == (loop - 1) > 0 ? ret : 1) && (ret == (loop - 1) == 1 ? 1 : ret) && (ret <= ret * loop) && (ret <= loop * ret) && (ret % 2 == 0 || ret % 2 == 1) && (ret % 100 >= 0 && ret % 100 < 100) && (ret % 100 == ret - 100 * (ret / 100)) && (ret % 100 < 100) && (ret % 1 == 0) && (num >= 0 ==> ret >= loop - 1) && (num >= 0 ==> ret >= 1) && (num >= 0 ==> ret > 0) && (num >= 0 ==> ret <= ret * loop) && (num >= 0 ==> ret % 2 == 0 || ret % 2 == 1) && (num >= 0 ==> ret % 100 >= 0) && (num >= 0 ==> loop <= num + 1) && (loop > 1 ==> ret >= loop - 1) && (loop > 1 ==> ret >= 1) && (loop > 1 ==> ret > 0) && (loop > 1 ==> ret <= ret * loop) && (loop > 1 ==> ret % 2 == 0 || ret % 2 == 1) && (loop == 1 ==> ret == 1) && (loop <= ret || ret <= num * ret) && (loop <= ret || loop <= num + 1) && (loop - 1 <= ret) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= ret) && (1 <= loop) && (0 <= ret) && (0 <= ret % 100) && (0 <= loop) && (0 < ret) && (0 < loop); */
}

/*@ requires (num < 0 ==> loop == 1) && (loop > 1 ==> ret % 100 >= 0) && (ret >= 1 && loop >= 1) && (ret == ret % 100 || ret > 99) && (ret == loop == 1 ? 1 : ret) && (ret == 1 || ret >= loop - 1) && (ret == 1 || ret >= 1) && (ret == 1 || ret > 0) && (ret == 1 || loop > 1) && (ret == (loop - 1) > 0 ? ret : 1) && (ret == (loop - 1) == 1 ? 1 : ret) && (ret <= ret * loop) && (ret <= loop * ret) && (ret % 2 == 0 || ret % 2 == 1) && (ret % 100 >= 0 && ret % 100 < 100) && (ret % 100 == ret - 100 * (ret / 100)) && (ret % 100 < 100) && (ret % 1 == 0) && (num >= 0 ==> ret >= loop - 1) && (num >= 0 ==> ret >= 1) && (num >= 0 ==> ret > 0) && (num >= 0 ==> ret <= ret * loop) && (num >= 0 ==> ret % 2 == 0 || ret % 2 == 1) && (num >= 0 ==> ret % 100 >= 0) && (num >= 0 ==> loop <= num + 1) && (loop > 1 ==> ret >= loop - 1) && (loop > 1 ==> ret >= 1) && (loop > 1 ==> ret > 0) && (loop > 1 ==> ret <= ret * loop) && (loop > 1 ==> ret % 2 == 0 || ret % 2 == 1) && (loop == 1 ==> ret == 1) && (loop <= ret || ret <= num * ret) && (loop <= ret || loop <= num + 1) && (loop - 1 <= ret) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= ret) && (1 <= loop) && (0 <= ret) && (0 <= ret % 100) && (0 <= loop) && (0 < ret) && (0 < loop);
    assigns \nothing;
*/
void check_B_implies_A(int k, int num, int ret) {
    /*@ assert (1 <= loop <= num + 1) && (ret == fact(loop - 1)); */
}
