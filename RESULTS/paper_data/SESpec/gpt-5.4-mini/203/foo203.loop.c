
int foo203(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /*@
          loop invariant 0 <= offset;
          loop invariant 1 <= max;
          loop invariant 0 <= find;
          loop invariant find <= offset;
          loop invariant find <= max;
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= find <= offset && 0 <= find <= max);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= offset <= \at(Array,Pre));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= max <= \at(Array,Pre));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= find <= \at(Array,Pre));
          loop invariant (!(0 < \at(Array,Pre) && 1 < \at(Array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop assigns offset, max, find;
            */
            while (offset < Array && max < Array) {
			if (array[offset] == array[max]) {
				offset++;
				max++;
				find++;
			} else if (array[offset] > array[max]) {
				offset++;
			} else {
				max++;
			}
		}
            

		return find;
}
