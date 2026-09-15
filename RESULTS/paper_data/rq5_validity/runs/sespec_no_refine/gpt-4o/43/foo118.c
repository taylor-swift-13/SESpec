
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires \valid(args + (0..\at(args_len,Pre)-1));
  requires sorted(args, 0, \at(args_len,Pre));
  ensures \result >= 0 && \result <= \at(args_len,Pre);
  assigns \nothing;
*/
int foo118(int * args, int args_len, int array) {

    int result = 0;
    int top = args_len - 1;

    /*@
      loop invariant 0 <= result && result <= args_len;
      loop invariant -1 <= top && top < args_len;
      loop invariant result <= top + 1;
      loop invariant sorted(args, 0, args_len);
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns result, top;
      loop variant top - result + 1;
    */
    while (result <= top) {
        int i = (result + top) / 2;
        if (args[i] == array) {
            return i;
        } else if (args[i] < array) {
            result = i + 1;
        } else {
            top = i - 1;
        }
    }

    return result;
}
