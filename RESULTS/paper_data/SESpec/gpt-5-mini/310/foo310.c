
/* No additional logic/predicate needed. */

/*@
  requires \at(num,Pre) >= 0;
  assigns \nothing;
  ensures (\at(num,Pre) < 0) ==> \result == -1;
*/
int foo310(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(num,Pre)) ==> (0 <= left && left <= right + 1 && 0 <= right && right <= \at(num,Pre));
          loop invariant (0 <= \at(num,Pre)) ==> (((right == \at(num,Pre)) && (left == 0) && (num == \at(num,Pre))) || (left >= 0 && right >= -1));
          loop invariant (!(0 <= \at(num,Pre))) ==> ((right == \at(num,Pre)) && (left == 0) && (num == \at(num,Pre)));
          loop invariant num == \at(num,Pre);
          loop assigns left, right;
            */
            while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid * mid == num) {
                return mid;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
            
        return right;
}
