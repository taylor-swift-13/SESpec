
/*@
  logic integer odd_count(int* ints, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(ints, lo, hi - 1) + (ints[hi - 1] % 2 != 0 ? 1 : 0);

  logic integer odd_count_mod2(int* ints, integer lo, integer hi) =
    odd_count(ints, lo, hi) % 2;
*/

/*@
  requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires ints_len > 0;
  requires ints_len < 100;
  assigns ret, start, index;
  ensures \result == (\exists integer i; 0 <= i < array && i < ints_len && ints[i] % 2 != 0 && odd_count_mod2(ints, 0, i + 1) != 0; ints[i]) ? \result : 0;
*/
int foo142(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre);
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
