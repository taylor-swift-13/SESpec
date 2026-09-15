#include <limits.h>



/*@requires args_len > 0;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  ensures args_len == \old(args_len);
  ensures args == \old(args);
  ensures Array == \old(Array);*/
int stub_A(int * args, int args_len, int Array);

/*@loop invariant top == args_len - 1 || args[top+1] > Array;
		loop invariant top == args_len - 1 || top < args_len - 1;
		loop invariant top < args_len;
		loop invariant top < args_len - 1 || top == args_len - 1;
		loop invariant top < args_len - 1 || top + 1 == args_len;
		loop invariant top < args_len - 1 ==> args[top+1] > Array;
		loop invariant top + 1 == args_len || args[top+1] >= Array;
		loop invariant top + 1 == args_len || args[top+1] > Array;
		loop invariant top + 1 <= args_len;
		loop invariant ret > 0 ==> ret - 1 <= top;
		loop invariant ret > 0 ==> args[ret-1] < Array;
		loop invariant ret == 0 || ret >= 0;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == 0 || ret - 1 <= top;
		loop invariant ret == 0 || args[ret-1] <= Array;
		loop invariant ret == 0 || args[ret-1] < Array;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || top < 0;
		loop invariant 0 <= ret || ret == top + 1;
		loop assigns top;
		loop assigns ret;*/
int stub_B(int * args, int args_len, int Array);

/*@loop invariant top == args_len - 1 || args[top+1] > Array;
		loop invariant top == args_len - 1 || top < args_len - 1;
		loop invariant top < args_len;
		loop invariant top < args_len - 1 || top == args_len - 1;
		loop invariant top < args_len - 1 || top + 1 == args_len;
		loop invariant top < args_len - 1 ==> args[top+1] > Array;
		loop invariant top + 1 == args_len || args[top+1] >= Array;
		loop invariant top + 1 == args_len || args[top+1] > Array;
		loop invariant top + 1 <= args_len;
		loop invariant ret > 0 ==> ret - 1 <= top;
		loop invariant ret > 0 ==> args[ret-1] < Array;
		loop invariant ret == 0 || ret >= 0;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == 0 || ret - 1 <= top;
		loop invariant ret == 0 || args[ret-1] <= Array;
		loop invariant ret == 0 || args[ret-1] < Array;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || top < 0;
		loop invariant 0 <= ret || ret == top + 1;
		loop assigns top;
		loop assigns ret;*/
int check_A_implies_B(int * args, int args_len, int Array) {
    return stub_A(args, args_len, Array);
}

/*@requires args_len > 0;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  ensures args_len == \old(args_len);
  ensures args == \old(args);
  ensures Array == \old(Array);*/
int check_B_implies_A(int * args, int args_len, int Array) {
    return stub_B(args, args_len, Array);
}
