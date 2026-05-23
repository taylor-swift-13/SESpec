
/*@
  requires n >= 2;
  assigns \nothing;
  ensures \result >= 0;
  ensures n < 2 ==> \result == 0;
*/
int foo345(int n) {
    int sum = 0;
    int i;

    /*@
      loop invariant 2 <= i <= n + 1;
      loop invariant sum >= 0;
      loop assigns i, sum;
      loop variant n + 1 - i;
    */
    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
    }

    return sum;
}
