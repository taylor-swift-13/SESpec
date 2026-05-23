


/*@
  requires array >= 0;
  requires array > 1 ==> \valid_read(args + (0..array-1));
  assigns \nothing;

  ensures array <= 1 ==> \result == 1;
  ensures array > 1 ==> 1 <= \result <= array;
  ensures array > 1 && \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && \result < array ==> \forall integer i; 0 <= i < \result - 1 ==> args[i] == i + 1;
*/
int foo226(int *args, int args_len, int array) {
  if (array == 0 || array == 1) {
    return 1;
  }

  int remaining;

  /*@
    loop invariant 1 <= remaining <= array + 1;
    loop invariant \forall integer i; 0 <= i < remaining - 1 ==> args[i] == i + 1;
    loop assigns remaining;
    loop variant array - remaining + 1;
  */
  for (remaining = 1; remaining <= array; remaining++) {
    if (args[remaining - 1] != remaining) {
      /*@ assert 1 <= remaining <= array; */
      /*@ assert args[remaining - 1] != remaining; */
      return remaining;
    }
  }

  /*@ assert remaining == array + 1; */
  /*@ assert \forall integer i; 0 <= i < array ==> i < remaining - 1; */
  /*@ assert \forall integer i; 0 <= i < array ==> args[i] == i + 1; */
  return array;
}
