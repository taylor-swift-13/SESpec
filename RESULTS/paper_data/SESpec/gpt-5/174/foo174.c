
/*@
  requires a_len >= 0;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures (\result == 0) ==> (\at(a_len,Pre) == a_len && a == \at(a,Pre) && \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre));
  ensures (\result != 0) ==> (1 <= \result <= a_len - 1);
  ensures (a_len == 0) ==> (\result == 0);
  ensures (a_len > 0) ==> (0 <= \result && \result <= a_len - 1);
*/
int foo174(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        
        /*@
          loop invariant 0 <= start;
          loop invariant end <= \at(a_len,Pre) - 1;
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> a[k] == \at(a[k],Pre);
          loop invariant (start <= end) ==> (start <= (start + (end - start) / 2));
          loop invariant (start <= end) ==> ((start + (end - start) / 2) <= end);
          loop invariant (start <= end && start < end) ==> (start + 1 <= end);
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((end == \at(a_len,Pre) - 1)&&(start == 0)&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= start));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((end == \at(a_len,Pre) - 1)&&(start == 0)&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (start <= \at(a_len,Pre)));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((end == \at(a_len,Pre) - 1)&&(start == 0)&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= end));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((end == \at(a_len,Pre) - 1)&&(start == 0)&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (end <= \at(a_len,Pre) - 1));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((end == \at(a_len,Pre) - 1)&&(start == 0)&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop assigns start, end;
        */
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && a[mid] > a[mid + 1]) {
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                return mid;
            }
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
            
        return 0;
}
