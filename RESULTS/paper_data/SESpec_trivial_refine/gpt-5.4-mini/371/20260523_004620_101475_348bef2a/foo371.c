
/*@
  requires p != 0;
  assigns \nothing;

  ensures value >= 1 && (\exists integer i; 1 <= i <= value && (i % p) == z) ==> \result != 0;

  ensures value >= 1 ==> (\forall integer i; 1 <= i <= value && (i % p) == z ==> i <= \result);
*/
int foo371(int value, int p, int z) {
  int result = 0;

  /*@
    loop invariant \forall integer i; 1 <= i < c && (i % p) == z ==> i <= result;
    loop assigns c, result;
    loop variant value + 1 - c;
  */
  for (int c = 1; c <= value; c++) {
    if ((c % p) == z) {
      result = c;
    }
  }

  return result;
}
