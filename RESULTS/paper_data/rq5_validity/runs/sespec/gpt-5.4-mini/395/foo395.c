


/*@ logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n - 1) + n * n * n * n; */
/*@
  requires 0 <= p <= 40;
  assigns \nothing;
  ensures p < 1 ==> \result >= 0;
  ensures p >= 1 ==> \result == 16 * sum4(p);
  ensures \result >= 0;
  ensures \result >= 0;
*/
int foo395(int p) {
    int odd = 0;

    /*@
      loop invariant p == \at(p,Pre);
      loop invariant 0 <= odd;
      loop invariant odd >= 0;
      loop assigns odd;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }

    return odd;
}
