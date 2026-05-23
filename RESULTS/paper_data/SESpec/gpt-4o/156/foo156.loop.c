
/*@
  logic integer array_copy(int* src, int* dest, integer len) =
    len <= 0 ? 1 : ((dest[len - 1] == src[len - 1] ? 1 : 0) * array_copy(src, dest, len - 1));
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires Array >= 0;
  ensures \forall integer k; 0 <= k < Array ==> mpis[k] == args[k];
*/
int foo156(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;

    /*@
      loop invariant 0 <= array <= Array;
      loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
      loop invariant \forall integer k; array <= k < Array ==> mpis[k] == 0;
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /*@
      loop invariant 1 <= i <= Array;
      loop invariant \forall integer k; 0 <= k < i ==> 
                       \forall integer j; 0 <= j < k ==> 
                         (args[k] > args[j] && mpis[k] < mpis[j] * args[k] ? 
                          mpis[k] == mpis[j] * args[k] : 
                          mpis[k] == args[k]);
      loop assigns i, p, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        /*@
          loop invariant 0 <= p <= i;
          loop invariant \forall integer k; 0 <= k < i ==> 
                           \forall integer j; 0 <= j < p ==> 
                             (args[k] > args[j] && mpis[k] < mpis[j] * args[k] ? 
                              mpis[k] == mpis[j] * args[k] : 
                              mpis[k] == args[k]);
          loop assigns p, mpis[0..Array-1];
        */
        for (int p = 0; p < i; p++) {
            /*@
              loop invariant 0 <= p <= i;
              loop invariant \forall integer k; 0 <= k < i ==> 
                               \forall integer j; 0 <= j < p ==> 
                                 (args[k] > args[j] && mpis[k] < mpis[j] * args[k] ? 
                                  mpis[k] == mpis[j] * args[k] : 
                                  mpis[k] == args[k]);
              loop assigns mpis[0..Array-1];
            */
            if (args[i] > args[p] && mpis[i] < (mpis[p] * args[i])) {
                mpis[i] = mpis[p] * args[i];
            }
        }
    }

    int num = mpis[0];

    /*@
      loop invariant 1 <= i <= Array;
      loop invariant \forall integer k; 0 <= k < i ==> num >= mpis[k];
      loop invariant \forall integer k; 0 <= k < Array ==> mpis[k] == \at(mpis[k], Pre);
      loop assigns i, num;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }

    return num;
}
