/*@
    requires array_len >= 0;
    requires 0 <= y <= array_len;
    requires \valid(array + (0 .. array_len-1));
    requires \forall integer i; 0 <= i < array_len-1 ==> array[i] <= array[i+1];
    assigns \nothing;
    ensures \result >= -1 && \result < y;
    ensures (\result == -1) <==> (\forall integer j; 0 <= j < y ==> array[j] != x);
    ensures (\result != -1) ==> (0 <= \result < y && array[\result] == x &&
                                 (\forall integer j; \result < j < y ==> array[j] != x));
*/
int last(int * array, int array_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@
		    loop invariant 0 <= i <= y;
		    loop invariant -1 <= r < y;
		    loop invariant i <= r+1;
		    loop invariant k == -1 || (0 <= k <= r && array[k] == x && k < i);
		    loop invariant \forall integer j; 0 <= j < i ==> array[j] <= x;
		    loop invariant \forall integer j; r < j < y ==> array[j] > x;
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
