
/*@
  logic integer sum_of_cubes(integer n) =
    n <= 0 ? 0 : n * n * n + sum_of_cubes(n - 1);

  logic integer sum_of_integers(integer n) =
    n <= 0 ? 0 : n + sum_of_integers(n - 1);
*/

/*@
  requires n >= 0;
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
    */
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant sum1 == sum_of_integers(i - 1);
      loop invariant sum == sum_of_cubes(n);
      loop invariant n == \at(n,Pre);
      loop assigns i, sum1;
    */
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }

    return sum - sum1;
}
