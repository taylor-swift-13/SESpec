
/*@
  // No extra logic functions are required for this loop.
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
          loop invariant \valid_read(args + (0..args_len-1));
          loop invariant \valid(mpis + (0..mpis_len-1));
          loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
          loop invariant \forall integer k; array <= k < mpis_len ==> mpis[k] == \at(mpis[k], Pre);
          loop assigns array, mpis[..];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \valid_read(args + (0..args_len-1));
          loop invariant \valid(mpis + (0..mpis_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] >= args[k];
          loop invariant \forall integer k; i <= k < mpis_len ==> mpis[k] == \at(mpis[k], Pre);
          loop assigns i, p, mpis[..];
            */
            for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= p <= i;
          loop invariant \forall integer k; 0 <= k < p ==> (args[i] > args[k] && mpis[i] < mpis[k]*args[i]) ==> \false;
          loop invariant \forall integer k; 0 <= k < p ==> mpis[i] >= mpis[k]*args[i] || args[i] <= args[k];
          loop assigns p, mpis[..];
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
          loop invariant \valid(mpis + (0..mpis_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] <= result;
          loop invariant \forall integer k; i <= k < mpis_len ==> mpis[k] == \at(mpis[k], Pre);
          loop assigns i, result;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
            
		return result;
}
