#include <limits.h>


/*@ logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1); */

/*@requires num >= 0;
  requires num <= 12;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures 0 <= \result <= 99;
  ensures num == 0 ==> \result == 1;*/
int stub_A(int num);

/*@loop invariant num < 0 ==> loop == 1;
		loop invariant loop > 1 ==> ret % 100 >= 0;
		loop invariant ret >= 1 && loop >= 1;
		loop invariant ret == ret % 100 || ret > 99;
		loop invariant ret == loop == 1 ? 1 : ret;
		loop invariant ret == 1 || ret >= loop - 1;
		loop invariant ret == 1 || ret >= 1;
		loop invariant ret == 1 || ret > 0;
		loop invariant ret == 1 || loop > 1;
		loop invariant ret == (loop - 1) > 0 ? ret : 1;
		loop invariant ret == (loop - 1) == 1 ? 1 : ret;
		loop invariant ret <= ret * loop;
		loop invariant ret <= loop * ret;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 100 >= 0 && ret % 100 < 100;
		loop invariant ret % 100 == ret - 100 * (ret / 100);
		loop invariant ret % 100 < 100;
		loop invariant ret % 1 == 0;
		loop invariant num >= 0 ==> ret >= loop - 1;
		loop invariant num >= 0 ==> ret >= 1;
		loop invariant num >= 0 ==> ret > 0;
		loop invariant num >= 0 ==> ret <= ret * loop;
		loop invariant num >= 0 ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant num >= 0 ==> ret % 100 >= 0;
		loop invariant num >= 0 ==> loop <= num + 1;
		loop invariant loop > 1 ==> ret >= loop - 1;
		loop invariant loop > 1 ==> ret >= 1;
		loop invariant loop > 1 ==> ret > 0;
		loop invariant loop > 1 ==> ret <= ret * loop;
		loop invariant loop > 1 ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant loop == 1 ==> ret == 1;
		loop invariant loop <= ret || ret <= num * ret;
		loop invariant loop <= ret || loop <= num + 1;
		loop invariant loop - 1 <= ret;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= k || ret == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret > 0;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 100 >= 0;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 100 == ret - 100 * (ret / 100);
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 1 == 0;
		loop invariant \forall integer k; 1 <= k < loop ==> loop - 1 <= ret;
		loop invariant \forall integer k; 0 <= k < loop ==> ret >= 1;
		loop invariant 1 <= ret;
		loop invariant 1 <= loop;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret % 100;
		loop invariant 0 <= loop;
		loop invariant 0 < ret;
		loop invariant 0 < loop;
		loop assigns ret;
		loop assigns loop;*/
int stub_B(int num);

/*@loop invariant num < 0 ==> loop == 1;
		loop invariant loop > 1 ==> ret % 100 >= 0;
		loop invariant ret >= 1 && loop >= 1;
		loop invariant ret == ret % 100 || ret > 99;
		loop invariant ret == loop == 1 ? 1 : ret;
		loop invariant ret == 1 || ret >= loop - 1;
		loop invariant ret == 1 || ret >= 1;
		loop invariant ret == 1 || ret > 0;
		loop invariant ret == 1 || loop > 1;
		loop invariant ret == (loop - 1) > 0 ? ret : 1;
		loop invariant ret == (loop - 1) == 1 ? 1 : ret;
		loop invariant ret <= ret * loop;
		loop invariant ret <= loop * ret;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 100 >= 0 && ret % 100 < 100;
		loop invariant ret % 100 == ret - 100 * (ret / 100);
		loop invariant ret % 100 < 100;
		loop invariant ret % 1 == 0;
		loop invariant num >= 0 ==> ret >= loop - 1;
		loop invariant num >= 0 ==> ret >= 1;
		loop invariant num >= 0 ==> ret > 0;
		loop invariant num >= 0 ==> ret <= ret * loop;
		loop invariant num >= 0 ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant num >= 0 ==> ret % 100 >= 0;
		loop invariant num >= 0 ==> loop <= num + 1;
		loop invariant loop > 1 ==> ret >= loop - 1;
		loop invariant loop > 1 ==> ret >= 1;
		loop invariant loop > 1 ==> ret > 0;
		loop invariant loop > 1 ==> ret <= ret * loop;
		loop invariant loop > 1 ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant loop == 1 ==> ret == 1;
		loop invariant loop <= ret || ret <= num * ret;
		loop invariant loop <= ret || loop <= num + 1;
		loop invariant loop - 1 <= ret;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= k || ret == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret > 0;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 100 >= 0;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 100 == ret - 100 * (ret / 100);
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 1 == 0;
		loop invariant \forall integer k; 1 <= k < loop ==> loop - 1 <= ret;
		loop invariant \forall integer k; 0 <= k < loop ==> ret >= 1;
		loop invariant 1 <= ret;
		loop invariant 1 <= loop;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret % 100;
		loop invariant 0 <= loop;
		loop invariant 0 < ret;
		loop invariant 0 < loop;
		loop assigns ret;
		loop assigns loop;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num >= 0;
  requires num <= 12;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures 0 <= \result <= 99;
  ensures num == 0 ==> \result == 1;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
