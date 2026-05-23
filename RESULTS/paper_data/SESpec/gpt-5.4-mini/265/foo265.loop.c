
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0);

  logic integer selected_odd(int* a, integer lo, integer hi, integer cnt) =
    lo >= hi ? 0 :
    (((a[lo] % 2) != 0) ?
      ((((cnt + 1) % 2) != 0) ? a[lo] : selected_odd(a, lo + 1, hi, cnt + 1)) :
      selected_odd(a, lo + 1, hi, cnt));

  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

int foo265(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /*@
          loop invariant 0 <= index;
          loop invariant (array < 0) || (index <= array);
          loop invariant 0 <= start <= index;
          loop invariant start == count_odd(ints, 0, index);
          loop invariant ret == 0 || ret % 2 != 0;
          loop invariant (start == 0) ==> (ret == 0);
          loop invariant (start > 0) ==> (ret == 0 || ret % 2 != 0);
          loop invariant \forall integer k; 0 <= k < index && (ints[k] % 2) != 0 ==> count_odd(ints, 0, k + 1) >= 1;
          loop invariant (index == array) ==> (start == count_odd(ints, 0, array));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant 0 <= ints_len ==> (\forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre));
          loop invariant (!(index < \at(array,Pre))) ==> (array == \at(array,Pre) && ints_len == \at(ints_len,Pre) && ints == \at(ints,Pre));
          loop assigns index, ret, start;
            */
            for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
            
		return ret;
}
