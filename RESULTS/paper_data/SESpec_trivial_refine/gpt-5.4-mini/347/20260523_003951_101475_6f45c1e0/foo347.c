
/*@ logic integer iabs(integer v) = v < 0 ? -v : v; */
/*@ logic integer count_divisors(integer x, integer n) =
      n <= 0 ? 0 : count_divisors(x, n - 1) + (x % n == 0 ? 1 : 0); */
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= iabs(\old(y));
  ensures \result == count_divisors(\old(x), iabs(\old(y)));
  ensures \old(y) == 0 ==> \result == 0;
*/
int foo347(int x, int y) {
    int n = y;
    if (n < 0) {
        n = -n;
    }

    int count = 0;
    int i = 1;

    if (n > 0) {
        count = 1; /* 1 always divides any integer x */
        i = 2;
    }

    /*@
      loop invariant 0 <= n;
      loop invariant 1 <= i <= n + 1;
      loop invariant 0 <= count;
      loop invariant count <= i - 1;
      loop invariant count == count_divisors(x, i - 1);
      loop assigns i, count;
    */
    while (i <= n) {
        if (x % i == 0) {
            count = count + 1;
        }
        i++;
    }

    return count;
}
