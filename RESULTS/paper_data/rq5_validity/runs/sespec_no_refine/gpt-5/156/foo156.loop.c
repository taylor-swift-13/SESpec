
#include <stdlib.h>

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

/*@
  requires Array >= 0;
  requires args_len >= Array;
  requires \valid_read(args + (0 .. args_len-1));
  ensures \result == \result; // dummy to keep a complete contract context
*/



int foo156(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
        int mpis_len = Array;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant 0 <= array <= Array;
          loop invariant mpis_len == Array;
          loop invariant \valid(mpis + (0 .. mpis_len-1));
          loop invariant \valid_read(args + (0 .. args_len-1));
          loop invariant args_len >= Array;
          loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns array, mpis[0 .. Array-1];
        */
        for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant mpis_len == Array;
          loop invariant \valid(mpis + (0 .. mpis_len-1));
          loop invariant \valid_read(args + (0 .. args_len-1));
          loop invariant args_len >= Array;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] >= args[k];
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns i, p, mpis[0 .. Array-1];
            */
            for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= p <= i;
          loop invariant 1 <= i <==> i >= 1;
          loop invariant \valid(mpis + (0 .. mpis_len-1));
          loop invariant \valid_read(args + (0 .. args_len-1));
          loop invariant args_len >= Array;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] >= args[k];
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns p, mpis[0 .. Array-1];
            */
            for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
            
		}
            
		int num = mpis[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \valid_read(mpis + (0 .. mpis_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] <= num;
          loop assigns i, num;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
            
		return num;
}
