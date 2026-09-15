#include <stddef.h>

int findPeak(int * data, int data_len, int array);

/*@ predicate is_peak(int *data, integer n, integer i) =
      0 <= i < n &&
      ((i == 0) || data[i] >= data[i - 1]) &&
      ((i == n - 1) || data[i] >= data[i + 1]);
*/

/*@ 
  requires array >= 1;
  requires 0 <= array <= data_len;
  requires \valid_read(data + (0 .. array - 1));
  assigns \nothing;
  ensures 0 <= \result < array;
  ensures is_peak(data, array, \result);
*/
int findPeak(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		/*@
		  loop invariant 0 <= found <= top <= array - 1;
		  loop invariant \exists integer p; found <= p <= top && is_peak(data, array, p);
		  loop assigns found, top;
		  loop variant top - found;
		*/
		while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
