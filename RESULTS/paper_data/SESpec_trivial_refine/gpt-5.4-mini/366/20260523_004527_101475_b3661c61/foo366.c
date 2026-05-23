
        /*@
  requires n >= 2;
  assigns \nothing;
  ensures \result == n / 2 + 1;
  ensures \result >= 2;
  ensures \result <= n / 2 + 1;
*/
int foo366(int n) {
    int sum = 0;
    int count = 0;

    /*@
      loop assigns i, sum, count;
      loop invariant 1 <= i <= n + 1;
      loop invariant count == (i - 1) / 2;
      loop invariant sum == count * (count + 1);
      loop invariant count >= 0;
      loop invariant sum >= 0;
      loop variant n - i + 1;
    */
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i;
            count++;
        }
    }

    return sum / count;
}
