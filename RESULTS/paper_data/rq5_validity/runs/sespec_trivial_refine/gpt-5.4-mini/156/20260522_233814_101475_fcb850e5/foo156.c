
/*@
        predicate valid_array{L}(int *a, integer n) = \valid_read(a + (0 .. n-1));
        */

/*@ 
  requires valid_array(args, Array);
  requires Array <= args_len;
  assigns \result \from args[0 .. Array-1], Array;
  ensures \true;
*/
int foo156(int *args, int args_len, int Array) {

  int *mpis = (int *)malloc(sizeof(int) * Array);
  int mpis_len = Array;
  (void)mpis_len;

  /*@
    loop invariant \true;
    loop assigns array, mpis[0 .. Array-1];
    loop variant Array - array;
  */
  for (int array = 0; array < Array; array++) {
    mpis[array] = args[array];
  }

  /*@
    loop invariant \true;
    loop assigns i, mpis[1 .. Array-1];
    loop variant Array - i;
  */
  for (int i = 1; i < Array; i++) {

    /*@
      loop invariant \true;
      loop assigns p, mpis[i];
      loop variant i - p;
    */
    for (int p = 0; p < i; p++) {
      if (args[i] > args[p] && mpis[i] < (mpis[p] * args[i])) {
        mpis[i] = mpis[p] * args[i];
      }
    }
  }

  int num = mpis[0];

  /*@
    loop invariant \true;
    loop assigns i, num;
    loop variant Array - i;
  */
  for (int i = 1; i < Array; i++) {
    if (mpis[i] > num) {
      num = mpis[i];
    }
  }

  return num;
}
