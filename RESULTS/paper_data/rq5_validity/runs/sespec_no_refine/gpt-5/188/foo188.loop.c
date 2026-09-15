
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  predicate is_min_prefix(int* a, integer hi, integer v) =
    \forall integer k; 0 <= k < hi ==> v <= a[k];
*/
        
int foo188(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant a_len == a_len;
          loop invariant a == a;
          loop invariant size == size;
          loop assigns c, f, max;
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
