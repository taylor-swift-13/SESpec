
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
*/



int foo154(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= array;
          loop invariant Array < 0 || array <= Array;
          loop assigns array, mpis[0..Array-1];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array < 1 || i <= Array;
          loop invariant 0 <= p;
          loop assigns i, p, mpis[0..Array-1];
            */
            for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
            
		}
            
		int result = mpis[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array < 1 || i <= Array;
          loop invariant result >= mpis[0];
          loop invariant \forall integer k; 0 <= k < i ==> result >= mpis[k];
          loop invariant \exists integer k; 0 <= k < i && result == mpis[k];
          loop assigns i, result;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
            
		return result;
}
