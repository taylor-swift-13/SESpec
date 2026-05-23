
/*@
  // No additional predicates or logic functions are required.
*/

/*@
  requires \valid(&rot[0] + (0..rot_len-1));
  requires \forall integer i; 0 <= i < rot_len ==> 0 <= rot[i] <= 100;
  requires rot_len > 0;
  requires rot_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
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
