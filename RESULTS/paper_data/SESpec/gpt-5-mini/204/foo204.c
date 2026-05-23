
/*@
  logic integer min_integer(integer a, integer b) = a <= b ? a : b;
*/

/*@
  requires \valid(ints + (0 .. ints_len-1));
  requires ints_len >= 0;
  requires ints_len >= array;
  assigns \nothing;
  ensures \result >= 0;
  ensures (\at(array,Pre) <= 1) ==> (\result == 0);
  ensures (\at(array,Pre) > 1) ==> (\result <= min_integer(\at(array,Pre), \at(array,Pre)));
  ensures \result == \result;
*/
int foo204(int * ints, int ints_len, int array) {

	int find = 0;
	int offset = 0;
	int max = 1;

	/*@
	  loop invariant 0 <= offset;
	  loop invariant 0 <= max;
	  loop invariant 0 <= find;
	  loop invariant offset <= max;
	  loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (offset <= array);
	  loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (max <= array);
	  loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==>
	                 (\forall integer k; 0 <= k < min_integer(offset,max) ==>
	                      0 <= k < ints_len && 0 <= k + (max - offset) < ints_len);
	  loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find <= min_integer(offset,max));
	  loop invariant array == \at(array,Pre);
	  loop invariant ints_len == \at(ints_len,Pre);
	  loop invariant ints == \at(ints,Pre);
	  loop invariant (\forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre));
	  loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((max == 1) && (offset == 0) && (find == 0) && (array == \at(array,Pre)) && (ints_len == \at(ints_len,Pre)) && (ints == \at(ints,Pre)));
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
