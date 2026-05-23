
/*@
  requires num < 0;
  assigns \nothing;
  ensures \result == -1 <==> num < 0;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> \result >= 0;
  ensures num >= 0 ==> \result * \result <= num;
  ensures num >= 0 ==> (\result + 1) * (\result + 1) > num;
*/
int foo310(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= left <= num + 1;
          loop invariant -1 <= right <= num;
          loop invariant left <= right + 1;
          loop invariant (0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (0 <= left <= num + 1));
          loop invariant (0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (-1 <= right <= num));
          loop invariant (!(0 <= \at(num,Pre))) ==> ((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre)));
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
