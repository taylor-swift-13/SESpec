
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/



int foo155(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= array <= Array;
          loop invariant \valid(mpis + (0..mpis_len-1));
          loop invariant \valid_read(args + (0..args_len-1));
          loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns array, mpis[..];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \valid(mpis + (0..mpis_len-1));
          loop invariant \valid_read(args + (0..args_len-1));
          loop invariant \forall integer idx; 0 <= idx < args_len ==> args[idx] == \at(args[idx], Pre);
          loop assigns i, k, mpis[..];
            */
            for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= k <= i;
          loop invariant \valid(mpis + (0..mpis_len-1));
          loop invariant \valid_read(args + (0..args_len-1));
          loop invariant \forall integer t; 0 <= t < k ==> 
                          (args[i] > args[t] && mpis[i] < \at(mpis[t], Pre) * args[i]) ==> mpis[i] >= \at(mpis[t], Pre) * args[i];
          loop invariant \forall integer u; k <= u < i ==> \true;
          loop invariant \forall integer idx; 0 <= idx < args_len ==> args[idx] == \at(args[idx], Pre);
          loop assigns k, mpis[..];
            */
            for (int k = 0; k < i; k++) {
				if (args[i] > args[k]
						&& mpis[i] < (mpis[k] * args[i])) {
					mpis[i] = mpis[k] * args[i];
				}
			}
            
		}
            
		int num = mpis[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \valid_read(mpis + (0..mpis_len-1));
          loop invariant \forall integer j; 0 <= j < i ==> num >= mpis[j];
          loop assigns i, num;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
            
		return num;
}
