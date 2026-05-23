#include <stddef.h>

int findMissing(int * args, int args_len, int array);

/*@
  requires args_len >= 0;
  requires array <= 1 || (args_len >= array && \valid_read(args + (0..args_len-1)));

  assigns \nothing;

  ensures array <= 1 ==> \result == 1;
  ensures array >= 2 ==> 1 <= \result <= array;
  ensures array >= 2 ==> (\forall integer i; 1 <= i < \result ==> args[i-1] == i);
  ensures array >= 2 && \result < array ==> args[\result - 1] != \result;
  ensures array >= 2 && \result == array ==> (\forall integer i; 1 <= i <= array ==> args[i-1] == i);

  terminates \true;
*/
int findMissing(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		/*@
		  loop invariant 1 <= remaining <= array + 1;
		  loop invariant array <= 1 || (args_len >= array && \valid_read(args + (0..args_len-1)));
		  loop invariant remaining == 1 ==> find == 1;
		  loop invariant remaining > 1 ==> find == remaining - 1;
		  loop invariant \forall integer i; 1 <= i < remaining ==> args[i-1] == i;
		  loop assigns find, remaining;
		  loop variant array - remaining + 1;
		*/
		for (int remaining = 1; remaining <= array; remaining++) {
			/*@ assert 0 <= remaining - 1 < args_len; */
			if (args[remaining - 1] == remaining) {
				find = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return find;
}
