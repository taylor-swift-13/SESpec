
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
  requires args != \null;
  requires Array > 0;
  requires args_len >= Array;
  requires \valid(args + (0 .. args_len-1));
  requires \forall integer j; 0 <= j < args_len ==> 0 <= args[j] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer j; 0 <= j < Array ==> \result >= args[j];
*/
int foo155(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;
        
    /*@
      loop invariant 0 <= array <= Array;
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }
            
    /*@
      loop invariant 1 <= i <= Array;
      loop invariant \forall integer t; 0 <= t < i ==> mpis[t] == args[t] || mpis[t] >= args[t];
      loop invariant \forall integer j; 0 <= j < args_len ==> 0 <= args[j] <= 100;
      loop assigns i, k, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        
        /*@
          loop invariant 0 <= k <= i;
          loop invariant \forall integer j; 0 <= j < k ==> mpis[j] == args[j] || mpis[j] >= args[j];
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
    
    /*@
      loop invariant 1 <= i <= Array;
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
