
/*@
  logic integer sum_of_cubes(integer n) =
    n <= 0 ? 0 : n * n * n + sum_of_cubes(n - 1);
*/
/*@
  logic integer sum_of_integers(integer n) =
    n <= 0 ? 0 : n + sum_of_integers(n - 1);
*/

/*@
  requires diff >= 0;
  ensures \result == sum_of_cubes(diff) - sum_of_integers(diff);
*/
int foo161(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant 1 <= c <= diff + 1;
      loop invariant result == sum_of_cubes(c - 1);
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= diff; c++) {
        result += c * c * c;
    }

    /*@
      loop invariant 1 <= c <= diff + 1;
      loop invariant max == sum_of_integers(c - 1);
      loop invariant diff == \at(diff,Pre);
      loop assigns c, max;
    */
    for (int c = 1; c <= diff; c++) {
        max += c;
    }

    return result - max;
}
