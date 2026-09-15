
/*@
  requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
*/
int foo262(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= left <= a_len;
          loop invariant -1 <= right < a_len;
          loop invariant left <= right + 1;
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (0 <= left <= a_len));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (-1 <= right < a_len));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> (right == \at(a_len,Pre) - 1 && left == 0 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
          loop assigns left, right;
            */
            while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
            
        return left;
}
