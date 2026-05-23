int findFixedPoint(int * args, int args_len, int array);

/*@ 
  requires array >= 0;
  requires args != \null;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array - 1 ==> args[k+1] >= args[k] + 1;
  assigns \nothing;
  ensures -1 <= \result < array;
  ensures (\exists integer i; 0 <= i < array && args[i] == i) ==> (0 <= \result < array && args[\result] == \result);
  ensures !(\exists integer i; 0 <= i < array && args[i] == i) ==> \result == -1;
*/
int findFixedPoint(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@
		  loop invariant 0 <= ret <= array;
		  loop invariant -1 <= stop <= array - 1;
		  loop invariant ret <= stop + 1;
		  loop invariant \forall integer j; 0 <= j < ret ==> args[j] < j;
		  loop invariant \forall integer j; stop < j < array ==> args[j] > j;
		  loop assigns ret, stop;
		  loop variant stop - ret + 1;
		*/
		while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return -1;
}
