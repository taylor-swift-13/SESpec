
        /*@
        predicate sorted{L}(int *a, integer n) =
          \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
        */
        
int foo255(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result;
          loop invariant top <= args_len - 1;
          loop assigns result, top;
            */
            while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return result;
}
