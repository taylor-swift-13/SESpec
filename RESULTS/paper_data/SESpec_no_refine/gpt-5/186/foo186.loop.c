
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo186(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

        /*@
          loop invariant 1 <= c <= size;
          loop invariant \forall integer k; 0 <= k < c ==> f <= a[k];
          loop invariant \exists integer k; 0 <= k < c && a[k] == f;
          loop invariant total == count_eq(a, 0, c, f);
          loop invariant a == a;
          loop invariant a_len == a_len;
          loop invariant size == size;
          loop assigns c, f, total;
        */
            /*@
          loop invariant 1 <= c <= size;
          loop invariant \forall integer k; 0 <= k < c ==> f <= a[k];
          loop invariant \exists integer k; 0 <= k < c && a[k] == f;
          loop invariant total == count_eq(a, 0, c, f);
          loop assigns c, f, total;
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
