

/*@
  requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires ints_len > 0;
  requires ints_len < 100;
  requires 0 <= array < ints_len;
  assigns \nothing;
*/
int foo204(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

            /*@
          loop invariant 0 <= offset <= array;
          loop invariant 1 <= max <= array + 1;
          loop invariant 0 <= find <= offset;
          loop invariant \at(array, Pre) == array;
          loop invariant \at(ints_len, Pre) == ints_len;
          loop invariant ints == \at(ints, Pre);
          loop invariant \forall integer i; 0 <= i < ints_len ==> ints[i] == \at(ints[i], Pre);
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
