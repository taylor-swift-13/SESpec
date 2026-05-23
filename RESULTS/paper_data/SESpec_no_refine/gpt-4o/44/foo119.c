
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum{L}(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len > 0 && args_len < 100;
  ensures \result >= 0 && \result <= args_len;
  assigns \nothing;
*/
int foo119(int * args, int args_len, int Array) {

    int ret = 0;
    int top = args_len - 1;

    /*@
      loop invariant 0 <= ret <= args_len;
      loop invariant -1 <= top < args_len;
      loop invariant ret <= top + 1;
      loop invariant \exists integer k; ret <= k <= top ==> args[k] == Array;
      loop invariant count_eq(args, 0, args_len, Array) == count_eq(args, 0, args_len, Array);
      loop invariant sum(args, 0, args_len) == sum(args, 0, args_len);
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
