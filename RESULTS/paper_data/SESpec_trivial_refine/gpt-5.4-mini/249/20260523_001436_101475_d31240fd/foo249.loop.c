
        /*@
        predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION;
        */
        
int foo249(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant \true;
          loop assigns found, num, mid, i;
            */
            while (found <= num) {
			mid = (found + num) / 2;
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				num = mid - 1;
			}
		}
            
		return found;
}
