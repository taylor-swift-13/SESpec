
/* The loop performs a binary search for an index cur such that i[cur] == cur.
   The invariants below capture that the search interval is always within
   the original bounds and that if a solution has been found it must be the
   one returned. I added a simple logic predicate to express that all inspected
   indices outside the current search interval do not satisfy i[k]==k, which
   helps relate ret/stop with the existence of a fixed point inside the
   current interval. */

/*@
  logic integer lo_pre(integer a) = a - 1;
*/

/*@
  predicate no_fixed_outside(int *i, integer lo, integer hi) =
    \forall integer k; k < lo || k > hi ==> i[k] != k;
*/
        
int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /*@
          loop invariant (0 <= \at(array,Pre) - 1) ==> (ret >= 0 && stop <= \at(array,Pre) - 1);
          loop invariant (!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(i_len == \at(i_len,Pre))&&(i == \at(i,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant i_len == \at(i_len,Pre);
          loop invariant i == \at(i,Pre);
        */
            while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			if (i[cur] == cur) {
				return cur;
			} else if (i[cur] < cur) {
				ret = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
            
		return -1;
}
