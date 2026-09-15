```c
/*@ 
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION(integer i, int* args, int* mpis) = \true;
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/



int foo154(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= array <= Array;
          loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
          loop assigns array, mpis[0..Array-1];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] == args[k];
          loop assigns i, p, mpis[0..Array-1];
            */
            for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] == args[k];
          loop assigns p, mpis[i];
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
          loop invariant 1 <= i <= Array;
          loop invariant \forall integer k; 0 <= k < i ==> result >= mpis[k];
          loop invariant \forall integer k; 0 <= k < Array ==> mpis[k] == \at(mpis[k], Pre);
          loop assigns i, result;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
            
		return result;
}`