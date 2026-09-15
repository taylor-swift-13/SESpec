#include <limits.h>


/*@
  logic integer minp(int* a, integer lo, integer hi) =
    hi <= lo ? 0 :
    (hi == lo + 1 ? a[lo] :
     (minp(a, lo, hi - 1) <= a[hi - 1] ? minp(a, lo, hi - 1) : a[hi - 1]));
*/

/*@requires arg_len >= 1;
  requires \valid_read(arg + (0 .. arg_len - 1));
  assigns \nothing;
  ensures \result >= 0;
  ensures arg_len == 1 ==> \result >= 0;
  ensures arg_len > 1 ==> \result >= 0;
  ensures \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre);
  ensures \result == 0 ==> arg_len >= 1;*/
int stub_A(int * arg, int arg_len);

/*@loop invariant ret == arg[0] || ret == arg[j-1] || \exists integer k; 0 <= k < j && ret == arg[k];
		loop invariant ret == arg[0] || ret == arg[j-1] || (\exists integer k; 0 <= k < j && ret == arg[k]);
		loop invariant ret == arg[0] || \exists integer k; 1 <= k < j && ret == arg[k];
		loop invariant ret == arg[0] || \exists integer k; 0 <= k < j && ret == arg[k];
		loop invariant ret == arg[0] || (\exists integer k; 1 <= k < j && ret == arg[k]);
		loop invariant ret == arg[0] || (\exists integer k; 0 <= k < j && ret == arg[k]);
		loop invariant ret <= g || g == 0;
		loop invariant ret <= arg[0];
		loop invariant ret <= arg[0] || ret == arg[0];
		loop invariant ret <= arg[0] || ret <= g;
		loop invariant g >= ret || g == 0;
		loop invariant g == 0 || ret <= g;
		loop invariant g == 0 || ret <= g || ret == arg[0];
		loop invariant g == 0 || ret <= arg[0];
		loop invariant g == 0 || g >= ret;
		loop invariant g == 0 || g >= 0;
		loop invariant g == 0 || g == ret || \exists integer k; 0 <= k < j && g == arg[k];
		loop invariant g == 0 || \exists integer k; 0 <= k < j && g >= arg[k];
		loop invariant g == 0 || \exists integer k; 0 <= k < j && g == arg[k];
		loop invariant g == 0 || (\exists integer k; 0 <= k < j && g == arg[k]);
		loop invariant \forall integer k; 1 <= k < j ==> ret <= arg[k];
		loop invariant \forall integer k; 1 <= k < j ==> ret <= arg[k] || ret == arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k] || ret == arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k] || g >= arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> g >= ret || g == 0;
		loop invariant \forall integer k; 0 <= k < j ==> g >= 0;
		loop invariant \forall integer k; 0 <= k < j ==> g == 0 || g >= ret;
		loop invariant \forall integer k; 0 <= k < j ==> arg[k] >= ret;
		loop invariant \forall integer k; 0 <= k < j ==> arg[k] >= ret || arg[k] == ret;
		loop invariant \exists integer k; 0 <= k < j && ret == arg[k];
		loop invariant \exists integer k; 0 <= k < j && ret == arg[k] || ret == arg[0];
		loop invariant \exists integer k; 0 <= k < j && g == arg[k] || g == 0;
		loop invariant \exists integer k; 0 <= k < j && arg[k] == ret;
		loop invariant \exists integer k; 0 <= k < j && (g == arg[k] || ret == arg[k]);
		loop invariant 1 <= j;
		loop invariant 0 <= j;
		loop invariant 0 <= g;
		loop assigns ret;
		loop assigns j;
		loop assigns g;*/
int stub_B(int * arg, int arg_len);

/*@loop invariant ret == arg[0] || ret == arg[j-1] || \exists integer k; 0 <= k < j && ret == arg[k];
		loop invariant ret == arg[0] || ret == arg[j-1] || (\exists integer k; 0 <= k < j && ret == arg[k]);
		loop invariant ret == arg[0] || \exists integer k; 1 <= k < j && ret == arg[k];
		loop invariant ret == arg[0] || \exists integer k; 0 <= k < j && ret == arg[k];
		loop invariant ret == arg[0] || (\exists integer k; 1 <= k < j && ret == arg[k]);
		loop invariant ret == arg[0] || (\exists integer k; 0 <= k < j && ret == arg[k]);
		loop invariant ret <= g || g == 0;
		loop invariant ret <= arg[0];
		loop invariant ret <= arg[0] || ret == arg[0];
		loop invariant ret <= arg[0] || ret <= g;
		loop invariant g >= ret || g == 0;
		loop invariant g == 0 || ret <= g;
		loop invariant g == 0 || ret <= g || ret == arg[0];
		loop invariant g == 0 || ret <= arg[0];
		loop invariant g == 0 || g >= ret;
		loop invariant g == 0 || g >= 0;
		loop invariant g == 0 || g == ret || \exists integer k; 0 <= k < j && g == arg[k];
		loop invariant g == 0 || \exists integer k; 0 <= k < j && g >= arg[k];
		loop invariant g == 0 || \exists integer k; 0 <= k < j && g == arg[k];
		loop invariant g == 0 || (\exists integer k; 0 <= k < j && g == arg[k]);
		loop invariant \forall integer k; 1 <= k < j ==> ret <= arg[k];
		loop invariant \forall integer k; 1 <= k < j ==> ret <= arg[k] || ret == arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k] || ret == arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k] || g >= arg[k];
		loop invariant \forall integer k; 0 <= k < j ==> g >= ret || g == 0;
		loop invariant \forall integer k; 0 <= k < j ==> g >= 0;
		loop invariant \forall integer k; 0 <= k < j ==> g == 0 || g >= ret;
		loop invariant \forall integer k; 0 <= k < j ==> arg[k] >= ret;
		loop invariant \forall integer k; 0 <= k < j ==> arg[k] >= ret || arg[k] == ret;
		loop invariant \exists integer k; 0 <= k < j && ret == arg[k];
		loop invariant \exists integer k; 0 <= k < j && ret == arg[k] || ret == arg[0];
		loop invariant \exists integer k; 0 <= k < j && g == arg[k] || g == 0;
		loop invariant \exists integer k; 0 <= k < j && arg[k] == ret;
		loop invariant \exists integer k; 0 <= k < j && (g == arg[k] || ret == arg[k]);
		loop invariant 1 <= j;
		loop invariant 0 <= j;
		loop invariant 0 <= g;
		loop assigns ret;
		loop assigns j;
		loop assigns g;*/
int check_A_implies_B(int * arg, int arg_len) {
    return stub_A(arg, arg_len);
}

/*@requires arg_len >= 1;
  requires \valid_read(arg + (0 .. arg_len - 1));
  assigns \nothing;
  ensures \result >= 0;
  ensures arg_len == 1 ==> \result >= 0;
  ensures arg_len > 1 ==> \result >= 0;
  ensures \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre);
  ensures \result == 0 ==> arg_len >= 1;*/
int check_B_implies_A(int * arg, int arg_len) {
    return stub_B(arg, arg_len);
}
