
/*@
  logic integer cnt_eq(int* a, integer off, integer mx, integer N) =
    off >= N || mx >= N ? 0
    : a[off] == a[mx] ? 1 + cnt_eq(a, off+1, mx+1, N)
    : a[off] > a[mx] ? cnt_eq(a, off+1, mx, N)
    : cnt_eq(a, off, mx+1, N);
*/

/*@
  requires \valid_read(array + (0..array_len-1));
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  requires Array == \at(Array,Pre);
  assigns \nothing;
  ensures \result == cnt_eq(array, 0, 1, Array);
*/
int foo61_c203(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (find + cnt_eq(array, offset, max, Array) == cnt_eq(array, 0, 1, Array));
          loop invariant (0 < \at(Array,Pre) && 1 < \at(Array,Pre)) ==> (1 <= max && 0 <= offset);
          loop invariant (!(0 < \at(Array,Pre) && 1 < \at(Array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre) ;
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
