
        /*@
        
        */

/*@
  requires 0 <= args_len;
  requires \valid_read(args + (0 .. args_len - 1));
  requires 0 <= n <= args_len;
  requires \forall integer i, j; 0 <= i <= j < n ==> args[i] <= args[j];
  assigns \result \from args[0 .. args_len - 1], n, array;
  ensures \result == -1 || (0 <= \result < n && args[\result] == array);
  ensures \result == -1 || \forall integer k; 0 <= k < \result ==> args[k] != array;
*/
int foo220(int *args, int args_len, int array, int n) {
  int i = 0;
  int hi = n - 1;
  int result = -1;

  /*@
    loop invariant 0 <= i;
    loop invariant -1 <= hi < n;
    loop invariant i <= n;
    loop invariant i <= hi + 1;
    loop invariant result == -1 || (0 <= result < n && args[result] == array);
    loop invariant result == -1 || \forall integer k; 0 <= k < result ==> args[k] != array;
    loop invariant \forall integer k; 0 <= k < i ==> args[k] < array;
    loop assigns i, hi, result;
    loop variant hi - i + 1;
  */
  while (i <= hi) {
    int tmp = (i + hi) / 2;
    if (args[tmp] == array) {
      result = tmp;
      hi = tmp - 1;
    } else if (args[tmp] < array) {
      i = tmp + 1;
    } else {
      hi = tmp - 1;
    }
  }

  return result;
}
