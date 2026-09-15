
/*@ ensures num < 0 ==> \result == -1;
    ensures num >= 0 ==> \result >= 0 && sq(\result) <= num && sq(\result + 1) > num;
    assigns \nothing;
*/
int foo69(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        
            
        /*@
          loop invariant 0 <= left;
          loop invariant left <= num + 1;
          loop invariant -1 <= right;
          loop invariant right <= num;
          loop invariant left <= right + 1;
          loop invariant num == \at(num,Pre);
          loop invariant left * left <= num;
          loop invariant (right + 1) * (right + 1) > num;
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
