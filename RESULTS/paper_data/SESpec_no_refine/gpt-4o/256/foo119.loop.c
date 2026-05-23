
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer binary_search_invariant(int* a, integer lo, integer hi, integer v) =
    \forall integer k; 0 <= k < lo ==> a[k] < v &&
    \forall integer k; hi < k < \at(args_len, Pre) ==> a[k] > v;
*/

int foo119(int * args, int args_len, int Array) {

    int ret = 0;
    int top = args_len - 1;

    /*@
      loop invariant 0 <= ret <= args_len;
      loop invariant -1 <= top < args_len;
      loop invariant ret <= top + 1;
      loop invariant binary_search_invariant(args, ret, top, Array);
      loop invariant Array == \at(Array, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop assigns ret, top;
    */
    while (ret <= top) {
        int i = (ret + top) / 2;
        if (args[i] == Array) {
            return i;
        } else if (args[i] < Array) {
            ret = i + 1;
        } else {
            top = i - 1;
        }
    }

    return ret;
}
