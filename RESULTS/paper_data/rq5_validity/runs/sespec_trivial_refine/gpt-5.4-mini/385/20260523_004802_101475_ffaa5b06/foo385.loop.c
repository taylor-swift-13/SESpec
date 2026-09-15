
int foo385(int n, int m) {
  /*@
    loop invariant \true;
    loop assigns i;
  */
  for (int i = n; i >= 0; i--) {
    if (i % m == 0) {
      return i;
    }
  }

  return -1;
}
