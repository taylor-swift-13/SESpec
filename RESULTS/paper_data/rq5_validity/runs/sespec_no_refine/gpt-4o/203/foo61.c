
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer max_value(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : \max(a[hi - 1], max_value(a, lo, hi - 1));
*/

/*@
  logic integer min_value(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : \min(a[hi - 1], min_value(a, lo, hi - 1));
*/

/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns offset, max, find;
  ensures \result == count_eq(array, 0, Array, \at(array[\at(offset, Pre)], Pre));
  ensures offset <= Array;
  ensures max <= Array;
  ensures \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
*/
int foo61(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
          loop invariant 0 <= find <= offset;
          loop invariant (!(0 < \at(Array,Pre) && 1 < \at(Array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
          loop assigns offset, max, find;
          loop variant Array - offset;
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
