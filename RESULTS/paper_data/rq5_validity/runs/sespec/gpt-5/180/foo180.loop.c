
/* No helper logic or predicates are required for this loop. */

int foo180(int * rot, int rot_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= top < count ==> r < count;
          loop invariant count == \at(count,Pre);
          loop invariant rot_len == \at(rot_len,Pre);
          loop invariant rot == \at(rot,Pre);
          loop invariant \forall integer k; 0 <= k < rot_len ==> rot[k] == \at(rot[k], Pre);
          loop invariant \forall integer k; count <= k < rot_len ==> rot[k] == \at(rot[k], Pre);
          loop invariant r < top ==> ((r + top) / 2) >= r && ((r + top) / 2) <= top;
          loop invariant r < top ==> (top - r) >= 1;
          loop invariant r >= 0 && top >= 0 ==> r + 1 <= top + 1;
          loop invariant (!(0 < \at(count,Pre) - 1)) ==> ((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(rot_len == \at(rot_len,Pre))&&(rot == \at(rot,Pre)));
          loop invariant count == \at(count,Pre);
          loop invariant rot_len == \at(rot_len,Pre);
          loop invariant rot == \at(rot,Pre);
          loop invariant \forall integer k; 0 <= k < rot_len ==> rot[k] == \at(rot[k], Pre) ;
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
