
        /*@
        
        */
        
int foo220(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
            /*@
          loop invariant 0 <= i;
          loop invariant hi < n;
          loop invariant i <= hi + 1;
          loop invariant result == -1 || (0 <= result < n && args[result] == array);
          loop assigns i, hi, result;
            */
            while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
