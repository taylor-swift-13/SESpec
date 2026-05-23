
#include <stdlib.h>

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/



int foo5_c154(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= array;
          loop assigns array, mpis[0..mpis_len-1];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop assigns i, mpis[0..mpis_len-1];
            */
            for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= p <= i;
          loop invariant 1 <= i;
          loop assigns p, mpis[0..mpis_len-1];
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
          loop invariant 1 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] <= result;
          loop assigns i, result;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
            
		return result;
}
