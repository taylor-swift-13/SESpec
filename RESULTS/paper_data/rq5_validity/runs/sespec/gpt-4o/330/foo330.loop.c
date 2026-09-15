
/*@ 
  logic integer sum_cubes(integer start, integer end) =
    start > end ? 0 : start * start * start + sum_cubes(start + 1, end);

  logic integer sum_linear(integer start, integer end) =
    start > end ? 0 : start + sum_linear(start + 1, end);
*/

int foo330(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant diff == \at(diff, Pre);
      loop invariant max == 0;
      loop assigns j, result;
    */
    for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }

    /*@
      loop invariant diff == \at(diff, Pre);
      loop assigns j, max;
    */
    for (int j = 1; j <= diff; j++) {
        max += j;
    }

    return result - max;
}
