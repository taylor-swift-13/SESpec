
/*@
  predicate unimodal_slice(int* a, integer lo, integer hi) =
    lo <= hi &&
    (\exists integer p; lo <= p <= hi &&
       (\forall integer j; lo <= j < p ==> a[j] < a[j+1]) &&
       (\forall integer j; p <= j < hi ==> a[j] >= a[j+1])
    );
*/

/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  requires \valid(array + (0 .. array_len-1));
  requires 0 <= Array && Array <= array_len;
  requires Array == \at(Array,Pre);
  requires array_len == \at(array_len,Pre);
  requires array == \at(array,Pre);
*/
int foo300(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= found && found <= array_len;
          loop invariant -1 <= top && top < array_len;
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
          loop invariant (0 < \at(Array,Pre) - 1) ==> (found <= \at(Array,Pre) - 1 && top <= \at(Array,Pre) - 1);
          loop invariant found <= top || found == top + 1;
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
