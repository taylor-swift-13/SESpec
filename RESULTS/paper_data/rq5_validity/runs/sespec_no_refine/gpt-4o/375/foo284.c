
/*@
  requires num >= 0 && p >= 0;
  assigns p, \nothing;
  ensures \result == combination(num, \old(p));
*/
int foo284(int num, int p) {

    if (p > num - p)
        p = num - p;
    int b = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop invariant 1 <= r <= p + 1;
      loop invariant b == combination(num, r - 1);
      loop assigns r, b;
      loop variant p - r;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }

    return b;
}
