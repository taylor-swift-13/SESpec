int getOddOccurrence(int * args, int args_len, int array);

/*@ 
  requires args_len >= 0;
  requires 0 <= array <= args_len;
  requires \valid_read(args + (0 .. args_len-1));
  assigns \nothing;
  ensures \let m = \numof integer i; 0 <= i < array && (args[i] % 2 != 0);
          (m == 0 ==> \result == 0) &&
          (m > 0 ==> \exists integer k; 0 <= k < array &&
                                   (args[k] % 2 != 0) &&
                                   (\numof integer i; 0 <= i <= k && (args[i] % 2 != 0)) == ((m % 2 != 0) ? m : m - 1) &&
                                   \result == args[k]);
*/
int getOddOccurrence(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		/*@
		  loop invariant 0 <= index <= array;
		  loop invariant 0 <= start <= index;
		  loop invariant start == \numof integer j; 0 <= j < index && (args[j] % 2 != 0);
		  loop invariant (start == 0 ==> ret == 0);
		  loop invariant (start > 0 ==> \exists integer k; 0 <= k < index &&
		                                   (args[k] % 2 != 0) &&
		                                   (\numof integer j; 0 <= j <= k && (args[j] % 2 != 0)) == ((start % 2 != 0) ? start : start - 1) &&
		                                   ret == args[k]);
		  loop assigns ret, start, index;
		  loop variant array - index;
		*/
		for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
		return ret;
}
