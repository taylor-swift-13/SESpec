
/*@
predicate sorted_array{L}(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures args_len == 0 ==> \result == 0;
*/
int foo257(int *args, int args_len, int array) {
    int ret = 0;
    int top = args_len - 1;

    /*@
      loop invariant 0 <= ret;
      loop invariant ret <= args_len;
      loop invariant top < args_len;
      loop invariant ret <= top + 1;
      loop invariant args_len == 0 ==> top == -1 && ret == 0;
      loop assigns ret, top;
      loop variant top - ret + 1;
    */
    while (ret <= top) {
        int i = (ret + top) / 2;
        if (args[i] == array) {
            return i;
        } else if (args[i] < array) {
            ret = i + 1;
        } else {
            top = i - 1;
        }
    }

    return ret;
}
