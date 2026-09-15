
        /*@
  assigns \nothing;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> \result >= -1;
  ensures num >= 0 ==> \result <= num;
*/
int foo310(int num) {

    if (num < 0) {
        return -1;
    }

    int left = 0;
    int right = num;

    /*@
      loop invariant 0 <= left;
      loop invariant -1 <= right;
      loop invariant right <= num;
      loop invariant left <= right + 1;
      loop invariant left == 0 || (left - 1) * (left - 1) <= num;
      loop invariant right == num || (right + 1) * (right + 1) >= num;
      loop assigns left, right;
      loop variant right - left + 1;
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
