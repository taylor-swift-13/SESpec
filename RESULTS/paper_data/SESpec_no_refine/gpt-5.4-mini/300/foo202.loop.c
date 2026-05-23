
/*@
  logic integer max_index(integer a, integer b) = a > b ? a : b;
*/

int foo202(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            /*@
          loop invariant (0 < \at(Array,Pre) - 1) ==> (((top == \at(Array,Pre) - 1)&&(found == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (found <= top && top < \at(Array,Pre) && 0 <= found));
          loop invariant (0 < \at(Array,Pre) - 1) ==> (((top == \at(Array,Pre) - 1)&&(found == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (found <= top));
          loop invariant (!(0 < \at(Array,Pre) - 1)) ==> ((top == \at(Array,Pre) - 1)&&(found == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop assigns i, found, top;
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
