
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo202(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		
            
            /*@
          loop invariant 0 <= find;
          loop invariant 0 <= min;
          loop invariant 1 <= offset;
          loop invariant find <= min;
          loop invariant min <= offset;
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < \at(ints_len,Pre) ==> ints[k] == \at(ints[k],Pre);
          loop assigns min, offset, find;
            */
            while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}
            

		return find;
}
