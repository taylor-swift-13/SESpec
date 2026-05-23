
/*@
  // Logic to simulate one loop step given the current (min, offset)
  // and the array contents; returns the next (min, offset, find_inc)
  // where find_inc is 1 if a match was taken, 0 otherwise.
  logic integer next_min(int* a, integer m, integer o) =
    (a[m] == a[o]) ? m + 1 :
    (a[m] >  a[o]) ? m + 1 :
                     m;

  logic integer next_off(int* a, integer m, integer o) =
    (a[m] == a[o]) ? o + 1 :
    (a[m] >  a[o]) ? o     :
                     o + 1;

  logic integer next_inc(int* a, integer m, integer o) =
    (a[m] == a[o]) ? 1 : 0;

  // Simulate k steps starting from (m0,o0), counting matches.
  logic integer eq_pairs(int* a, integer limit, integer m0, integer o0, integer k) =
    (k <= 0 || m0 >= limit || o0 >= limit) ? 0
      : next_inc(a, m0, o0) +
        eq_pairs(a, limit,
                 next_min(a, m0, o0),
                 next_off(a, m0, o0),
                 k - 1);
*/

/*@
  requires \at(ints_len,Pre) > 0 && \at(ints_len,Pre) < 100;
*/
int foo60_c202(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		/*@
          loop invariant (min == 0 && offset == 1 && find == 0) ||
                          (min + offset + find >= 1);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= find <= (min + offset - 1));
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= min <= \at(array,Pre));
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (1 <= offset <= \at(array,Pre));
          loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((offset == 1)&&(min == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop assigns min, offset, find;
        */
        while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
}
