/*@
    requires \valid(array + (0..array_len-1));
    requires array_len > 0;
    requires 0 <= y <= array_len;
    ensures \result == -1 || (0 <= \result < array_len && array[\result] == x);
    ensures \result == -1 ==> \forall integer i; 0 <= i < y ==> array[i] != x;
    ensures \result != -1 ==> \forall integer i; \result < i < y ==> array[i] != x;
    assigns \nothing;
*/
int last(int * array, int array_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@
		    loop invariant 0 <= i <= y;
		    loop invariant -1 <= r < y;
		    loop invariant -1 <= k < y;
		    loop invariant \forall integer j; 0 <= j < i ==> (k == -1 || j <= k || array[j] != x);
		    loop invariant \forall integer j; k != -1 ==> (k < j <= r ==> array[j] != x);
		    loop assigns i, r, k;
		    loop variant r - i + 1;
		*/
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (array[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (array[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
}
