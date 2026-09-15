#include <limits.h>


/*@
logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1);
*/

/*@requires num >= 0;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures -99 <= \result && \result < 100 ;
  ensures num == 0 ==> \result == 1;*/
int stub_A(int num);

/*@loop invariant loop == 1 || ret >= 1;
		loop invariant 0 <= loop - 1;
		loop invariant ret >= 1 && loop >= 1;
		loop invariant ret == 1 || ret >= loop - 1;
		loop invariant ret == 1 || ret >= 1;
		loop invariant ret == 1 || ret > 1;
		loop invariant ret == 1 || ret > 0;
		loop invariant ret == 1 || ret % 2 == 0;
		loop invariant ret == 1 || ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret == (loop - 1) * ret || ret > 0;
		loop invariant ret <= loop || loop <= num + 1;
		loop invariant ret <= loop * ret;
		loop invariant ret % 2 == loop % 2 || ret % 2 != loop % 2;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 100 >= 0 && ret % 100 < 100;
		loop invariant ret % 100 == ret % 100;
		loop invariant ret % 100 == (ret % 100);
		loop invariant ret % 100 == (1 <= loop ? ret % 100 : ret % 100);
		loop invariant loop > 1 ==> ret >= loop - 1;
		loop invariant loop > 1 ==> ret >= 1;
		loop invariant loop > 1 ==> ret > 0;
		loop invariant loop > 0 ==> ret >= loop - 1;
		loop invariant loop > 0 ==> ret >= 1;
		loop invariant loop > 0 ==> ret > 0;
		loop invariant loop == 1 || ret % 2 == 0 || ret % 2 == 1;
		loop invariant loop == 1 || loop > 1;
		loop invariant loop == 1 ==> ret == 1;
		loop invariant loop <= ret || loop <= num + 1;
		loop invariant loop <= num + 1 || loop <= ret;
		loop invariant loop - 1 <= ret;
		loop invariant loop % 2 == 0 || loop % 2 == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret > 0;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 2 == (k % 2 == 0 ? ret % 2 : ret % 2);
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 100 == ret % 100;
		loop invariant \exists integer k; 1 <= k <= loop && ret >= 1;
		loop invariant \exists integer k; 1 <= k <= loop && ret > 0;
		loop invariant 1 <= ret;
		loop invariant 1 <= ret || loop == 1;
		loop invariant 1 <= loop;
		loop invariant 0 <= ret;
		loop invariant 0 <= loop;
		loop invariant 0 < ret;
		loop invariant 0 < loop;
		loop assigns ret;
		loop assigns loop;*/
int stub_B(int num);

/*@loop invariant loop == 1 || ret >= 1;
		loop invariant 0 <= loop - 1;
		loop invariant ret >= 1 && loop >= 1;
		loop invariant ret == 1 || ret >= loop - 1;
		loop invariant ret == 1 || ret >= 1;
		loop invariant ret == 1 || ret > 1;
		loop invariant ret == 1 || ret > 0;
		loop invariant ret == 1 || ret % 2 == 0;
		loop invariant ret == 1 || ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret == (loop - 1) * ret || ret > 0;
		loop invariant ret <= loop || loop <= num + 1;
		loop invariant ret <= loop * ret;
		loop invariant ret % 2 == loop % 2 || ret % 2 != loop % 2;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 100 >= 0 && ret % 100 < 100;
		loop invariant ret % 100 == ret % 100;
		loop invariant ret % 100 == (ret % 100);
		loop invariant ret % 100 == (1 <= loop ? ret % 100 : ret % 100);
		loop invariant loop > 1 ==> ret >= loop - 1;
		loop invariant loop > 1 ==> ret >= 1;
		loop invariant loop > 1 ==> ret > 0;
		loop invariant loop > 0 ==> ret >= loop - 1;
		loop invariant loop > 0 ==> ret >= 1;
		loop invariant loop > 0 ==> ret > 0;
		loop invariant loop == 1 || ret % 2 == 0 || ret % 2 == 1;
		loop invariant loop == 1 || loop > 1;
		loop invariant loop == 1 ==> ret == 1;
		loop invariant loop <= ret || loop <= num + 1;
		loop invariant loop <= num + 1 || loop <= ret;
		loop invariant loop - 1 <= ret;
		loop invariant loop % 2 == 0 || loop % 2 == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= k;
		loop invariant \forall integer k; 1 <= k < loop ==> ret >= 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret > 0;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 2 == 0 || ret % 2 == 1;
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 2 == (k % 2 == 0 ? ret % 2 : ret % 2);
		loop invariant \forall integer k; 1 <= k < loop ==> ret % 100 == ret % 100;
		loop invariant \exists integer k; 1 <= k <= loop && ret >= 1;
		loop invariant \exists integer k; 1 <= k <= loop && ret > 0;
		loop invariant 1 <= ret;
		loop invariant 1 <= ret || loop == 1;
		loop invariant 1 <= loop;
		loop invariant 0 <= ret;
		loop invariant 0 <= loop;
		loop invariant 0 < ret;
		loop invariant 0 < loop;
		loop assigns ret;
		loop assigns loop;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num >= 0;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures -99 <= \result && \result < 100 ;
  ensures num == 0 ==> \result == 1;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
