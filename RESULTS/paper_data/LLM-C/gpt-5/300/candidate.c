int findPeak(int * array, int array_len, int Array);

/*@ 
  requires Array > 0;
  requires 0 <= Array <= array_len;
  requires \valid_read(array + (0 .. Array-1));
  assigns \nothing;
  ensures 0 <= \result < Array;
  ensures (\result == 0 || array[\result] >= array[\result - 1]) &&
          (\result == Array - 1 || array[\result] >= array[\result + 1]);
*/
int findPeak(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		/*@
		  loop invariant 0 <= found <= top < Array;
		  loop invariant found == 0 || array[found - 1] < array[found];
		  loop invariant top == Array - 1 || array[top] >= array[top + 1];
		  loop assigns found, top;
		  loop variant top - found;
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
