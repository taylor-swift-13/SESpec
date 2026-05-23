
        /*@
  requires 0 <= p <= num;
  assigns \nothing;
  ensures \result >= 1;
*/
int foo375(int num, int p) {

  if (p > num - p)
    p = num - p;
  int b = 1;

  /*@
    loop invariant 1 <= b;
    loop invariant 1 <= r <= p + 1;
    loop assigns r, b;
    loop variant p - r + 1;
  */
  for (int r = 1; r <= p; r++) {
    b = b * (num - r + 1) / r;
  }

  return b;
}
