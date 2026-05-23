
        /*@
        */

/*@
  requires 0 <= array <= args_len;
  requires array <= 1 || \valid_read(args + (0 .. array - 1));
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 && (\forall integer i; 0 <= i < array ==> args[i] == i + 1) ==> \result == array;
  ensures array > 1 && 1 <= \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && 1 <= \result < array ==> (\forall integer i; 0 <= i < \result - 1 ==> args[i] == i + 1);
*/
int foo224(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= num <= array + 1;
          loop invariant found == num || found == num - 1;
          loop invariant \forall integer i; 0 <= i < num - 1 ==> args[i] == i + 1;
          loop assigns num, found;
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
