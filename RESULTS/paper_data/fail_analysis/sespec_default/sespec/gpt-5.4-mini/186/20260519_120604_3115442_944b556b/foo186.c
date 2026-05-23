
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
  requires size > 0 ==> size <= a_len;
  requires size > 0 ==> a_len >= size;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
*/
int foo186(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (c < \at(size,Pre)) ==> (f <= a[0]);
          loop invariant (c < \at(size,Pre)) ==> (((total == 1)&&(f == a[0])&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(size == \at(size,Pre))) || (f <= \at(a[0],Pre)));
          loop invariant (c < \at(size,Pre)) ==> (((total == 1)&&(f == a[0])&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(size == \at(size,Pre))) || (total >= 1));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
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
