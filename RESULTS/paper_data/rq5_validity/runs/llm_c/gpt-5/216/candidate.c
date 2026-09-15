int last(int * array, int array_len, int x, int y);

/*@ 
  requires array_len >= 0;
  requires 0 <= y && y <= array_len;
  requires \valid_read(array + (0 .. y - 1));
  requires \forall integer i, j; 0 <= i && i <= j && j < y ==> array[i] <= array[j];
  assigns \nothing;
  ensures \result == -1 ==> (\forall integer j; 0 <= j && j < y ==> array[j] != x);
  ensures \result != -1 ==> (0 <= \result && \result < y && array[\result] == x
                             && (\forall integer j; \result < j && j < y ==> array[j] != x));
*/
int last(int * array, int array_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@
		  loop invariant 0 <= i && i <= y;
		  loop invariant -1 <= r && r < y;
		  loop invariant -1 <= k && k < y;
		  loop invariant (k == -1) || (array[k] == x);
		  loop invariant \forall integer j; (0 <= j && j < i) ==> (array[j] <= x);
		  loop invariant \forall integer j; (r + 1 <= j && j < y) ==> (array[j] > x);
		  loop invariant \forall integer j; (0 <= j && j < i && array[j] == x) ==> (j <= k);
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
