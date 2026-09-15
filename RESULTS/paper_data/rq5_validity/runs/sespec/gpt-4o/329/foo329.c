
/*@
  logic integer sum_cubes(integer start, integer end) =
    start > end ? 0 : start * start * start + sum_cubes(start + 1, end);
*/

/*@
  requires diff >= 0; // Ensure valid loop bounds
  ensures diff == \at(diff, Pre); // diff remains unchanged
  assigns \nothing; // No caller-visible state is modified
*/
int foo329(int diff) {

    int ret = 0;
    int max = 0;

    /*@
      loop invariant diff == \at(diff, Pre);
      loop invariant 1 <= j <= diff + 1;
      loop assigns j, ret;
      loop variant diff - j; // Decreasing loop variant
    */
    for (int j = 1; j <= diff; j++) {
        ret += j * j * j;
    }

    /*@
      loop invariant diff == \at(diff, Pre);
      loop invariant max == (j - 1) * j / 2; // Sum of integers from 1 to j-1
      loop invariant 1 <= j <= diff + 1;
      loop assigns j, max;
      loop variant diff - j; // Decreasing loop variant
    */
    for (int j = 1; j <= diff; j++) {
        max += j;
    }

    return ret - max;
}
