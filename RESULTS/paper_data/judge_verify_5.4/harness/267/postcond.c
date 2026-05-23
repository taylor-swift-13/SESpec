#include <limits.h>

/*@ logic integer oddcount(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : oddcount(args, lo, hi - 1) + ((args[hi - 1] % 2) != 0 ? 1 : 0); */
/*@ logic integer oddret(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : (((args[hi - 1] % 2) != 0) && ((oddcount(args, lo, hi - 1) + 1) % 2 != 0))
               ? args[hi - 1]
               : oddret(args, lo, hi - 1); */

/*@ requires array >= 0;
  requires \valid_read(args + (0..array-1));
  assigns \nothing;
  ensures array == 0 ==> \result == 0;
  ensures \result == oddret(args, 0, array); */
int stub_A(int * args, int args_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@ requires array >= 0;
  requires \valid_read(args + (0..array-1));
  assigns \nothing;
  ensures array == 0 ==> \result == 0;
  ensures \result == oddret(args, 0, array); */
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
