
/*@
  requires \true;
  requires code != 0;
  assigns \nothing;
*/
int foo343(int code, int b, int l, int c) {

    int ret = 0;
        
    /*@
      loop invariant l == \at(l,Pre);
      loop invariant c == \at(c,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop invariant ret >= 0;
      loop assigns ret;
      loop variant c - loop + 1;
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
