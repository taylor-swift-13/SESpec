
/*@
  logic integer invcnt_from(int* a, integer n, integer i) =
    i >= n ? 0 : invcnt_from(a, n, i + 1) + (a[i] > a[i+1] ? 1 : 0);

  logic integer invpairs(int* a, integer n, integer i) =
    i <= 0 ? 0
           : invpairs(a, n, i - 1)
             + ( \sum(integer j = i; j < n; j++) (a[i - 1] > a[j] ? 1 : 0) );
*/

/*@
  requires args_len >= 0;
  requires num >= 0;
  requires \valid(args + (0 .. args_len-1));
  requires num <= args_len;
  ensures \result >= 0;
*/
int foo248(int * args, int args_len, int num) {

    int ret = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant num == \at(num,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns index, c, ret;
            */
            for (int index = 0; index < num; index++) {
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant 0 <= index <= num;
          loop invariant ret >= 0;
          loop invariant \forall integer i,j; 0 <= i < index && i < j < num ==> 
                           (args[i] > args[j] ? 1 : 0) <= ret;
          loop assigns ret, index;
        */
        for (int c = index + 1; c < num; c++) {
            if (args[index] > args[c]) {
                ret++;
            }
        }
            
    }
            
    return ret;
}
