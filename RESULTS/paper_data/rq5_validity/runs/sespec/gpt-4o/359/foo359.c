
/*@
  logic integer sum_odd(integer start, integer end) =
    (start > end) ? 0 : (start % 2 != 0 ? start : 0) + sum_odd(start + 1, end);

  logic integer count_odd(integer start, integer end) =
    (start > end) ? 0 : (start % 2 != 0 ? 1 : 0) + count_odd(start + 1, end);
*/

/*@
  requires size > 0; // Strengthened precondition to avoid division by zero
  assigns \nothing;
*/
int foo359(int size) {

    int ret = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant size == \at(size, Pre);
      loop invariant ret >= 0; // Ensure ret is non-negative
      loop assigns c, ret, total;
      loop variant size - c;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }

    return ret / total;
}
