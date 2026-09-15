
/*@
  logic integer count_even_up_to(integer x) =
    x <= 0 ? 0 : (x % 2 == 0 ? 1 : 0) + count_even_up_to(x - 1);
*/

/*@
  logic integer count_even_in_range(integer start, integer end) =
    start >= end ? 0 : (start % 2 == 0 ? 1 : 0) + count_even_in_range(start + 1, end);
*/

void foo253(int k) {

    int n;
    int i;

    n = 0;
    i = 0;

    /*@
      loop invariant (0 < 2 * \at(k,Pre)) ==> (0 <= i <= 2 * \at(k,Pre));
      loop invariant (!(0 < 2 * \at(k,Pre))) ==> ((i == 0)&&(n == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns n, i;
    */
    while (i < 2 * k) {
        if (i % 2 == 0) {
            n = n + 1;
        }
        i = i + 1;
    }
}
