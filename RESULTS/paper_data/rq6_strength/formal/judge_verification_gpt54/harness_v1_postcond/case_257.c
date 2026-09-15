#include <limits.h>



/*@requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires \forall integer i, j; 0 <= i <= j < args_len ==> args[i] <= args[j];
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] < args[j];
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures (\exists integer k; 0 <= k < args_len && args[k] == array) ==> 0 <= \result <= args_len;
  ensures (\forall integer k; 0 <= k < args_len ==> args[k] != array) ==> 0 <= \result <= args_len;*/
int stub_A(int * args, int args_len, int array);

/*@loop invariant args_len > 0 ==> top + 1 == args_len || array <= args[top + 1];
		loop invariant args_len > 0 ==> 0 <= ret <= top + 1 <= args_len;
		loop invariant top == args_len - 1 || top < args_len - 1;
		loop invariant top == args_len - 1 || args[top + 1] >= array;
		loop invariant top < args_len;
		loop invariant ret == 0 || args[ret - 1] < array;
		loop invariant args_len > 0 ==> top + 1 <= args_len;
		loop invariant args_len > 0 ==> ret == 0 || args[ret - 1] < array;
		loop invariant args_len > 0 ==> ret <= top + 1 <= args_len;
		loop invariant args_len > 0 ==> ret <= args_len && top + 1 >= 0;
		loop invariant args_len > 0 ==> ret <= args_len && top + 1 <= args_len;
		loop invariant args_len > 0 ==> 0 <= top + 1 <= args_len;
		loop invariant args_len > 0 ==> 0 <= ret <= args_len;
		loop invariant args_len > 0 ==> (top + 1 == args_len || array <= args[top + 1]);
		loop invariant args_len > 0 ==> (top + 1 < args_len ==> array <= args[top + 1]);
		loop invariant args_len > 0 ==> (ret > 0 ==> args[ret - 1] < array);
		loop invariant args_len > 0 ==> (ret == 0 || args[ret - 1] < array);
		loop invariant args_len > 0 ==> (0 <= ret && top < args_len);
		loop invariant args_len == 0 ==> top == -1;
		loop invariant args_len == 0 ==> top == -1 && ret == 0;
		loop invariant args_len == 0 ==> ret == 0;
		loop invariant args_len == 0 ==> ret == 0 && top == -1;
		loop invariant 0 <= ret;
		loop assigns top;
		loop assigns ret;*/
int stub_B(int * args, int args_len, int array);

/*@loop invariant args_len > 0 ==> top + 1 == args_len || array <= args[top + 1];
		loop invariant args_len > 0 ==> 0 <= ret <= top + 1 <= args_len;
		loop invariant top == args_len - 1 || top < args_len - 1;
		loop invariant top == args_len - 1 || args[top + 1] >= array;
		loop invariant top < args_len;
		loop invariant ret == 0 || args[ret - 1] < array;
		loop invariant args_len > 0 ==> top + 1 <= args_len;
		loop invariant args_len > 0 ==> ret == 0 || args[ret - 1] < array;
		loop invariant args_len > 0 ==> ret <= top + 1 <= args_len;
		loop invariant args_len > 0 ==> ret <= args_len && top + 1 >= 0;
		loop invariant args_len > 0 ==> ret <= args_len && top + 1 <= args_len;
		loop invariant args_len > 0 ==> 0 <= top + 1 <= args_len;
		loop invariant args_len > 0 ==> 0 <= ret <= args_len;
		loop invariant args_len > 0 ==> (top + 1 == args_len || array <= args[top + 1]);
		loop invariant args_len > 0 ==> (top + 1 < args_len ==> array <= args[top + 1]);
		loop invariant args_len > 0 ==> (ret > 0 ==> args[ret - 1] < array);
		loop invariant args_len > 0 ==> (ret == 0 || args[ret - 1] < array);
		loop invariant args_len > 0 ==> (0 <= ret && top < args_len);
		loop invariant args_len == 0 ==> top == -1;
		loop invariant args_len == 0 ==> top == -1 && ret == 0;
		loop invariant args_len == 0 ==> ret == 0;
		loop invariant args_len == 0 ==> ret == 0 && top == -1;
		loop invariant 0 <= ret;
		loop assigns top;
		loop assigns ret;*/
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires \forall integer i, j; 0 <= i <= j < args_len ==> args[i] <= args[j];
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] < args[j];
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures (\exists integer k; 0 <= k < args_len && args[k] == array) ==> 0 <= \result <= args_len;
  ensures (\forall integer k; 0 <= k < args_len ==> args[k] != array) ==> 0 <= \result <= args_len;*/
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
