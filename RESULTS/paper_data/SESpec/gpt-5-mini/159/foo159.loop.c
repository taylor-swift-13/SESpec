
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires array >= 0;
  ensures \result >= 1;
*/
int foo159(int * args, int args_len, int array) {

    int ret = 0;
        
    /*@
      loop invariant 0 <= ret <= array;
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      
      loop invariant \forall integer k; 0 <= k < ret ==>
                       (args[k] == k + 1 || args[k] <= 0 || args[k] > array);
      
      loop invariant \forall integer k; 0 <= k < array ==>
                       ((args[k] > 0 && args[k] <= args_len && args[k] != k + 1) || (args[k] <= 0 || args[k] > args_len || args[k] == k + 1));
      
      loop invariant (ret == array) ==>
                       (\forall integer i; 0 <= i < array ==> (args[i] == i + 1 || args[i] <= 0 || args[i] > array));
      
      loop assigns ret, args[0..args_len-1];
    */
    while (ret < array) {
        if (args[ret] <= 0 || args[ret] > array
            || args[ret] == ret + 1) {
            ret++;
        } else {
            int j = args[ret];
            args[ret] = args[j - 1];
            args[j - 1] = j;
        }
    }
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 0 <= ret <= array;
      loop invariant \forall integer k; 0 <= k < ret ==> args[k] == k + 1;
      loop invariant \forall integer i; 0 <= i < args_len ==> \true;
      loop invariant (!(ret < array)) ==> (\forall integer i; 0 <= i < array ==> args[i] == i + 1);
      loop assigns ret;
    */
    for (ret = 0; ret < array; ret++) {
        if (args[ret] != ret + 1) {
            return ret + 1;
        }
    }
            
    return array + 1;
}
