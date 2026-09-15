
/*@
  logic integer cnt_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cnt_odd(a, lo, hi - 1) + ((a[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@ 
  assigns \nothing;
  ensures \result == \result;
*/
int foo266(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
            /*@
          loop invariant 0 <= start <= index;
          loop invariant start == cnt_odd(array, 0, index);
          loop invariant \forall integer k; 0 <= k < index ==> array[k] == \at(array[k], Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop invariant (index < \at(Array,Pre)) ==> (start == cnt_odd(array, 0, index));
          loop invariant (index == 0) ==> (start == 0 && ret == 0);
          loop invariant (index == Array) ==> (start == cnt_odd(array, 0, Array));
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre) ;
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
