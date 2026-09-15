
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
  requires 0 <= array <= args_len;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer i, j; 0 <= i < j < array ==> args[i] < args[j];
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
  ensures \result != -1 ==> args[\result] == \result;
  ensures \result == -1 ==> \forall integer i; 0 <= i < array ==> args[i] != i;
*/
int foo259(int * args, int args_len, int array) {
  int i = 0;
  int stop = array - 1;

  /*@
    loop invariant 0 <= i;
    loop invariant -1 <= stop < array;
    loop invariant i <= stop + 1;
    loop invariant \forall integer k; 0 <= k < i ==> args[k] != k;
    loop invariant \forall integer k; stop < k < array ==> args[k] != k;
    loop assigns i, stop;
    loop variant stop - i + 1;
  */
  while (i <= stop) {
    int cur = i + (stop - i) / 2;
    if (args[cur] == cur) {
      return cur;
    } else if (args[cur] < cur) {
      i = cur + 1;
    } else {
      stop = cur - 1;
    }
  }

  return -1;
}
