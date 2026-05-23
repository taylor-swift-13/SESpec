#include <stddef.h>

int countRotation(int * array, int array_len, int count);

/*@ 
  requires array_len >= 0;
  requires 0 <= count <= array_len;
  requires count == 0 || \valid_read(array + (0 .. count-1));
  assigns \nothing;

  behavior empty:
    assumes count == 0;
    ensures \result == 0;

  behavior nonempty:
    assumes count > 0;
    ensures 1 <= \result <= count;

  complete behaviors;
  disjoint behaviors;
*/
int countRotation(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		/*@
		  loop invariant count > 0;
		  loop invariant 0 <= r <= top <= count - 1;
		  loop assigns r, top;
		  loop variant top - r;
		*/
		while (r < top) {
			/*@ assert 0 <= r <= count - 1; */
			/*@ assert 0 <= top <= count - 1; */
			if (array[r] < array[top]) {
				return r + 1;
			}
			int end = (r + top) / 2;
			/*@ assert r <= end < top; */
			/*@ assert 0 <= end <= count - 1; */
			if (array[end] > array[r]) {
				r = end;
			} else {
				top = end;
			}
		}
		return r + 1;
}
