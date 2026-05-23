/*@
    requires array_len >= 0;
    requires \valid_read(array + (0 .. array_len - 1));
    requires 0 <= y <= array_len;
    assigns \nothing;
    ensures -1 <= \result < y;
    ensures \result == -1 || array[\result] == x;
    ensures \result != -1 ==> (\forall integer j; \result < j < y ==> array[j] != x);
*/
int last(int * array, int array_len, int x, int y);

 /*@
    requires array_len >= 0;
    requires \valid_read(array + (0 .. array_len - 1));
    requires 0 <= y <= array_len;
    assigns \nothing;
    ensures -1 <= \result < y;
    ensures \result == -1 || array[\result] == x;
    ensures \result != -1 ==> (\forall integer j; \result < j < y ==> array[j] != x);
*/
int last(int * array, int array_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@
		    loop invariant 0 <= i <= y;
		    loop invariant -1 <= r < y;
		    loop invariant -1 <= k < y;
		    loop invariant k == -1 || array[k] == x;
		    loop invariant k == -1 || (\forall integer j; k < j < y ==> array[j] != x);
		    loop invariant (\forall integer j; 0 <= j < i ==> array[j] != x);
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
