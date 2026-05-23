
        /*@
        predicate sorted{L}(int *a, integer n) =
          \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
        */

/*@
  requires 0 <= args_len;
  requires args_len == 0 || \valid_read(args + (0 .. args_len - 1));
  requires sorted(args, args_len);
  assigns \nothing;
  ensures 0 <= \result <= args_len;
*/
int foo255(int *args, int args_len, int array)
{
  int result = 0;
  int top = args_len - 1;

  /*@
    loop invariant 0 <= result <= args_len;
    loop invariant -1 <= top < args_len;
    loop invariant result <= top + 1;
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
