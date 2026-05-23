
#include <limits.h>

/*@
  requires num >= 0;
  ensures \result * \result <= num;
  ensures (\result + 1) * (\result + 1) > num;
*/
int foo310(int num) {
    if (num < 0) {
        return -1;
    }
    int left = 0;
    int right = num;

    /*@
      loop invariant 0 <= left && left <= num;
      loop invariant 0 <= right && right <= num;
      loop invariant left <= right + 1;
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
