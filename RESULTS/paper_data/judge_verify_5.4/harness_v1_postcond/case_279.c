#include <limits.h>


/*@
  logic integer max_prefix(int *args, integer lo, integer hi) =
    lo >= hi ? args[lo] :
    (max_prefix(args, lo, hi - 1) > args[hi - 1] ? max_prefix(args, lo, hi - 1) : args[hi - 1]);
*/

/*@requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args_len == \old(args_len);
  ensures args == \old(args);*/
int stub_A(int * args, int args_len);

/*@loop invariant ret == args[0] || ret == args[j-1] || (\exists integer k; 0 <= k < j && ret == args[k]);
		loop invariant ret == args[0] || (\exists integer k; 1 <= k < j && ret == args[k]);
		loop invariant ret == args[0] || (\exists integer k; 0 <= k < j && ret == args[k]);
		loop invariant ret <= args[j-1];
		loop invariant ret <= args[0];
		loop invariant ret <= args[0] || ret == args[0];
		loop invariant ret <= args[0] || ret <= args[j-1];
		loop invariant j == 0 || j > 0;
		loop invariant g >= ret || g == 0;
		loop invariant g == 0 || g >= ret;
		loop invariant g == 0 || g == ret || g >= ret;
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[0];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k] || ret <= args[0];
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= ret;
		loop invariant \exists integer k; 0 <= k < j && ret == args[k];
		loop invariant 1 <= j;
		loop invariant 1 <= j || j == 0;
		loop invariant 0 <= j;
		loop invariant 0 <= g;
		loop assigns ret;
		loop assigns j;
		loop assigns g;*/
int stub_B(int * args, int args_len);

/*@loop invariant ret == args[0] || ret == args[j-1] || (\exists integer k; 0 <= k < j && ret == args[k]);
		loop invariant ret == args[0] || (\exists integer k; 1 <= k < j && ret == args[k]);
		loop invariant ret == args[0] || (\exists integer k; 0 <= k < j && ret == args[k]);
		loop invariant ret <= args[j-1];
		loop invariant ret <= args[0];
		loop invariant ret <= args[0] || ret == args[0];
		loop invariant ret <= args[0] || ret <= args[j-1];
		loop invariant j == 0 || j > 0;
		loop invariant g >= ret || g == 0;
		loop invariant g == 0 || g >= ret;
		loop invariant g == 0 || g == ret || g >= ret;
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[k];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[0];
		loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k] || ret <= args[0];
		loop invariant \forall integer k; 0 <= k < j ==> args[k] >= ret;
		loop invariant \exists integer k; 0 <= k < j && ret == args[k];
		loop invariant 1 <= j;
		loop invariant 1 <= j || j == 0;
		loop invariant 0 <= j;
		loop invariant 0 <= g;
		loop assigns ret;
		loop assigns j;
		loop assigns g;*/
int check_A_implies_B(int * args, int args_len) {
    return stub_A(args, args_len);
}

/*@requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args_len == \old(args_len);
  ensures args == \old(args);*/
int check_B_implies_A(int * args, int args_len) {
    return stub_B(args, args_len);
}
