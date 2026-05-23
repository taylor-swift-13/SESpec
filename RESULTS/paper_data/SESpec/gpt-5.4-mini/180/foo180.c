
/*@
  requires count > 0;
  requires count <= rot_len;
  requires \valid_read(rot + (0 .. count - 1));
  assigns \nothing;
  ensures \result >= 1;
  ensures \result <= count + 1 ;
  ensures count == 1 ==> \result >= 1 ;
  ensures rot[0] < rot[count - 1] ==> \result >= 1 ;
  ensures \result >= 1;
*/
int foo180(int * rot, int rot_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            /*@
          loop invariant 0 <= r;
          loop invariant r <= top + 1;
          loop invariant 0 <= top;
          loop invariant top < count;
          loop invariant count == \at(count, Pre);
          loop invariant rot_len == \at(rot_len, Pre);
          loop invariant rot == \at(rot, Pre);
          loop invariant \forall integer k; 0 <= k < rot_len ==> rot[k] == \at(rot[k], Pre);
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
