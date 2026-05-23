

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;   
  ensures \true; 
  ensures \result == \result;  
*/
int foo250(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant start == \at(start,Pre);
          loop invariant stop == \at(stop,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop assigns mid, result, total;
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
