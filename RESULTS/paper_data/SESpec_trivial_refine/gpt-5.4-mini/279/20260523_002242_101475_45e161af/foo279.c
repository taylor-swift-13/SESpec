
        /*@
logic integer foo279_acc(int *a, integer n, integer g, integer ret) =
  n <= 0 ? g :
  (a[0] > ret ?
    foo279_acc(a + 1, n - 1, (g > ret ? g : ret), ret) :
    foo279_acc(a + 1, n - 1, g, a[0]));
*/
/*@
  requires args_len > 0;
  requires \valid_read(args + (0 .. args_len-1));
  assigns \nothing;

  ensures \result >= 0;
  ensures \result <= (args[0] < 0 ? 0 : args[0]);
*/
int foo279(int *args, int args_len) {
  int g = 0;
  int ret = args[0];

  /*@
    loop invariant 1 <= j <= args_len;
    loop invariant 0 <= g;
    loop invariant ret <= args[0];
    loop invariant (\forall integer k; 0 <= k < j ==> ret <= args[k]);
    loop invariant g <= (args[0] < 0 ? 0 : args[0]);
    loop assigns j, g, ret;
    loop variant args_len - j;
  */
  for (int j = 1; j < args_len; j++) {
    if (args[j] > ret) {
      g = g > ret ? g : ret;
    } else {
      ret = args[j];
    }
  }

  return g;
}
