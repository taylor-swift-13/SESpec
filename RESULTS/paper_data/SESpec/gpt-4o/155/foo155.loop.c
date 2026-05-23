
#include <stdlib.h>

/*@
  logic integer max(int* array, integer lo, integer hi) =
    lo >= hi ? 0 : (max(array, lo, hi - 1) > array[hi - 1] ? max(array, lo, hi - 1) : array[hi - 1]);
*/

/*@
  predicate unchanged_array{L1, L2}(int* array, integer len) =
    \forall integer i; 0 <= i < len ==> \at(array[i], L1) == \at(array[i], L2);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires Array >= 0;
  ensures \result == max(mpis, 0, Array);
*/
int foo155(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;

    /*@
      loop invariant 0 <= array <= Array;
      loop invariant \forall integer i; 0 <= i < array ==> mpis[i] == args[i];
      loop invariant \forall integer i; array <= i < Array ==> mpis[i] == \at(mpis[i], Pre);
      loop invariant unchanged_array{Pre, Here}(args, args_len);
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /*@
      loop invariant 1 <= i <= Array;
      loop invariant \forall integer j; 0 <= j < i ==> \forall integer k; 0 <= k < j ==> 
        (args[j] > args[k] && mpis[j] < (mpis[k] * args[j])) ==> mpis[j] == (mpis[k] * args[j]);
      loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= args[j];
      loop invariant unchanged_array{Pre, Here}(args, args_len);
      loop assigns i, k, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        /*@
          loop invariant 0 <= k <= i;
          loop invariant \forall integer j; 0 <= j < i ==> \forall integer l; 0 <= l < j ==> 
            (args[j] > args[l] && mpis[j] < (mpis[l] * args[j])) ==> mpis[j] == (mpis[l] * args[j]);
          loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= args[j];
          loop invariant unchanged_array{Pre, Here}(args, args_len);
          loop assigns k, mpis[0..Array-1];
        */
        for (int k = 0; k < i; k++) {
            /*@
              loop invariant 0 <= k <= i;
              loop invariant \forall integer j; 0 <= j < i ==> 
                (args[j] > args[k] && mpis[j] < (mpis[k] * args[j])) ==> mpis[j] == (mpis[k] * args[j]);
              loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= args[j];
              loop invariant unchanged_array{Pre, Here}(args, args_len);
              loop assigns mpis[i];
            */
            if (args[i] > args[k] && mpis[i] < (mpis[k] * args[i])) {
                mpis[i] = mpis[k] * args[i];
            }
        }
    }

    int num = mpis[0];

    /*@
      loop invariant 1 <= i <= Array;
      loop invariant num == max(mpis, 0, i);
      loop invariant \forall integer j; 0 <= j < Array ==> mpis[j] >= args[j];
      loop invariant unchanged_array{Pre, Here}(args, args_len);
      loop assigns i, num;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }

    return num;
}
