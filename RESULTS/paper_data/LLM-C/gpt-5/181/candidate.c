int countRotation(int * array, int array_len, int count);

/*@ 
  requires array_len >= 0;
  requires count >= 0;
  requires count <= array_len;
  requires count == 0 || \valid_read(array + (0 .. count - 1));
  assigns \nothing;

  behavior empty:
    assumes count == 0;
    ensures \result == 0;

  behavior nonempty:
    assumes count > 0;
    ensures 1 <= \result <= count;

  ensures 0 <= \result <= count;

  complete behaviors;
  disjoint behaviors;
*/
int countRotation(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		/*@ assert count > 0; */

		int r = 0, top = count - 1;
		/*@
		  loop invariant 0 <= r <= top < count;
		  loop invariant \valid_read(array + (0 .. count - 1));
		  loop assigns r, top;
		  loop variant top - r;
		*/
		while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			/*@ assert r <= i <= top; */
			if (array[i] > array[r]) {
				r = i;
			} else {
				top = i;
			}
		}
		return r + 1;
}
