
/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == sum_of_cubes(n) - sum_of_integers(n);
*/
int foo172(int n) {

    int sum = 0;
    int sum1 = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant sum == sum_of_cubes(i - 1);
      loop invariant sum1 == 0;
      loop invariant n == \at(n,Pre);
      loop assigns i, sum;
      loop variant n - i;
    */
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant sum1 == sum_of_integers(i - 1);
      loop invariant n == \at(n,Pre);
      loop assigns i, sum1;
      loop variant n - i;
    */
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }

    return sum - sum1;
}
