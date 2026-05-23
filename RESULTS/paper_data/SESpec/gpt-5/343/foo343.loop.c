
/*@
  requires \true;
*/
int foo343(int code, int b, int l, int c) {

    int ret = 0;
        
    /*@
      loop invariant l == \at(l,Pre);
      loop invariant c == \at(c,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop invariant ret >= 0;
      loop invariant l <= c ==> \forall integer i; l <= i <= \min(\at(c,Pre), c) ==> i >= l;
      loop invariant \at(l,Pre) <= \at(c,Pre) ==> (\at(l,Pre) <= \at(c,Pre));
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
