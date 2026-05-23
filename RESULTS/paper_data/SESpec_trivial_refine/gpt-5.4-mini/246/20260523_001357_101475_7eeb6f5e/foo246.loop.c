
/*@ 
    requires 0 <= num;
    requires \valid_read(args + (0 .. num-1));
*/
        
int foo246(int * args, int args_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant 0 <= index <= num;
          loop assigns ret, index;
            */
            for (int index = 0; index < num; index++) {
			
            /*@
              loop invariant 0 <= index <= num;
              loop invariant 0 <= ret;
              loop assigns ret, index;
            */
        
            /*@
          loop invariant 0 <= index + 1 <= k <= num;
          loop invariant 0 <= ret;
          loop assigns ret, k;
            */
            for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
