/*@ 
  logic integer array_min{L}(int *a, integer n) =
    n <= 0 ? 0 :
    (n == 1 ? a[0] :
      (let m = array_min{L}(a, n-1) in (m <= a[n-1] ? m : a[n-1])));

  logic integer count_eq{L}(int *a, integer n, integer v) =
    n <= 0 ? 0 :
    count_eq{L}(a, n-1, v) + (a[n-1] == v ? 1 : 0);
*/

/*@ 
  requires a_len >= 0;
  requires 0 <= size <= a_len;
  requires size == 0 || \valid_read(a + (0 .. size-1));

  assigns \nothing;

  ensures size == 0 ==> \result == 0;

  ensures size > 0 ==> 1 <= \result <= size;
  ensures size > 0 ==> \result == count_eq{Pre}(a, size, array_min{Pre}(a, size));

  ensures size > 0 ==> (\exists integer j; 0 <= j < size &&
                         (\forall integer i; 0 <= i < size ==> a[j] <= a[i]));
*/
int frequencyOfSmallest(int size, int * a, int a_len);

int frequencyOfSmallest(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

		/*@
		  loop invariant 1 <= c <= size;
		  loop invariant f == array_min{Pre}(a, c);
		  loop invariant max == count_eq{Pre}(a, c, f);
		  loop invariant 1 <= max <= c;
		  loop assigns f, max, c;
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
