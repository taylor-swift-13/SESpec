
/*@ 
  logic integer sum_cubes(integer start, integer end) = 
    start > end ? 0 : start * start * start + sum_cubes(start + 1, end);
*/

/*@ 
  logic integer sum_linear(integer start, integer end) = 
    start > end ? 0 : start + sum_linear(start + 1, end);
*/

/*@
  requires diff >= 1;
  assigns \nothing;
*/
int foo330(int diff) {

    int result = 0;
    int max = 0;

    /*@
      loop invariant diff == \at(diff, Pre);
      loop invariant j >= 1;
      loop assigns j, result;
      loop variant diff - j;
    */
    for (int j = 1; j <= diff; j++) {
        result += j * j * j;
    }

    /*@
      loop invariant diff == \at(diff, Pre);
      loop invariant j >= 1;
      loop assigns j, max;
      loop variant diff - j;
    */
    for (int j = 1; j <= diff; j++) {
        max += j;
    }

    return result - max;
}
