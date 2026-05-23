int frequencyOfSmallest(int size, int * a, int a_len);

/*@
    requires a_len >= 0;
    requires 0 <= size <= a_len;
    requires size == 0 || \valid(a + (0 .. size-1));
    assigns \nothing;
    ensures size == 0 ==> \result == 0;
    ensures size > 0 ==>
        (\exists integer m; 0 <= m < size &&
            (\forall integer j; 0 <= j < size ==> a[m] <= a[j]) &&
            \result == \sum integer j; 0 <= j < size; (a[j] == a[m]) ? 1 : 0);
*/
int frequencyOfSmallest(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		/*@
		    loop invariant 1 <= c <= size;
		    loop invariant (\forall integer j; 0 <= j < c ==> f <= a[j]);
		    loop invariant (\exists integer j; 0 <= j < c && f == a[j]);
		    loop invariant total == \sum integer j; 0 <= j < c; (a[j] == f) ? 1 : 0;
		    loop assigns c, f, total;
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
