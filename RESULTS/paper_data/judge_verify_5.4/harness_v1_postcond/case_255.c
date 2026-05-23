#include <limits.h>



/*@requires args_len >= 0;
  requires \valid(args + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures \result < args_len ==> 0 <= args[\result] <= 100;
  ensures \result >= 0;
  ensures \result <= args_len;*/
int stub_A(int * args, int args_len, int array);

/*@loop invariant top == args_len - 1 || args[top + 1] > array;
		loop invariant top < args_len;
		loop invariant top + 1 <= args_len;
		loop invariant result == 0 || args[result - 1] <= array;
		loop invariant result == 0 || args[result - 1] < array;
		loop invariant 0 <= result;
		loop assigns top;
		loop assigns result;*/
int stub_B(int * args, int args_len, int array);

/*@loop invariant top == args_len - 1 || args[top + 1] > array;
		loop invariant top < args_len;
		loop invariant top + 1 <= args_len;
		loop invariant result == 0 || args[result - 1] <= array;
		loop invariant result == 0 || args[result - 1] < array;
		loop invariant 0 <= result;
		loop assigns top;
		loop assigns result;*/
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@requires args_len >= 0;
  requires \valid(args + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures \result < args_len ==> 0 <= args[\result] <= 100;
  ensures \result >= 0;
  ensures \result <= args_len;*/
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
