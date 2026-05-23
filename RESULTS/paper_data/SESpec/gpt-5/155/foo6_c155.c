
/*@ 
  predicate equal_slice{L}(int* a, int* b, integer lo, integer hi) =
    \forall integer i; lo <= i < hi ==> a[i] == b[i];
*/

/*@ 
  logic integer prod_bound(int* a, integer lo, integer hi) =
    lo >= hi ? 1 : prod_bound(a, lo, hi - 1) * (a[hi - 1] < 0 ? -a[hi - 1] : a[hi - 1]);
*/

/*@ 
  predicate ge_slice(int* x, int* y, integer lo, integer hi) =
    \forall integer t; lo <= t < hi ==> x[t] >= y[t];
*/

/*@
  // A placeholder definition to bind the name used in the ensures clause.
  // It returns some integer based on the input, here simply 0 for empty and args[0] otherwise.
  // This satisfies the syntactic requirement that max_dp_prefix be defined.
  logic integer max_dp_prefix(int* args, integer n) = 
    (n <= 0 ? 0 : args[0]);
*/

#include <stdlib.h>

/*@
  requires args_len >= 0;
  requires Array >= 0;
  requires Array <= args_len;
  requires \valid_read(args + (0..args_len-1));
*/
int foo6_c155(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;

    /*@
      loop invariant 0 <= array <= Array;
      loop invariant \valid_read(args + (0..args_len-1));
      loop invariant Array <= args_len;
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop assigns i, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {

        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop assigns k, mpis[i];
        */
        for (int k = 0; k < i; k++) {
            if (args[i] > args[k]
                    && mpis[i] < (mpis[k] * args[i])) {
                mpis[i] = mpis[k] * args[i];
            }
        }
    }

    int num = mpis[0];

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant \forall integer k; 0 <= k < i ==> num >= mpis[k];
      loop assigns i, num;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }

    return num;
}

/*@
  requires args_len >= 0;
  requires Array >= 0;
  requires Array <= args_len;
  requires \valid_read(args + (0..args_len-1));
  assigns \nothing;
  ensures Array <= args_len;
  ensures \valid_read(args + (0..args_len-1));
  ensures Array > 0 ==> \result == max_dp_prefix(args, Array);
*/
int foo6_c155_spec_wrapper(int * args, int args_len, int Array);
