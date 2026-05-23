int frequencyOfSmallest(int size, int * a, int a_len);

/*@
    requires size >= 0;
    requires a != \null;
    requires a_len >= size;
    requires \valid(a + (0..a_len-1));
    assigns \nothing;
    ensures size == 0 ==> \result == 0;
    ensures size > 0 ==>
        (\exists integer m;
            (\forall integer j; 0 <= j < size ==> a[j] >= m)
            && (\exists integer j; 0 <= j < size && a[j] == m)
            && \result == (\sum integer i; 0 <= i < size; (a[i] == m ? 1 : 0))
        );
    ensures 0 <= \result <= size;
*/
int frequencyOfSmallest(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

		/*@
		    loop invariant 1 <= c <= size;
		    loop invariant (\forall integer j; 0 <= j < c ==> a[j] >= f);
		    loop invariant (\exists integer j; 0 <= j < c && a[j] == f);
		    loop invariant max == (\sum integer i; 0 <= i < c; (a[i] == f ? 1 : 0));
		    loop assigns c, f, max;
		    loop variant size - c;
		*/
		for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				max = 1;
			} else if (f == a[c]) {
				max++;
			}
		}
		return max;
}
