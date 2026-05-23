/*@ 
  logic integer odd_count{L}(int *a, integer n) =
    n <= 0 ? 0 :
    odd_count{L}(a, n-1) + ((a[n-1] % 2 != 0) ? 1 : 0);

  logic integer last_odd_at_odd_parity{L}(int *a, integer n) =
    n <= 0 ? 0 :
    (((a[n-1] % 2 != 0) && ((odd_count{L}(a, n) % 2) != 0)) 
      ? a[n-1] 
      : last_odd_at_odd_parity{L}(a, n-1));
*/

/*@ 
  requires array_len >= 0;
  requires 0 <= Array <= array_len;
  requires Array == 0 || \valid_read(array + (0..Array-1));
  assigns \nothing;
  ensures \result == last_odd_at_odd_parity{Pre}(array, Array);
  ensures (\result == 0) <==> (odd_count{Pre}(array, Array) == 0);
  ensures (odd_count{Pre}(array, Array) > 0) ==> (\result % 2 != 0);
*/
int getOddOccurrence(int * array, int array_len, int Array);

 /*@ 
   requires array_len >= 0;
   requires 0 <= Array <= array_len;
   requires Array == 0 || \valid_read(array + (0..Array-1));
   assigns \nothing;
   ensures \result == last_odd_at_odd_parity{Pre}(array, Array);
   ensures (\result == 0) <==> (odd_count{Pre}(array, Array) == 0);
   ensures (odd_count{Pre}(array, Array) > 0) ==> (\result % 2 != 0);
 */
int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@
		  loop invariant 0 <= index <= Array;
		  loop invariant 0 <= start <= index;
		  loop invariant start == odd_count{Pre}(array, index);
		  loop invariant ret == last_odd_at_odd_parity{Pre}(array, index);
		  loop assigns index, start, ret;
		  loop variant Array - index;
		*/
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
}
