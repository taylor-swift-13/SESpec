
/* No extra predicates needed */

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result && \result <= (a_len > 0 ? \at(a_len,Pre) - 1 : 0);
  ensures (\result > 0) ==> (1 <= \result <= \at(a_len,Pre)-1
                             && \at(a[\result-1],Pre) > \at(a[\result],Pre));
  ensures \result == 0 || (\result >= 1 && \result <= \at(a_len,Pre)-1);
  ensures \forall integer i; 0 <= i < \at(a_len,Pre) ==> a[i] == \at(a[i],Pre);
  ensures a_len == \at(a_len,Pre) && a == \at(a,Pre);
*/
int foo174(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= start;
          loop invariant end <= \at(a_len,Pre) - 1;
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (0 <= start <= \at(a_len,Pre));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> ( -1 <= end <= \at(a_len,Pre) - 1);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> a[k] == \at(a[k],Pre);
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
