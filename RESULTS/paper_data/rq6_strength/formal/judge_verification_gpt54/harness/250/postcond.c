#include <limits.h>
#include <stddef.h>

/*@ logic integer dummy_logic = 0; */

/*@ requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures start == \old(start);
  ensures stop == \old(stop);
  ensures \result >= \old(start);
  ensures \result >= \old(start);
  ensures \old(start) > \old(stop) ==> \result >= \old(start); */
int stub_A(int * args, int args_len, int start, int stop);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int start, int stop);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int start, int stop) {
    return stub_A(args, args_len, start, stop);
}

/*@ requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures start == \old(start);
  ensures stop == \old(stop);
  ensures \result >= \old(start);
  ensures \result >= \old(start);
  ensures \old(start) > \old(stop) ==> \result >= \old(start); */
int check_B_implies_A(int * args, int args_len, int start, int stop) {
    return stub_B(args, args_len, start, stop);
}
