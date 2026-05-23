
        /*@ logic integer foo397_sum(integer n) =
      n <= 0 ? 0 : foo397_sum(n - 1) + 16 * n * n * n * n; */
/*@
  requires 0 <= p <= 10;
  assigns \nothing;
  ensures \result == foo397_sum(p);
  ensures p <= 0 ==> \result == 0;
  ensures \result >= 0;
*/
int foo397(int p) {
    int even = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant even == foo397_sum(c - 1);
      loop invariant even >= 0;
      loop assigns even, c;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        even = even + (tmp * tmp * tmp * tmp);
    }

    return even;
}
