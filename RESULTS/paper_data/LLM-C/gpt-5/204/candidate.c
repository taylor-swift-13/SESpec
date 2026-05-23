#include <limits.h>

int findMinSwaps(int * ints, int ints_len, int array);

/*@ 
  requires ints_len >= 0;
  requires 0 <= array <= ints_len;
  requires \valid_read(ints + (0 .. array-1));
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= (array >= 1 ? array - 1 : 0);
  ensures (array <= 1) ==> (\result == 0);
  ensures \forall integer i; 0 <= i < array ==> ints[i] == \at(ints[i], Pre);
*/
int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
		  loop invariant 0 <= offset <= array;
		  loop invariant 1 <= max;
		  loop invariant 0 <= find <= offset;
		  loop invariant find <= max - 1;
		  loop assigns offset, max, find;
		  loop variant (array - offset) + (array - max);
		*/
		while (offset < array && max < array) {
			/*@ assert 0 <= offset < array; */
			/*@ assert 0 <= max < array; */
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
