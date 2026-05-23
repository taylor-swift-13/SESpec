
/*@
        predicate valid_array{L}(int *a, integer n) = \valid_read(a + (0 .. n-1));
        */

/*@
  requires 0 < Array;
  requires 0 <= Array <= args_len;
  requires valid_array(args, Array);
*/



int foo156(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= array <= Array;
          loop assigns array, mpis[0 .. Array-1];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 1 <= i <= Array;
          loop assigns i, mpis[i];
            */
            for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= p <= i;
          loop assigns p, mpis[i];
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
          loop invariant \forall integer k; 0 <= k < i ==> num >= mpis[k];
          loop assigns i, num;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
            
		return num;
}
