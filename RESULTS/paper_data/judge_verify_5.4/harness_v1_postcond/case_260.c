#include <limits.h>



/*@requires array >= 0;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1];
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
  ensures \result != -1 ==> 0 <= \result < array;
  ensures \result != -1 ==> args[\result] == \result;*/
int stub_A(int * args, int args_len, int array);

/*@loop invariant stop == array - 1 || stop < array - 1;
		loop invariant stop <= array - 1;
		loop invariant stop < array;
		loop invariant stop < array ==> ret >= 0;
		loop invariant stop < array - 1 ==> ret >= 0;
		loop invariant stop + 1 <= array;
		loop invariant ret >= 0 || ret == -1;
		loop invariant ret == 0 || ret >= 0;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == 0 || ret > 0 || ret == -1;
		loop invariant ret == 0 || ret == -1 || ret > 0;
		loop invariant ret == 0 || ret <= array;
		loop invariant ret == 0 ==> \forall integer k; 0 <= k < ret ==> args[k] != k;
		loop invariant ret == -1 || ret >= 0;
		loop invariant ret <= stop + 1 ==> ret <= array;
		loop invariant ret <= array ==> stop < array;
		loop invariant ret <= array ==> stop + 1 <= array;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || ret == -1;
		loop assigns stop;
		loop assigns ret;*/
int stub_B(int * args, int args_len, int array);

/*@loop invariant stop == array - 1 || stop < array - 1;
		loop invariant stop <= array - 1;
		loop invariant stop < array;
		loop invariant stop < array ==> ret >= 0;
		loop invariant stop < array - 1 ==> ret >= 0;
		loop invariant stop + 1 <= array;
		loop invariant ret >= 0 || ret == -1;
		loop invariant ret == 0 || ret >= 0;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == 0 || ret > 0 || ret == -1;
		loop invariant ret == 0 || ret == -1 || ret > 0;
		loop invariant ret == 0 || ret <= array;
		loop invariant ret == 0 ==> \forall integer k; 0 <= k < ret ==> args[k] != k;
		loop invariant ret == -1 || ret >= 0;
		loop invariant ret <= stop + 1 ==> ret <= array;
		loop invariant ret <= array ==> stop < array;
		loop invariant ret <= array ==> stop + 1 <= array;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || ret == -1;
		loop assigns stop;
		loop assigns ret;*/
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@requires array >= 0;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1];
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
  ensures \result != -1 ==> 0 <= \result < array;
  ensures \result != -1 ==> args[\result] == \result;*/
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
