
int foo83(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= num;
              loop invariant array >= 1 ==> num <= array + 1;
              loop invariant 1 <= found <= num;
              loop invariant \forall integer k; 1 <= k < num && args[k-1] == k ==> k <= found;
              loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
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
