
/*@ predicate same_array{L1,L2}(int* a, integer lo, integer hi) =
      \forall integer k; lo <= k < hi ==> \at(a[k],L1) == \at(a[k],L2);
*/

/*@
  requires \valid(rot + (0 .. rot_len-1));
  requires rot_len >= 0;
  requires \at(count,Pre) != 0;
*/
int foo180(int * rot, int rot_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
        /*@
          loop invariant 0 <= r;
          loop invariant top <= \at(count,Pre) - 1;
          loop invariant (r == 0) || (r <= top);
          loop invariant count == \at(count,Pre);
          loop invariant rot_len == \at(rot_len,Pre);
          loop invariant rot == \at(rot,Pre);
          loop invariant same_array{Pre,Here}(rot, 0, rot_len);
          loop invariant (0 < \at(count,Pre) - 1) ==>
                         (((top == \at(count,Pre) - 1) && (r == 0))
                           || (r < top ==> rot[r] >= rot[top]));
          loop assigns r, top;
        */
        while (r < top) {
			if (rot[r] < rot[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (rot[i] > rot[r]) {
				r = i;
			} else {
				top = i;
			}
		}
            
		return r + 1;
}
