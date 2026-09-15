
int foo202(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          // Basic establishment: initial values satisfy these
          loop invariant 0 <= min;
          loop invariant 1 <= offset;
          loop invariant 0 <= find;
          // Monotonicity and relative order preserved by all branches
          loop invariant min <= offset;
          // Array contents are not modified by the loop body
          loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre);
          // Functional progression: find increases only on equality branch where both indices advance
          loop invariant find <= min;
          loop invariant find <= offset;
          // Exit implication: when loop condition is false, at least one index reached array
          loop invariant !(min < array && offset < array) ==> (min >= array || offset >= array);

          // Guarded bounds using the pre-state value of array when it is positive enough
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= min && 1 <= offset);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= find);
          loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((offset == 1)&&(min == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
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
