
/*@
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (max(array, begin, end - 1) > array[end - 1] ? max(array, begin, end - 1) : array[end - 1]);
*/

/*@
  logic integer min(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (min(array, begin, end - 1) < array[end - 1] ? min(array, begin, end - 1) : array[end - 1]);
*/

/*@
  requires \at(args_len, Pre) > 0 && \at(args_len, Pre) < 100;
  requires \valid(args + (0..\at(args_len, Pre) - 1));
  ensures \result == max(args, 0, \at(args_len, Pre) - 1);
*/
int foo159(int * args, int args_len) {

    int ret = 0;
    int tmp = args[0];

    /*@
      loop invariant 1 <= j <= \at(args_len, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop invariant \forall integer k; 0 <= k < \at(args_len, Pre) ==> args[k] == \at(args[k], Pre);
      loop assigns j, ret, tmp;
    */
    for (int j = 1; j < args_len; j++) {
        if (args[j] > tmp) {
            ret = ret > tmp ? ret : tmp;
        } else {
            tmp = args[j];
        }
    }

    return ret;
}
