
/*@
  /* Predicate expressing that array a is equal to its value in the pre-state */
  logic boolean same_array(int* a, integer lo, integer hi, int* a_pre) =
    \forall integer i; lo <= i < hi ==> a[i] == a_pre[i];
*/

int foo129(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((right == \at(a_len,Pre) - 1)&&(left == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (PLACE_HOLDER_left));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((right == \at(a_len,Pre) - 1)&&(left == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (PLACE_HOLDER_right));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((right == \at(a_len,Pre) - 1)&&(left == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant PLACE_HOLDER_ARRAY_a ;
          loop assigns mid, left, right;
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
