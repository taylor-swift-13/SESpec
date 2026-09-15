
/*@
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo203(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /*@
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (offset <= Array && max <= Array);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (0 <= find);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (offset >= 0 && max >= 1);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (find == offset - 0 || find <= offset);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (Array == \at(Array,Pre));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (array_len == \at(array_len,Pre));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (array == \at(array,Pre));
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
