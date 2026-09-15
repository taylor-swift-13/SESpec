
/*@
  logic integer sum_of_cubes(integer n) =
    (n <= 0) ? 0 : n * n * n + sum_of_cubes(n - 1);

  logic integer sum_of_integers(integer n) =
    (n <= 0) ? 0 : n + sum_of_integers(n - 1);
*/

int foo172(int n) {

    int sum = 0;
    int sum1 = 0;

    /*@
      loop invariant sum1 == 0;
      loop invariant n == \at(n,Pre);
      loop assigns i, sum;
    */
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }

    /*@
      loop invariant n == \at(n,Pre);
      loop assigns i, sum1;
    */
    for (int i = 1; i <= n; i++) {
        sum1 += i;
    }

    return sum - sum1;
}
