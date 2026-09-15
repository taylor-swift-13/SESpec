
/*@
  logic integer count_nonmul(integer a, integer b, integer code) =
    a > b ? 0 :
    ( (a % code != 0) ? 1 : 0 ) + count_nonmul(a+1, b, code);
*/
/*@
   requires c == \at(c,Pre);
   requires l == \at(l,Pre);
   requires b == \at(b,Pre);
   requires code == \at(code,Pre);
   requires b >= 0;
   requires l <= c;
   requires code != 0;
   assigns \nothing;
   ensures \result != -1 ==> l <= \result <= c;
 */
int foo343(int code, int b, int l, int c) {

    int ret = 0;

    /*@
      loop invariant l <= loop;
      loop invariant 0 <= ret <= (loop - l);
      loop invariant \forall integer k; l <= k < loop ==> ((k % code != 0) ==> (0 <= ret));
      loop invariant c == \at(c,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop assigns loop, ret;
    */
    for (int loop = l; loop <= c; loop++) {
        if (loop % code != 0) {
            ret++;
        }
        if (ret == b) {
            return loop;
        }
    }

    return -1;
}
