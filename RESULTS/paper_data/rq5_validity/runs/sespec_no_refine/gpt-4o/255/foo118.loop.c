
/*@
  logic boolean is_sorted(int* a, integer len) =
    \forall integer i; 0 <= i < len - 1 ==> a[i] <= a[i + 1];
*/

/*@
  requires \valid(args + (0 .. args_len-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires is_sorted(args, args_len);
  ensures \result == args_len || (0 <= \result < args_len && args[\result] == array);
*/
int foo118(int * args, int args_len, int array) {

    int result = 0;
    int top = args_len - 1;
    
    /*@
      loop invariant 0 <= result <= top + 1;
      loop invariant -1 <= top < args_len;
      loop invariant \forall integer k; 0 <= k < result ==> args[k] < array;
      loop invariant \forall integer k; top < k < args_len ==> args[k] > array;
      loop invariant is_sorted(args, args_len);
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns result, top;
    */
    while (result <= top) {
        int i = (result + top) / 2;
        if (args[i] == array) {
            return i;
        } else if (args[i] < array) {
            result = i + 1;
        } else {
            top = i - 1;
        }
    }
    
    return result;
}
