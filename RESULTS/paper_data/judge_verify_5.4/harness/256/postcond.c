#include <limits.h>

/*@ requires args_len > 0;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  ensures args_len == \old(args_len);
  ensures args == \old(args);
  ensures Array == \old(Array); */
int stub_A(int * args, int args_len, int Array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int Array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int Array) {
    return stub_A(args, args_len, Array);
}

/*@ requires args_len > 0;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  ensures args_len == \old(args_len);
  ensures args == \old(args);
  ensures Array == \old(Array); */
int check_B_implies_A(int * args, int args_len, int Array) {
    return stub_B(args, args_len, Array);
}
