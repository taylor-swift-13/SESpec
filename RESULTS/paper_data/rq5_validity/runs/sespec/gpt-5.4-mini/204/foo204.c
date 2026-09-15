
/*@
  predicate ints_unchanged{L1,L2}(int* ints, integer n) =
    \forall integer k; 0 <= k < n ==> \at(ints[k], L1) == \at(ints[k], L2);
*/

 /*@
  requires array >= 1;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result < array;
  ensures array == 1 ==> \result == 0;
  ensures array > 1 ==> \result <= array - 1;
*/
int foo204(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /*@
          loop invariant 0 <= find <= offset;
          loop invariant 0 <= find <= max;
          loop invariant offset <= array;
          loop invariant 1 <= max <= array;
          loop invariant offset + max - 2 * find >= 1;
          loop invariant find <= offset && find <= max;
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find <= offset && find <= max && offset <= array && max <= array);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find >= 0);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (offset >= 0 && max >= 0);
          loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre);
          loop assigns offset, max, find;
            */
            while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}
            

		return find;
}
