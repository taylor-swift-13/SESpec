
/*@
  logic integer unchanged_array{L1,L2}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i], L1) == \at(a[i], L2);
*/

/*@
  logic integer is_found(int* a, integer start, integer stop, integer len) =
    \exists integer i; start <= i <= stop && a[i] == i;
*/

/*@
  logic integer is_total(int* a, integer start, integer stop, integer len) =
    \forall integer i; start <= i <= stop ==> a[i] != i;
*/

int foo110(int * args, int args_len, int start, int stop) {

    int found = start;
    int total = stop;
    int mid;

    /*@
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (is_found(args,found,stop,args_len)));
      loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (is_total(args,found,stop,args_len)));
      loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
      loop invariant stop == \at(stop,Pre);
      loop invariant start == \at(start,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant unchanged_array{Pre,Here}(args, args_len);
      loop assigns mid, i, found, total;
    */
    while (found <= total) {
        mid = (found + total) / 2;
        int i = args[mid];

        if (i == mid) {
            found = mid + 1;
        } else if (i < mid) {
            found = mid + 1;
        } else {
            total = mid - 1;
        }
    }

    return found;
}
