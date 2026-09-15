
/*@
  logic integer prod_from_to(integer a, integer b, integer n) =
    a > b ? 1 :
    a == b ? (n - a + 1) :
    (n - a + 1) * prod_from_to(a+1, b, n);
*/

/*@
  requires \true;
*/
int foo312_c390(int n, int k) {

    int res = 1;
    int i = 1;

    /*@
      loop invariant (1 <= \at(k,Pre)) ==> (1 <= i && i <= \at(k,Pre) + 1);
      loop invariant (1 <= \at(k,Pre)) ==> ((i-1) <= \at(k,Pre));
      loop invariant (!(1 <= \at(k,Pre))) ==> ((i == 1)&&(res == 1)&&(k == \at(k,Pre))&&(n == \at(n,Pre)));
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
