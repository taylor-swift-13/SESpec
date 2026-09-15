int findMissing(int * args, int args_len, int array);

/*@
  requires args_len >= 0;
  requires array >= 0;
  requires array <= args_len;
  requires array == 0 || (args != \null && \valid_read(args + (0 .. array-1)));
  assigns \nothing;
  ensures array == 0 ==> \result == 1;
  ensures array >= 1 ==> 
    (
      (exists integer j; 1 <= j <= array && args[j-1] != j 
        && (forall integer k; 1 <= k < j ==> args[k-1] == k) && \result == j)
      ||
      ((forall integer k; 1 <= k <= array ==> args[k-1] == k) && \result == array)
    );
  terminates \true;
*/
int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
		  loop invariant 1 <= num <= array + 1;
		  loop invariant \forall integer k; 1 <= k < num ==> args[k-1] == k;
		  loop invariant (num <= 1 && found == 1) || (num > 1 && found == num - 1);
		  loop assigns found, num;
		  loop variant array - num + 1;
		*/
		for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
		return found;
}
