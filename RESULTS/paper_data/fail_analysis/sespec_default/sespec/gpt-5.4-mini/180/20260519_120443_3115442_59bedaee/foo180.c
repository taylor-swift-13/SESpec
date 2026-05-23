
/*@
  logic integer rot_max(int* rot, integer lo, integer hi) =
    lo >= hi ? rot[lo - 1] :
    (rot_max(rot, lo, hi - 1) > rot[hi - 1] ? rot_max(rot, lo, hi - 1) : rot[hi - 1]);
*/

/*@
  requires \valid(&rot[0] + (0..rot_len-1));
  requires \forall integer i; 0 <= i < rot_len ==> 0 <= rot[i] <= 100;
  requires rot_len > 0;
  requires rot_len < 100;
  requires count >= 0;
  requires count <= rot_len;
  assigns \nothing;
  ensures count == 0 ==> \result == 0;
  ensures count != 0 ==> 1 <= \result <= count;
  
*/
int foo180(int * rot, int rot_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(count,Pre) - 1) ==> (((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(rot_len == \at(rot_len,Pre))&&(rot == \at(rot,Pre))) || (0 <= r <= top));
          loop invariant (0 < \at(count,Pre) - 1) ==> (((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(rot_len == \at(rot_len,Pre))&&(rot == \at(rot,Pre))) || (0 <= top < \at(count,Pre)));
          loop invariant (!(0 < \at(count,Pre) - 1)) ==> ((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(rot_len == \at(rot_len,Pre))&&(rot == \at(rot,Pre)));
          loop invariant count == \at(count,Pre);
          loop invariant rot_len == \at(rot_len,Pre);
          loop invariant rot == \at(rot,Pre);
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
