
/*@ predicate in_bounds(int array_len, integer lo, integer hi) =
      0 <= lo <= hi < array_len; */

/*@ logic integer min_int(integer a, integer b) = a < b ? a : b; */

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures array == \old(array);
  ensures array_len == \old(array_len);
  ensures Array == \old(Array);
  ensures \forall integer k; 0 <= k < array_len ==> array[k] == \old(array[k]);
  ensures 0 <= \result;
  ensures \result == \result;
*/
int foo202(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= found;
          loop invariant top <= \at(Array,Pre) - 1;
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
          loop invariant (0 < \at(Array,Pre) - 1) ==> (((top == \at(Array,Pre) - 1) && (found == 0) && (Array == \at(Array,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre))) || (0 <= found && top <= \at(Array,Pre) - 1));
          loop invariant (0 < \at(Array,Pre) - 1) ==> (((top == \at(Array,Pre) - 1) && (found == 0) && (Array == \at(Array,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre))) || (top <= \at(Array,Pre) - 1));
          loop invariant (!(0 < \at(Array,Pre) - 1)) ==> ((top == \at(Array,Pre) - 1) && (found == 0) && (Array == \at(Array,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre)));
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
