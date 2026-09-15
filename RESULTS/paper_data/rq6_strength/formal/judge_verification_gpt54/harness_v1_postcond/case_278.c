#include <limits.h>


/*@
  logic integer min_prefix(int *a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : (a[hi - 1] < min_prefix(a, lo, hi - 1) ? a[hi - 1] : min_prefix(a, lo, hi - 1));
*/

/*@requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures \result >= 0;
  ensures args_len <= 1 ==> \result >= 0;
  ensures args_len > 1 && (\forall integer j; 1 <= j < args_len ==> args[j] <= \at(args[j - 1], Pre)) ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;*/
int stub_A(int * args, int args_len);

/*@loop invariant ret == 0 || \exists integer k; 0 <= k < j && ret == args[k];
		loop invariant tmp >= 0 || tmp <= args[0];
		loop invariant tmp == args[j-1] || tmp <= args[j-1];
		loop invariant tmp == args[0] || \exists integer k; 0 <= k < j && tmp == args[k];
		loop invariant tmp == args[0] || (\exists integer k; 0 <= k < j && tmp == args[k]);
		loop invariant tmp <= ret || ret == 0;
		loop invariant tmp <= args[j-1];
		loop invariant tmp <= args[j-1] || ret >= tmp;
		loop invariant tmp <= args[0];
		loop invariant tmp <= args[0] || tmp == args[0];
		loop invariant tmp <= args[0] || tmp <= ret;
		loop invariant ret >= tmp || ret == 0;
		loop invariant ret == 0 || tmp <= ret;
		loop invariant ret == 0 || tmp <= args[0];
		loop invariant ret == 0 || ret >= tmp;
		loop invariant ret == 0 || ret >= 0;
		loop invariant ret == 0 ==> j >= 1;
		loop invariant j == 1 || j > 0;
		loop invariant j <= args_len || 0 <= j;
		loop invariant \forall integer k; 0 <= k < j ==> tmp <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= tmp;
		loop invariant \forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret >= args[k] || tmp <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret >= 0;
		loop invariant \forall integer k; 0 <= k < j ==> ret >= 0 || tmp <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret >= 0 || args[k] >= tmp;
		loop invariant \forall integer k; 0 <= k < j ==> ret == 0 || ret >= 0;
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= tmp;
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= tmp || ret >= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= ret || tmp <= args[k];
		loop invariant \exists integer k; 0 <= k < j && tmp == args[k];
		loop invariant \exists integer k; 0 <= k < j && args[k] == tmp;
		loop invariant 1 <= j;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || ret == 0;
		loop invariant 0 <= j;
		loop invariant 0 < j;
		loop assigns tmp;
		loop assigns ret;
		loop assigns j;*/
int stub_B(int * args, int args_len);

/*@loop invariant ret == 0 || \exists integer k; 0 <= k < j && ret == args[k];
		loop invariant tmp >= 0 || tmp <= args[0];
		loop invariant tmp == args[j-1] || tmp <= args[j-1];
		loop invariant tmp == args[0] || \exists integer k; 0 <= k < j && tmp == args[k];
		loop invariant tmp == args[0] || (\exists integer k; 0 <= k < j && tmp == args[k]);
		loop invariant tmp <= ret || ret == 0;
		loop invariant tmp <= args[j-1];
		loop invariant tmp <= args[j-1] || ret >= tmp;
		loop invariant tmp <= args[0];
		loop invariant tmp <= args[0] || tmp == args[0];
		loop invariant tmp <= args[0] || tmp <= ret;
		loop invariant ret >= tmp || ret == 0;
		loop invariant ret == 0 || tmp <= ret;
		loop invariant ret == 0 || tmp <= args[0];
		loop invariant ret == 0 || ret >= tmp;
		loop invariant ret == 0 || ret >= 0;
		loop invariant ret == 0 ==> j >= 1;
		loop invariant j == 1 || j > 0;
		loop invariant j <= args_len || 0 <= j;
		loop invariant \forall integer k; 0 <= k < j ==> tmp <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= tmp;
		loop invariant \forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret >= args[k] || tmp <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret >= 0;
		loop invariant \forall integer k; 0 <= k < j ==> ret >= 0 || tmp <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret >= 0 || args[k] >= tmp;
		loop invariant \forall integer k; 0 <= k < j ==> ret == 0 || ret >= 0;
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= tmp;
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= tmp || ret >= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= ret || tmp <= args[k];
		loop invariant \exists integer k; 0 <= k < j && tmp == args[k];
		loop invariant \exists integer k; 0 <= k < j && args[k] == tmp;
		loop invariant 1 <= j;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || ret == 0;
		loop invariant 0 <= j;
		loop invariant 0 < j;
		loop assigns tmp;
		loop assigns ret;
		loop assigns j;*/
int check_A_implies_B(int * args, int args_len) {
    return stub_A(args, args_len);
}

/*@requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures \result >= 0;
  ensures args_len <= 1 ==> \result >= 0;
  ensures args_len > 1 && (\forall integer j; 1 <= j < args_len ==> args[j] <= \at(args[j - 1], Pre)) ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;*/
int check_B_implies_A(int * args, int args_len) {
    return stub_B(args, args_len);
}
