
/*@ */
/*@ */

/*@
  requires args_len > 0;
  requires args_len < 100;
  requires 1 <= Array <= args_len;
  requires \valid(&args[0] + (0 .. args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= args[0];
*/
int foo7_c156(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;
        
    /*@
      loop invariant 0 <= array && array <= Array;
      loop invariant \valid(mpis + (0 .. mpis_len-1));
      loop invariant \valid_read(args + (0 .. args_len-1));
      loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
      loop invariant \forall integer k; 0 <= k < array ==> 0 <= k && k < mpis_len;
      loop invariant \forall integer k; 0 <= k && k < args_len ==> args[k] == \at(args[k], Pre);
      loop assigns array, mpis[..];
    */
    for (int array = 0; array < Array; array++) {
            mpis[array] = args[array];
        }
            
    /*@
      loop invariant 1 <= i && i <= Array;
      loop invariant \valid(mpis + (0 .. mpis_len-1));
      loop invariant \valid_read(args + (0 .. args_len-1));
      loop invariant \forall integer k; 0 <= k && k < Array ==> 0 <= k && k < mpis_len;
      loop invariant \forall integer k; 0 <= k && k < args_len ==> args[k] == \at(args[k], Pre);
      loop assigns i, mpis[..];
    */
    for (int i = 1; i < Array; i++) {
        
        /*@
          loop invariant 0 <= p && p <= i;
          loop invariant \valid(mpis + (0 .. mpis_len-1));
          loop invariant \valid_read(args + (0 .. args_len-1));
          loop invariant \forall integer k; 0 <= k && k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant \forall integer k; 0 <= k && k < Array ==> 0 <= k && k < mpis_len;
          loop invariant \forall integer q; 0 <= q < p ==>
                           ((args[i] > args[q] && mpis[i] < mpis[q] * args[i]) ==> mpis[i] >= mpis[q] * args[i]);
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
    
    /*@
      loop invariant 1 <= i && i <= Array;
      loop invariant \valid_read(mpis + (0 .. mpis_len-1));
      loop invariant \forall integer k; 0 <= k < i ==> num >= mpis[k];
      loop invariant \forall integer k; 0 <= k && k < Array ==> 0 <= k && k < mpis_len;
      loop assigns i, num;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }
            
    return num;
}
