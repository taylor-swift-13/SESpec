/*@
    requires size >= 0;
    requires \valid(a + (0 .. size-1));
    requires a_len >= size;
    ensures \result >= 0;
    ensures size == 0 ==> \result == 0;
    ensures size > 0 ==> \exists integer f; 
        f == \min(integer i; 0 <= i < size; a[i]) &&
        \result == \sum(integer i; 0 <= i < size && a[i] == f; 1);
*/
int frequencyOfSmallest(int size, int * a, int a_len);

int frequencyOfSmallest(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		/*@
		    loop invariant 1 <= c <= size;
		    loop invariant \exists integer f; 
		        f == \min(integer i; 0 <= i < c; a[i]) &&
		        total == \sum(integer i; 0 <= i < c && a[i] == f; 1);
		    loop invariant f == \min(integer i; 0 <= i < c; a[i]);
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
