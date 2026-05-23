
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/


int foo156(int *args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;

    /*@
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /*@
      loop assigns i, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        /*@
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
