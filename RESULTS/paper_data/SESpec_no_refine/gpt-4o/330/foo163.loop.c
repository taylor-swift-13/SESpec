
/*@
  logic integer sum_of_cubes(integer n) =
    n <= 0 ? 0 : n * n * n + sum_of_cubes(n - 1);
*/

/*@
  logic integer sum_of_integers(integer n) =
    n <= 0 ? 0 : n + sum_of_integers(n - 1);
*/

int foo163(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop assigns j, result;
    */
    for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }

    /*@
      loop invariant diff == \at(diff,Pre);
      loop assigns j, max;
    */
    for (int j = 1; j <= diff; j++) {
        max += j;
    }

    return result - max;
}
