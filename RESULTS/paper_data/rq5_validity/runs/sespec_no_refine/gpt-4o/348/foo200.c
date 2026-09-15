
/*@
  logic integer count_non_divisible(int l, int r, int a) =
    \sum(l <= i <= r, i % a != 0);
*/

/*@
  requires a > 0 && n >= 0 && l <= r;
  assigns count, i;
  ensures \result == -1 ==> count_non_divisible(l, r, a) < n;
  ensures \result != -1 ==> \result >= l && \result <= r && count_non_divisible(l, \result, a) == n;
*/
int foo200(int a, int n, int l, int r) {

    int count = 0;

    /*@
      loop invariant l <= i <= r + 1;
      loop invariant count == count_non_divisible(l, i - 1, a);
      loop invariant r == \at(r, Pre);
      loop invariant l == \at(l, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
      loop assigns i, count;
      loop variant r - i;
    */
    for (int i = l; i <= r; i++) {
        if (i % a != 0) {
            count++;
        }
        if (count == n) {
            return i;
        }
    }

    return -1;
}
