int getOddOccurrence(int * ints, int ints_len, int array);

/*@ predicate is_odd(integer x) = x % 2 != 0; */

/*@ logic integer odd_count_prefix(int *a, integer j) =
      \numof integer k; 0 <= k <= j && is_odd(a[k]); */

/*@ logic integer odd_count_range(int *a, integer n) =
      \numof integer k; 0 <= k < n && is_odd(a[k]); */

/*@ requires array >= 0;
    requires ints_len >= 0;
    requires array <= ints_len;
    requires array == 0 || \valid_read(ints + (0 .. array-1));
    assigns \nothing;
    ensures odd_count_range(ints, array) == 0 ==> \result == 0;
    ensures odd_count_range(ints, array) > 0 ==>
            (\exists integer j; 0 <= j < array &&
                odd_count_prefix(ints, j) % 2 == 1 &&
                (\forall integer t; j < t < array ==> !(odd_count_prefix(ints, t) % 2 == 1)) &&
                \result == ints[j]);
*/
int getOddOccurrence(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		/*@ 
		  loop invariant 0 <= index <= array;
		  loop invariant start == \numof integer k; 0 <= k < index && is_odd(ints[k]);
		  loop invariant start == 0 ==> ret == 0;
		  loop invariant start > 0 ==> 
		     (\exists integer j; 0 <= j < index &&
		         odd_count_prefix(ints, j) % 2 == 1 &&
		         (\forall integer t; j < t < index ==> !(odd_count_prefix(ints, t) % 2 == 1)) &&
		         ret == ints[j]);
		  loop assigns index, start, ret;
		  loop variant array - index;
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
