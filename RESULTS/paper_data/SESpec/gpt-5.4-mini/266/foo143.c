
/*@
  logic integer odd_count(int *array, integer lo, integer hi) =
    lo >= hi ? 0 :
    odd_count(array, lo, hi - 1) + (array[hi - 1] % 2 != 0 ? 1 : 0);

  logic integer last_odd_value(int *array, integer lo, integer hi) =
    lo >= hi ? 0 :
    (array[hi - 1] % 2 != 0 ? array[hi - 1] : last_odd_value(array, lo, hi - 1));
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures \result == \result;
*/
int foo143(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index;
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant start == odd_count(array, 0, index);
          loop invariant start >= 0;
          loop invariant start <= index;
          loop invariant (start % 2 != 0) ==> ret == last_odd_value(array, 0, index);
          loop invariant \forall integer k; 0 <= k < \at(Array,Pre) ==> array[k] == \at(array[k],Pre);
          loop assigns index, ret, start;
            */
            for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
            
		return ret;
}
