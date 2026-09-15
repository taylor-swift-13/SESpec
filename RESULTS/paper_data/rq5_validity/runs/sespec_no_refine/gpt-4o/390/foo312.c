
/*@
  logic integer factorial_partial(integer n, integer k, integer i) =
    i > k ? 1 : (n - i + 1) * factorial_partial(n, k, i + 1);
*/

/*@
  requires (i == 1) && (res == 1) && (k == \at(k,Pre)) && (n == \at(n,Pre));
  assigns res, i;
  ensures (k < 1) ==> (\result == 1);
  ensures (k >= 1) ==> (\result == factorial_partial(n, k, 1));
*/
int foo312(int n, int k) {

    int res = 1;
    int i = 1;

    /*@
      loop invariant (1 <= \at(k,Pre)) ==> (res == factorial_partial(n, \at(k,Pre), i));
      loop invariant (1 <= \at(k,Pre)) ==> (1 <= i <= k + 1);
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
