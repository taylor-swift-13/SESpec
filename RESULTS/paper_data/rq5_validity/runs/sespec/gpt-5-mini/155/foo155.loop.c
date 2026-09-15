
/*@
  predicate PartiallyCopied(int *mpis, int *args, integer lo, integer hi) =
    \forall integer k; lo <= k < hi ==> mpis[k] == args[k];
*/
/*@
  predicate NonNegBoundedArgs(int *args, integer len) =
    \forall integer j; 0 <= j < len ==> 0 <= args[j] <= 100;
*/
/*@
  /* No additional logic required for the outer loop; preserve predicates above. */
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/

int foo155(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;
        
    /*@
      loop invariant 0 <= array;
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }
            
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \forall integer t; 0 <= t < i ==> mpis[t] == args[t];
          loop invariant \forall integer j; 0 <= j < args_len ==> 0 <= args[j] <= 100;
          loop assigns i, k, mpis[0..Array-1];
            */
            for (int i = 1; i < Array; i++) {
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= k <= i;
          loop invariant \forall integer j; 0 <= j < k ==> mpis[j] == args[j];
          loop invariant \forall integer j; 0 <= j < args_len ==> 0 <= args[j] <= 100;
          loop assigns k, mpis[0..Array-1];
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
          loop invariant \forall integer t; 0 <= t < Array ==> \true; 
          loop invariant \forall integer j; 0 <= j < args_len ==> 0 <= args[j] <= 100;
          loop assigns i, num;
            */
            for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }
            
    return num;
}
