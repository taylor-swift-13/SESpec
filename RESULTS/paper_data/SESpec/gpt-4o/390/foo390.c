
/*@
  logic integer product(integer start, integer end, integer n) =
    (start > end) ? 1 : (n - start + 1) * product(start + 1, end, n);
*/

/*@
  requires n >= 0; // Ensure n is non-negative, as negative values would lead to invalid computations.
  requires k >= 0; // Ensure k is non-negative, as the loop and logic assume k >= 0.
  requires n >= k; // Ensure n is greater than or equal to k for valid computations.
  assigns \nothing;
*/
int foo390(int n, int k) {

    int res = 1;
    int i = 1;

    /*@
      loop invariant 1 <= i;
      loop invariant i <= k + 1 || k < 1;
      loop invariant (1 <= \at(k,Pre)) ==> (i >= 1 && i <= k + 1);
      loop invariant (!(1 <= \at(k,Pre))) ==> ((i == 1) && (res == 1) && (k == \at(k,Pre)) && (n == \at(n,Pre)));
      loop invariant k == \at(k,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns res, i;
    */
    while (i <= k) {
        res *= (n - i + 1);
        i++;
    }

    return res;
}
