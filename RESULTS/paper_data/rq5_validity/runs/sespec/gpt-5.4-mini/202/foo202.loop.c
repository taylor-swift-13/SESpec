
int foo202(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		
            
        /*@
          loop invariant 0 <= min;
          loop invariant 1 <= offset;
          loop invariant 0 <= find;
          loop invariant find <= min;
          loop invariant find <= offset;
          loop invariant min <= offset;
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < array ==> ints[k] == \at(ints[k], Pre);
          loop invariant \forall integer k; 0 <= k < min ==> k < offset;
          loop invariant \forall integer k; 0 <= k < min ==> 0 <= k < array;
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= find <= min && 0 <= find <= offset);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (min <= offset && 0 <= min && 1 <= offset);
          loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((offset == 1)&&(min == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < array ==> ints[k] == \at(ints[k], Pre);
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
