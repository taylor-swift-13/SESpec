#include <limits.h>

int findFirstMissing(int * args, int args_len, int start, int stop);

/*@ 
  requires args != \null;
  requires 0 <= args_len;
  requires 0 <= start <= stop < args_len;
  requires \valid(args + (start..stop));
  requires \forall integer i; start <= i < stop ==> args[i] < args[i+1];
  assigns \nothing;
  ensures start <= \result <= stop + 1;
  ensures \forall integer i; start <= i < \result ==> args[i] <= i;
  ensures (\result <= stop ==> args[\result] > \result);
  ensures (\result == stop + 1 ==> (\forall integer i; start <= i <= stop ==> args[i] <= i));
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		/*@
		  loop invariant start <= found <= (total + 1);
		  loop invariant (start - 1) <= total <= stop;
		  loop invariant found <= (total + 1);
		  loop invariant \forall integer i; start <= i < found ==> args[i] <= i;
		  loop invariant \forall integer i; total < i <= stop ==> args[i] > i;
		  loop assigns found, total, mid;
		  loop variant (total - found + 1);
		*/
		while (found <= total) {
			mid = (found + total) / 2;
			/*@ assert start <= mid <= stop; */
			/*@ assert \valid(args + mid); */
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return found;
}
