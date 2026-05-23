
        /*@
        */
        
int foo224(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS;
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
