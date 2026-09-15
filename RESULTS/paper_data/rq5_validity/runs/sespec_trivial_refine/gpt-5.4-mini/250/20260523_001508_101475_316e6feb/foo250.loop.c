
/*@
  requires 0 <= start <= stop < args_len;
*/
        
int foo250(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant start <= result;
          loop invariant 0 <= result;
          loop invariant -1 <= total < args_len;
          loop invariant result <= total + 1;
          loop assigns result, total, mid, i;
            */
            while (result <= total) {
			mid = (result + total) / 2;
			int i = args[mid];

			if (i == mid) {
				result = mid + 1;
			} else if (i < mid) {
				result = mid + 1;
			} else {
				total = mid - 1;
			}
		}
            
		return result;
}
