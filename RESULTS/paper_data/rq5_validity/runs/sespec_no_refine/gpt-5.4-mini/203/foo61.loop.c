
/*@
  logic integer cnt_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : cnt_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  assigns \nothing;
*/
int foo61(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= find <= offset <= \at(Array,Pre));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= max <= \at(Array,Pre));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (find <= offset && find <= max);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (array_len == \at(array_len,Pre) && array == \at(array,Pre) && Array == \at(Array,Pre));
          loop invariant (!(0 < \at(Array,Pre) && 1 < \at(Array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
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
