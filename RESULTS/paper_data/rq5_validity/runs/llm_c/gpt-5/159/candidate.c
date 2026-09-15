/*@ 
  requires args_len >= 0;
  requires 0 <= array <= args_len;
  requires \valid(args + (0 .. args_len-1));

  assigns args[0 .. array-1];

  ensures 1 <= \result <= array + 1;

  ensures \forall integer k; 1 <= k < \result ==> 
            (\exists integer i; 0 <= i < array && \at(args[i],Pre) == k);

  ensures \forall integer i; 0 <= i < array ==> \at(args[i],Pre) != \result;

  ensures \forall integer i; array <= i < args_len ==> args[i] == \at(args[i],Pre);
*/
int firstMissingPositive(int * args, int args_len, int array);

int firstMissingPositive(int * args, int args_len, int array) {

		int ret = 0;
		/*@
		  loop invariant 0 <= ret <= array;
		  loop invariant \valid(args + (0 .. args_len-1));
		  loop assigns ret, args[0 .. array-1];
		*/
		while (ret < array) {
			if (args[ret] <= 0 || args[ret] > array
					|| args[ret] == ret + 1) {
				ret++;
			} else {
				int j = args[ret];
				//@ assert 1 <= j <= array;
				//@ assert 0 <= j-1 < array;
				args[ret] = args[j - 1];
				args[j - 1] = j;
			}
		}
		/*@
		  loop invariant 0 <= ret <= array;
		  loop invariant \forall integer i; 0 <= i < ret ==> args[i] == i+1;
		  loop assigns ret;
		  loop variant array - ret;
		*/
		for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
}
