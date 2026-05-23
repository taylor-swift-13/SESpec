
/*@
  assigns \nothing;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> (
            (\result >= 0 && \result * \result == num)
         || (\result >= 0 && \result * \result <= num && (\result + 1) * (\result + 1) > num)
         );
*/
int foo310(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num >= 0;
          loop invariant 0 <= left;
          loop invariant -1 <= right;
          loop invariant right <= num;
          loop invariant left <= num || right < left;
          loop invariant right < left || right*right <= num;
          loop invariant left == 0 || (left - 1) * (left - 1) < num;
          loop assigns left, right, mid;
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
