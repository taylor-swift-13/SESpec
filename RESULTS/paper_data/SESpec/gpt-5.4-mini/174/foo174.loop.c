
/*@
  requires a_len >= 0;
*/
int foo174(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        
        /*@
          loop invariant 0 <= start;
          loop invariant end < a_len;
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer i; 0 <= i < a_len ==> a[i] == \at(a[i],Pre);
          loop invariant start <= end + 1;
          loop invariant start <= a_len;
          loop invariant -1 <= end;
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
