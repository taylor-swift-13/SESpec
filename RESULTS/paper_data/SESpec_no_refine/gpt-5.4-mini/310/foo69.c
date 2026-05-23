
/*@ logic integer abs(integer x) = x < 0 ? -x : x; */

/*@ 
  predicate PLACE_HOLDER_left(integer left, integer right, integer num, integer pre) =
    0 <= left && left <= pre + 1 &&
    left <= right + 1 &&
    num == pre;
*/

/*@ 
  assigns \nothing;
  ensures \result == -1 || \result * \result == num;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> (\result == -1 || (\result >= 0 && \result * \result == num));
*/
int foo69(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (PLACE_HOLDER_left(left, right, num, \at(num,Pre))));
          loop invariant (0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (PLACE_HOLDER_right(left, right, num, \at(num,Pre))));
          loop invariant (!(0 <= \at(num,Pre))) ==> ((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre)));
          loop invariant num == \at(num,Pre);
          loop assigns mid, left, right;
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
