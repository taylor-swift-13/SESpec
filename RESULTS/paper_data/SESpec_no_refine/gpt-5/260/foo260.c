

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;   
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]); 
  ensures \result == (\result == -1 ? -1 : \result);  
*/
int foo260(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == array;
          loop invariant args_len == args_len;
          loop invariant args == args;
          loop invariant stop <= array - 1;
          loop assigns ret, stop;
            */
            while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
            
		return -1;
}
