int frequencyOfSmallest(int size, int * a, int a_len);

/*@ 
  requires a_len >= 0;
  requires 0 <= size <= a_len;
  requires size == 0 || \valid_read(a + (0 .. size-1));
  assigns \nothing;

  behavior empty:
    assumes size == 0;
    ensures \result == 0;

  behavior nonempty:
    assumes size > 0;
    ensures \exists integer j;
              0 <= j < size &&
              (\forall integer i; 0 <= i < size ==> a[j] <= a[i]) &&
              \result == \numof integer i; 0 <= i < size && a[i] == a[j];
    ensures 1 <= \result <= size;

  complete behaviors;
  disjoint behaviors;
*/
int frequencyOfSmallest(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		/*@
		  loop invariant 1 <= c <= size;
		  loop invariant (\forall integer i; 0 <= i < c ==> f <= a[i]);
		  loop invariant (\exists integer k; 0 <= k < c && a[k] == f);
		  loop invariant total == \numof integer i; 0 <= i < c && a[i] == f;
		  loop invariant 1 <= total <= c;
		  loop assigns f, total, c;
		  loop variant size - c;
		*/
		for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				total = 1;
			} else if (f == a[c]) {
				total++;
			}
		}
		return total;
}
