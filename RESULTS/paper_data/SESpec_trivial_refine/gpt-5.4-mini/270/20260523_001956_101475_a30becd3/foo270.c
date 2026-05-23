
/*@ logic integer foo270_rec(integer n, integer m) =
      n == 2 ? m * m :
      n > 2 ? ((m - 1) * (foo270_rec(n - 1, m) + foo270_rec(n - 2, m))) % 1000000007 :
      0;
*/

/*@
  requires count >= 2;
  assigns \result \from count, m;
  ensures count == 2 ==> \result == m * m;
*/
int foo270(int count, int m) {
    int w = 1000000007;

    if (count == 2) {
        return m * m;
    }

    int prev2 = 1;
    int prev1 = m;
    int curr = m * m;

    /*@
      loop invariant 3 <= d <= count + 1;
      loop assigns d, prev2, prev1, curr;
      loop variant count - d + 1;
    */
    for (int d = 3; d <= count; d++) {
        prev2 = prev1;
        prev1 = curr;
        curr = ((m - 1) * (prev1 + prev2)) % w;
    }

    return curr;
}
