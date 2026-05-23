
/*@
  logic boolean is_divisor(integer n, integer i) = (n % i == 0);
*/

/*@
  requires n > 0;
  assigns \nothing;
  ensures \result == \old(n) || (\exists integer i; 2 <= i <= \old(n) / i && is_divisor(\old(n), i) && \result == i);
*/
int foo268(int n) {
    int i = 2;

    /*@
      loop invariant 2 <= i;
      loop invariant i <= n + 1;
      loop invariant n == \at(n, Pre);
      loop invariant \forall integer k; 2 <= k < i ==> !is_divisor(n, k);
      loop assigns i;
      loop variant n / i;
    */
    while (i <= n / i) {
        if (n % i == 0) {
            return i;
        }
        i++;
    }

    return n;
}
