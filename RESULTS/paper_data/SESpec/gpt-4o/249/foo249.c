
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires start <= stop; // Added to ensure valid range
  
  ensures \result >= \at(start, Pre) && \result <= \at(stop, Pre) + 1;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
*/
int foo249(int * args, int args_len, int start, int stop) {

    int found = start;
    int num = stop;
    int mid;

    /*@
      loop invariant start <= found <= stop + 1 || start > stop;
      loop invariant start - 1 <= num <= stop || start > stop;
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found >= start && num <= stop);
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (num >= found - 1);
      loop invariant stop == \at(stop,Pre);
      loop invariant start == \at(start,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns mid, found, num;
    */
    while (found <= num) {
        mid = (found + num) / 2;
        int i = args[mid];

        if (i == mid) {
            found = mid + 1;
        } else if (i < mid) {
            found = mid + 1;
        } else {
            num = mid - 1;
        }
    }

    return found;
}
