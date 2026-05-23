

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires 0 < Array <= array_len;
  requires \forall integer i; 0 <= i < Array - 1 ==> array[i] < array[i + 1];
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result < Array;
*/
int foo300(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= found;
          loop invariant found <= top;
          loop invariant 0 <= top;
          loop invariant top < Array;
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
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
