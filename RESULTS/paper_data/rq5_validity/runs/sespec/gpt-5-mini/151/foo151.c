
/*@
  logic integer count_odds_in_result(integer lo, integer hi) =
    lo >= hi ? 0
             : count_odds_in_result(lo, hi - 1) + ((hi - 1 + 1) % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer count_evens_in_result(integer lo, integer hi) =
    lo >= hi ? 0
             : count_evens_in_result(lo, hi - 1) + ((hi - 1 + 1) % 2 == 0 ? 1 : 0);
*/

/*@
  requires number >= 0;
  requires p >= 0;
  assigns \nothing;
*/
int foo151(int number, int p) {

    int *result = (int *)malloc(sizeof(int) * (number));
    int result_len = number;
    int *b = (int *)malloc(sizeof(int) * (number));
    int b_len = number;
    int c, ii = 0;

    /*@
      loop invariant 0 <= c <= number;
      loop invariant (c < number) ==> (\forall integer k; 0 <= k < c ==> result[k] == k + 1);
      loop invariant (!(c < number)) ==> (\forall integer k; 0 <= k < number ==> result[k] == k + 1);
      loop assigns c, result[0..number-1];
    */
    for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }

    /* Second loop: count odd elements seen so far */
    /*@
      loop invariant 0 <= c <= number;
      loop invariant 0 <= ii <= c;
      loop assigns c, b[0..number-1], ii;
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 != 0) {
            ii++;
            if (ii == p) {
                return result[c];
            }
        }
    }

    /* Third loop: count even elements seen so far */
    /*@
      loop invariant 0 <= c <= number;
      loop assigns c, b[0..number-1], ii;
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 == 0) {
            ii++;
            if (ii == p) {
                return result[c];
            }
        }
    }

    return 0;
}
