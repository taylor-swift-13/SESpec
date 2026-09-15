
/*@
logic integer count_occ{L}(int *a, integer n, integer v) = \numof(integer i; 0 <= i < n && a[i] == v);
*/

/*@ logic integer count_occ{L}(int *a, integer n, integer v) = \numof(integer i; 0 <= i < n && a[i] == v);
*/

/*@
  requires 0 <= size <= a_len;
  requires size == 0 || \valid_read(a + (0 .. size-1));
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > 0 ==> \result >= 1;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 ==> \forall integer i; 0 <= i < size ==> a[i] >= min_val(a, size);
  ensures size > 0 ==> \exists integer i; 0 <= i < size && a[i] == min_val(a, size);
  ensures size > 0 ==> \result == count_occ(a, size, min_val(a, size));
  ensures \result == \null ==> \false;
*/
int foo186(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= size;
          loop invariant \forall integer i; 0 <= i < c ==> a[i] >= f;
          loop invariant \exists integer k; 0 <= k < c && a[k] == f;
          loop invariant total == count_occ(a, c, f);
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
