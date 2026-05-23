

/*@
  requires 0 < a_len;
  requires \valid_read(a + (0 .. a_len-1));
  assigns \nothing;
  ensures 0 <= \result < a_len;
  ensures \result == 0 || a[\result - 1] > a[\result];
  ensures \result > 0 ==> a[\result - 1] > a[\result];
  ensures \result == 0 || \result < a_len;
*/
int foo174(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        
        /*@
          loop invariant 0 <= start;
          loop invariant end < a_len;
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
