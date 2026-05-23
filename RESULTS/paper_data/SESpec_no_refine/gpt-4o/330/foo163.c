
/*@
  logic integer sum_of_cubes(integer n) =
    n <= 0 ? 0 : n * n * n + sum_of_cubes(n - 1);
*/

/*@
  requires diff >= 0;
  assigns \nothing;
  ensures \result == sum_of_cubes(diff) - sum_of_integers(diff);
*/
int foo163(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop invariant result == sum_of_cubes(j - 1);
      loop assigns j, result;
      loop variant diff - j;
    */
    for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }

    /*@
      loop invariant diff == \at(diff,Pre);
      loop invariant max == sum_of_integers(j - 1);
      loop assigns j, max;
      loop variant diff - j;
    */
    for (int j = 1; j <= diff; j++) {
        max += j;
    }

    return result - max;
}
