
/*@
  // No additional predicates or logic functions are required.
*/

int foo180(int * rot, int rot_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant count == count;
              loop invariant rot_len == rot_len;
              loop invariant rot == rot;
              loop invariant 0 <= r <= top < count;
              loop invariant \forall integer k; 0 <= k < rot_len ==> rot[k] == rot[k];
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
