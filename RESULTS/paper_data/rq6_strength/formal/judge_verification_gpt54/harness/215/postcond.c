#include <limits.h>

/*@ requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires 0 <= y <= args_len;
  assigns \nothing;
  ensures -1 <= \result < args_len;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
  ensures \result != -1 ==> args[\result] == x; */
int stub_A(int * args, int args_len, int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int x, int y) {
    return stub_A(args, args_len, x, y);
}

/*@ requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires 0 <= y <= args_len;
  assigns \nothing;
  ensures -1 <= \result < args_len;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
  ensures \result != -1 ==> args[\result] == x; */
int check_B_implies_A(int * args, int args_len, int x, int y) {
    return stub_B(args, args_len, x, y);
}
