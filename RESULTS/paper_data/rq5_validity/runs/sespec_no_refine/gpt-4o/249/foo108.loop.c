
/*@
  logic integer unchanged_array{L1,L2}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(a[i],L2);
*/

/*@
  logic integer mid_value(int start, int stop) = (start + stop) / 2;
*/

/*@
  logic integer updated_found(int found, int num, int mid, int i) =
    (i == mid || i < mid) ? mid + 1 : found;
*/

/*@
  logic integer updated_num(int found, int num, int mid, int i) =
    (i > mid) ? mid - 1 : num;
*/

int foo108(int * args, int args_len, int start, int stop) {

    int found = start;
    int num = stop;
    int mid;

    /*@
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> 
        (((num == \at(stop,Pre)) && (found == \at(start,Pre)) && 
          (stop == \at(stop,Pre)) && (start == \at(start,Pre)) && 
          (args_len == \at(args_len,Pre)) && (args == \at(args,Pre))) || 
         (found == updated_found(\at(start,Pre), \at(stop,Pre), mid_value(found, num), args[mid_value(found, num)])));
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> 
        (((num == \at(stop,Pre)) && (found == \at(start,Pre)) && 
          (stop == \at(stop,Pre)) && (start == \at(start,Pre)) && 
          (args_len == \at(args_len,Pre)) && (args == \at(args,Pre))) || 
         (num == updated_num(\at(start,Pre), \at(stop,Pre), mid_value(found, num), args[mid_value(found, num)])));
      loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> 
        ((num == \at(stop,Pre)) && (found == \at(start,Pre)) && 
         (stop == \at(stop,Pre)) && (start == \at(start,Pre)) && 
         (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)));
      loop invariant stop == \at(stop,Pre);
      loop invariant start == \at(start,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant unchanged_array{Pre,Here}(args, args_len);
      loop assigns mid, i, found, num;
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
