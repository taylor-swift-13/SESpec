int countRotation(int * array, int array_len, int count);

/*@
    requires array_len >= 0;
    requires 0 <= count <= array_len;
    requires \valid_read(array + (0 .. array_len-1)) || array_len == 0;
    assigns \nothing;
    behavior empty:
        assumes count == 0;
        ensures \result == 0;
    behavior non_empty:
        assumes count > 0;
        ensures 1 <= \result <= count;
    complete behaviors empty, non_empty;
    disjoint behaviors empty, non_empty;
*/
int countRotation(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		/*@
		    loop invariant count > 0;
		    loop invariant 0 <= r <= top < count;
		    loop invariant \forall integer i; 0 <= i < r ==> \valid_read(&array[i]);
		    loop invariant \valid_read(&array[top]);
		    loop assigns r, top, end;
		    loop variant top - r;
		*/
		while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int end = (r + top) / 2;
			if (array[end] > array[r]) {
				r = end;
			} else {
				top = end;
			}
		}
		return r + 1;
}
