
        /*@
        predicate sorted{L}(int *a, integer n) =
          \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
        */

/*@
  requires 0 <= args_len;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= args_len;
  ensures args_len == 0 ==> \result == 0;
  ensures \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i], Pre);
  ensures \result < args_len ==> 0 <= \result;
*/
int foo256(int * args, int args_len, int Array) {

  int ret = 0;
  int top = args_len - 1;

  /*@
    loop invariant 0 <= ret;
    loop invariant -1 <= top < args_len;
    loop invariant ret <= top + 1;
    loop invariant \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i], Pre);
    loop assigns ret, top;
    loop variant top - ret + 1;
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
