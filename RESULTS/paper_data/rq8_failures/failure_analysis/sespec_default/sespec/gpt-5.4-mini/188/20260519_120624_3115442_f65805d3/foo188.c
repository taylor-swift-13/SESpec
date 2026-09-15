
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires size <= a_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > 0 ==> \result >= 1;
  ensures size > 0 ==> \exists integer k; 0 <= k < size && \result >= 1;
*/
int foo188(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer k; 0 <= k < c ==> f <= a[k];
          loop invariant \exists integer k; 0 <= k < c && f == a[k];
          loop invariant 1 <= max <= c;
          loop invariant max >= 1;
          loop invariant max <= c;
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
