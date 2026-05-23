
/*@ logic integer common_div_count_upto(integer n, integer x, integer y) =
      n <= 0 ? 0 :
      common_div_count_upto(n - 1, x, y) + ((x % n == 0 && y % n == 0) ? 1 : 0);
*/
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures x <= 0 || y <= 0 ==> \result == 0;
*/
int foo381(int x, int y) {
    if (x <= 0 || y <= 0) {
        return 0;
    }

    int count = 0;
    int m = (x < y ? x : y);

    /*@
      loop invariant count >= 0;
      loop invariant 1 <= i;
      loop invariant i <= m + 1;
      loop invariant count <= i - 1;
      loop assigns count, i;
      loop variant m - i + 1;
    */
    for (int i = 1; i <= m; i++) {
        if (x % i == 0 && y % i == 0) {
            count++;
        }
    }

    return count;
}
