
/*@ 
  logic integer int_max(integer a, integer b) = a >= b ? a : b;
*/

/*@ 
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  requires \valid_read(array + (0 .. array_len - 1));
  requires Array > 0;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo300(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            /*@
          loop invariant found >= 0;
          loop invariant top <= Array - 1;
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
          loop assigns found, top;
            */
            while (found < top) {
			int i = found + (top - found) / 2;
			if (array[i] < array[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
            
		return found;
}
