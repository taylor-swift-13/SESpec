

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo249(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant start == \at(start,Pre);
          loop invariant stop == \at(stop,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant found >= start;
          loop invariant num <= stop;
          loop assigns mid, found, num;
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
