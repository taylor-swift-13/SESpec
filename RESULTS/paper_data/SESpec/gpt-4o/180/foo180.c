
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer count_less_than(int* array, integer begin, integer end, integer value) =
    end <= begin ? 0 : count_less_than(array, begin, end - 1, value) + (array[end - 1] < value ? 1 : 0);
*/

/*@
  logic integer count_greater_than(int* array, integer begin, integer end, integer value) =
    end <= begin ? 0 : count_greater_than(array, begin, end - 1, value) + (array[end - 1] > value ? 1 : 0);
*/

/*@
  logic integer count_equal(int* array, integer begin, integer end, integer value) =
    end <= begin ? 0 : count_equal(array, begin, end - 1, value) + (array[end - 1] == value ? 1 : 0);
*/

/*@
  logic integer sorted_prefix(int* array, integer begin, integer end) =
    begin >= end - 1 ? 1 : (array[begin] <= array[begin + 1] ? sorted_prefix(array, begin + 1, end) : 0);
*/

/*@
  predicate unchanged_array{L1, L2}(int* array, integer begin, integer end) =
    \forall integer k; begin <= k < end ==> \at(array[k], L1) == \at(array[k], L2);
*/

/*@
  requires \valid(rot + (0 .. rot_len - 1));
  requires count > 0 && rot_len > 0 && rot_len < 100;
  ensures \result >= 1 && \result <= count;
  ensures unchanged_array{Pre,Post}(rot, 0, rot_len);
  ensures \forall integer k; 0 <= k < rot_len ==> rot[k] == \at(rot[k], Pre);
  assigns \nothing;
*/
int foo180(int * rot, int rot_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;

        /*@
          loop invariant 0 <= r <= top <= count - 1;
          loop invariant \forall integer k; 0 <= k < rot_len ==> rot[k] == \at(rot[k], Pre);
          loop invariant unchanged_array{Pre,Here}(rot, 0, rot_len);
          loop invariant count == \at(count, Pre);
          loop invariant rot_len == \at(rot_len, Pre);
          loop invariant rot == \at(rot, Pre);
          loop assigns r, top;
        */
        while (r < top) {
			if (rot[r] < rot[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (rot[i] > rot[r]) {
				r = i;
			} else {
				top = i;
			}
		}

		return r + 1;
}
