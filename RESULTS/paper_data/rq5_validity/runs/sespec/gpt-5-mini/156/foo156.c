
/*@ 
  predicate prefix_copy(int* src, int* dst, integer len, integer total) =
    0 <= len <= total && (\forall integer k; 0 <= k < len ==> dst[k] == src[k]);
*/

#include <stdlib.h>

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;   
  ensures \result == max_mpis_range{Pre}(args, Array, Array-1); 
*/
int foo156(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 0 <= array <= Array;
      loop invariant prefix_copy(args, mpis, array, Array);
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }
            
    /* After the copy loop, mpis[0..Array-1] are initialized and non-negative. */
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 1 <= i <= Array;
      loop invariant prefix_copy(args, mpis, Array, Array);
      loop invariant \forall integer k; 0 <= k < Array ==> 0 <= mpis[k];
      loop assigns i, p, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant 0 <= p <= i;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] == mpis[k];
          loop invariant \forall integer k; 0 <= k < Array ==> 0 <= mpis[k];
          loop assigns p, mpis[0..Array-1];
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
              loop invariant \forall integer k; 0 <= k < Array ==> mpis[k] >= 0;
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
