
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  predicate unchanged_array(int* a, integer len) =
    \forall integer k; 0 <= k < len ==> a[k] == \at(a[k], Pre);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns result, total, mid;
  ensures unchanged_array(args, args_len);
  ensures \result > stop || \result == \at(start, Pre);
  ensures \forall integer i; start <= i < \result ==> args[i] != i;
*/
int foo109(int * args, int args_len, int start, int stop) {

    int result = start;
    int total = stop;
    int mid;

    /*@
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> 
        (((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || 
        (result >= start && result <= total));
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> 
        (((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || 
        (total >= start && total <= stop));
      loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> 
        ((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
      loop invariant stop == \at(stop,Pre);
      loop invariant start == \at(start,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant unchanged_array(args, args_len);
      loop assigns mid, result, total;
    */
    while (result <= total) {
        mid = (result + total) / 2;
        int i = args[mid];

        if (i == mid) {
            result = mid + 1;
        } else if (i < mid) {
            result = mid + 1;
        } else {
            total = mid - 1;
        }
    }

    return result;
}
