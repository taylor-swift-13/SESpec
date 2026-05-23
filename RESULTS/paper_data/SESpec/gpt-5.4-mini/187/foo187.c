
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires size > 0;
  requires size <= array_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size != 0 ==> \result >= 1;
*/
int foo187(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c;
          loop invariant 1 <= max <= c;
          loop invariant \forall integer i; 0 <= i < c ==> f <= array[i];
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant array[0] == \at(array[0],Pre);
          loop assigns c, f, max;
            */
            for (int c = 1; c < size; c++) {
			if (f > array[c]) {
				f = array[c];
				max = 1;
			} else if (f == array[c]) {
				max++;
			}
		}
            
		return max;
}
