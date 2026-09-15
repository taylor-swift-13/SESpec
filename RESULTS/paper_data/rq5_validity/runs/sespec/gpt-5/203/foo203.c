
/*@
  logic integer count_equal_pairs(int* a, integer lo1, integer hi1, integer lo2, integer hi2) =
    (hi1 <= lo1 || hi2 <= lo2) ? 0
      : count_equal_pairs(a, lo1, hi1 - 1, lo2, hi2 - 1)
        + (a[hi1 - 1] == a[hi2 - 1] ? 1 : 0);
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures Array <= 1 ==> \result == 0;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
  ensures array == \at(array,Pre) && array_len == \at(array_len,Pre) && Array == \at(Array,Pre);
*/
int foo203(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

        /*@
          loop invariant find >= 0;
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (find <= offset);
          loop invariant (offset < Array && max < Array) ==> (offset >= 0 && max >= 0);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> ((offset < Array && max < Array) || (offset >= Array || max >= Array));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (max >= 1);
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (\forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre));
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
