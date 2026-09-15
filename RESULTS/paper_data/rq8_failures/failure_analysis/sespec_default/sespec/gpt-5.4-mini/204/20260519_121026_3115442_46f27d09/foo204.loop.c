
        
        
int foo204(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= find && find <= offset && find <= max && offset <= array && max <= array);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= find) ;
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= offset && offset <= array) ;
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (1 <= max && max <= array) ;
          loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer i; 0 <= i < ints_len ==> ints[i] == \at(ints[i],Pre);
          loop assigns offset, max, find;
            */
            while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}
            

		return find;
}
