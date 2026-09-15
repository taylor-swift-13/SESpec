
/*@
  requires code > 0;
  requires b >= 0;
  requires l <= c;
  requires c >= 0;
  requires l >= 0;
  ensures \result == -1 || (\result >= l && \result <= c);
  ensures \result == -1 || (\result % code != 0);
  ensures \result == -1 || (\exists integer k; l <= k <= c && k % code != 0 && k == \result);
  ensures \result == -1 || (\forall integer k; l <= k < \result ==> k % code == 0 || (\exists integer m; m == b && k % code != 0));
*/

int foo343(int code, int b, int l, int c) {

    int ret = 0;

    /*@
      loop invariant l <= loop <= c + 1;
      loop invariant ret >= 0;
      loop invariant c == \at(c, Pre);
      loop invariant l == \at(l, Pre);
      loop invariant b == \at(b, Pre);
      loop invariant code == \at(code, Pre);
      loop invariant \forall integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1);
      loop invariant \forall integer k; l <= k < loop ==> (k % code != 0 ==> (\exists integer m; m == ret));
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
