#include <limits.h>


/*@ logic integer count_nondiv(integer code, integer l, integer i) =
      i < l ? 0 : count_nondiv(code, l, i - 1) + (i % code != 0 ? 1 : 0);
*/

/*@requires code != 0;
  requires 0 <= l <= c;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result && \result <= c);
  ensures \result != -1 ==> l <= \result && \result <= c;
  ensures \result != -1 ==> (\result % code != 0 || count_nondiv(code, l, \result) == b);*/
int stub_A(int code, int b, int l, int c);

/*@loop invariant ret > 0 ==> loop > l;
		loop invariant ret > 0 ==> l < loop;
		loop invariant ret > 0 ==> \exists integer k; l <= k < loop ==> k % code != 0;
		loop invariant ret > 0 ==> \exists integer k; l <= k < loop && k % code != 0;
		loop invariant ret == 0 || ret >= 1;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == 0 || ret == 1 || ret > 1;
		loop invariant ret == 0 ==> loop == l || \forall integer k; l <= k < loop ==> k % code == 0;
		loop invariant ret == 0 ==> \forall integer k; l <= k < loop ==> k % code == 0;
		loop invariant ret == 0 ==> \forall integer k; l <= k < loop && k % code == 0 ==> 1 == 1;
		loop invariant ret <= loop - l;
		loop invariant ret <= loop - l + 1;
		loop invariant ret <= b ==> ret <= loop - l;
		loop invariant ret <= b ==> ret <= loop - l + 1;
		loop invariant ret < b ==> ret >= 0;
		loop invariant ret < b ==> ret <= loop - l;
		loop invariant ret < b ==> ret <= b;
		loop invariant ret < b ==> ret < loop - l + 1;
		loop invariant ret < b ==> ret < b + 1;
		loop invariant ret < b ==> loop == l + ret || loop > l;
		loop invariant ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1;
		loop invariant ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0;
		loop invariant ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret < b;
		loop invariant loop == l ==> ret == 0;
		loop invariant loop == l + ret || loop > l;
		loop invariant l <= loop;
		loop invariant l <= loop - ret;
		loop invariant \forall integer k; l <= k < loop ==> (k % code == 0 || k % code != 0);
		loop invariant \forall integer k; l <= k < loop ==> (k % code == 0 ==> ret >= 0);
		loop invariant \forall integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1);
		loop invariant \forall integer k; l <= k < loop ==> (k % code != 0 ==> ret > 0);
		loop invariant \forall integer k; l <= k < loop && k % code == 0 ==> ret >= 0;
		loop invariant \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1;
		loop invariant \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0;
		loop invariant \forall integer k; l <= k < loop && k % code != 0 ==> ret > 0;
		loop invariant \exists integer k; l <= k < loop ==> k % code != 0 || ret == 0;
		loop invariant \exists integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1);
		loop invariant 0 <= ret;
		loop assigns ret;
		loop assigns loop;*/
int stub_B(int code, int b, int l, int c);

/*@loop invariant ret > 0 ==> loop > l;
		loop invariant ret > 0 ==> l < loop;
		loop invariant ret > 0 ==> \exists integer k; l <= k < loop ==> k % code != 0;
		loop invariant ret > 0 ==> \exists integer k; l <= k < loop && k % code != 0;
		loop invariant ret == 0 || ret >= 1;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == 0 || ret == 1 || ret > 1;
		loop invariant ret == 0 ==> loop == l || \forall integer k; l <= k < loop ==> k % code == 0;
		loop invariant ret == 0 ==> \forall integer k; l <= k < loop ==> k % code == 0;
		loop invariant ret == 0 ==> \forall integer k; l <= k < loop && k % code == 0 ==> 1 == 1;
		loop invariant ret <= loop - l;
		loop invariant ret <= loop - l + 1;
		loop invariant ret <= b ==> ret <= loop - l;
		loop invariant ret <= b ==> ret <= loop - l + 1;
		loop invariant ret < b ==> ret >= 0;
		loop invariant ret < b ==> ret <= loop - l;
		loop invariant ret < b ==> ret <= b;
		loop invariant ret < b ==> ret < loop - l + 1;
		loop invariant ret < b ==> ret < b + 1;
		loop invariant ret < b ==> loop == l + ret || loop > l;
		loop invariant ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1;
		loop invariant ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0;
		loop invariant ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret < b;
		loop invariant loop == l ==> ret == 0;
		loop invariant loop == l + ret || loop > l;
		loop invariant l <= loop;
		loop invariant l <= loop - ret;
		loop invariant \forall integer k; l <= k < loop ==> (k % code == 0 || k % code != 0);
		loop invariant \forall integer k; l <= k < loop ==> (k % code == 0 ==> ret >= 0);
		loop invariant \forall integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1);
		loop invariant \forall integer k; l <= k < loop ==> (k % code != 0 ==> ret > 0);
		loop invariant \forall integer k; l <= k < loop && k % code == 0 ==> ret >= 0;
		loop invariant \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1;
		loop invariant \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0;
		loop invariant \forall integer k; l <= k < loop && k % code != 0 ==> ret > 0;
		loop invariant \exists integer k; l <= k < loop ==> k % code != 0 || ret == 0;
		loop invariant \exists integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1);
		loop invariant 0 <= ret;
		loop assigns ret;
		loop assigns loop;*/
int check_A_implies_B(int code, int b, int l, int c) {
    return stub_A(code, b, l, c);
}

/*@requires code != 0;
  requires 0 <= l <= c;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result && \result <= c);
  ensures \result != -1 ==> l <= \result && \result <= c;
  ensures \result != -1 ==> (\result % code != 0 || count_nondiv(code, l, \result) == b);*/
int check_B_implies_A(int code, int b, int l, int c) {
    return stub_B(code, b, l, c);
}
