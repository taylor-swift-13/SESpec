
/*@
  logic integer initial_k = \at(k, Pre);
*/

/*@
  predicate even(integer x) = x % 2 == 0;
*/

/*@
  predicate odd(integer x) = x % 2 != 0;
*/

/*@
  logic integer count_evens(integer x) = x / 2 + 1;
*/

/*@
  logic integer count_odds(integer x) = x / 2;
*/

/*@
  logic integer compute_n(int i, int k) =
    (i <= 2 * k) ? count_evens(i - 1) : 0;
*/

/*@
  requires k >= 0;
  ensures n == count_evens(2 * k - 1);
  ensures i == 2 * k;
  ensures k == \at(k, Pre);
*/
void foo253(int k) {
    int n;
    int i;

    n = 0;
    i = 0;

    /*@
      loop invariant (0 < 2 * \at(k, Pre)) ==> (n == compute_n(i, \at(k, Pre)));
      loop invariant (0 < 2 * \at(k, Pre)) ==> (0 <= i <= 2 * \at(k, Pre));
      loop invariant (!(0 < 2 * \at(k, Pre))) ==> ((i == 0) && (n == 0) && (k == \at(k, Pre)));
      loop invariant k == \at(k, Pre);
      loop assigns n, i;
    */
    while (i < 2 * k) {
        if (i % 2 == 0) {
            n = n + 1;
        }
        i = i + 1;
    }
}
