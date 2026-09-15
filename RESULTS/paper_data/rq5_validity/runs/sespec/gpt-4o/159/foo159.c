
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns args[0..args_len-1];
  ensures \forall integer k; 0 <= k < \result - 1 ==> args[k] == k + 1; // Weakened postcondition
  ensures \result == array + 1 ==> \forall integer k; 0 <= k < array ==> args[k] == k + 1;
*/
int foo159(int * args, int args_len, int array) {

    int ret = 0;

    /*@
      loop invariant array == \at(array, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop invariant \forall integer k; 0 <= k < ret ==> 
                       (args[k] <= 0 || args[k] > array || args[k] == k + 1);
      loop invariant \forall integer v; 0 <= v <= array ==>
                       count_eq(args, 0, ret, v) == count_eq(\at(args, Pre), 0, ret, v);
      loop assigns ret, args[0..args_len-1];
    */
    while (ret < array) {
        if (args[ret] <= 0 || args[ret] > array || args[ret] == ret + 1) {
            ret++;
        } else {
            int j = args[ret];
            args[ret] = args[j - 1];
            args[j - 1] = j;
        }
    }

    /*@
      loop invariant \forall integer k; 0 <= k < ret ==> args[k] == k + 1;
      loop invariant \forall integer v; 0 <= v <= array ==>
                       count_eq(args, 0, array, v) == count_eq(\at(args, Pre), 0, array, v);
      loop invariant array == \at(array, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop assigns ret;
    */
    for (ret = 0; ret < array; ret++) {
        if (args[ret] != ret + 1) {
            return ret + 1;
        }
    }

    return array + 1;
}
