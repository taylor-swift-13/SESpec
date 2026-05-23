
int foo344(int code, int b, int l, int m) {

    int ret = 0;

    /*@
      loop invariant l == \at(l,Pre);
      loop invariant m == \at(m,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop invariant ret >= 0;

      loop invariant \forall integer k; l <= k < c ==> ((k % code != 0) || (k % code == 0));

      loop invariant ret == 0 ==> (\forall integer k; l <= k < c ==> k % code == 0);

      loop invariant c <= \at(m,Pre) ==> ( ((c % code != 0) && ret + 1 >= ret) || ((c % code == 0) && ret >= 0) );
      loop invariant (c <= \at(m,Pre)) ==> ((ret < b) ==> (ret + ((c % code != 0) ? 1 : 0) <= b));

      loop assigns c, ret;
    */
    for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            ret++;
        }
        if (ret == b) {
            return c;
        }
    }

    return -1;
}
