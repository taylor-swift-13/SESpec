
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer min_value_prefix(int* a, integer n) =
    n <= 0 ? 0 : (n == 1 ? a[0] : (min_value_prefix(a, n - 1) <= a[n - 1] ? min_value_prefix(a, n - 1) : a[n - 1]));
*/
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > 0 ==> (\exists integer j; 0 <= j < size && a[j] == min_value_prefix(a, size)) &&
                      (\forall integer k; 0 <= k < size ==> min_value_prefix(a, size) <= a[k]) &&
                      \result == count_eq(a, 0, size, min_value_prefix(a, size));
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
