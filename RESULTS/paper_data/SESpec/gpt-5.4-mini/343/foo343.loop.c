
/*@
  logic integer count_nondiv(integer code, integer l, integer u) =
    u <= l ? 0 :
    count_nondiv(code, l, u - 1) + (((u - 1) % code) != 0 ? 1 : 0);
*/

int foo343(int code, int b, int l, int c) {

		int ret = 0;
		
        /*@
          loop invariant 0 <= ret;
          loop invariant l <= loop;
          loop invariant ret == count_nondiv(code, l, loop);
          loop invariant ret <= loop - l;
          loop invariant code == \at(code,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant c == \at(c,Pre);
          loop invariant l == \at(l,Pre);
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
