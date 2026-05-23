
int foo342(int code, int b, int l, int m) {

    int result = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant l <= c;
      loop invariant 0 <= result <= c - l;
      loop invariant (c == l) ==> (result == 0);
      loop invariant (c <= \at(m,Pre)) ==> (c >= \at(l,Pre));
      loop invariant (c <= \at(m,Pre)) ==> (0 <= result <= c - \at(l,Pre));
      loop invariant m == \at(m,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop assigns c, result;
    */
    for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            result++;
        }
        if (result == b) {
            return c;
        }
    }

    return -1;
}
