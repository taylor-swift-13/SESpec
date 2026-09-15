
/*@
  ensures \result == -1 || \result == \old(num) / 2 || \result <= \old(num);
  assigns \nothing;
*/
int foo310(int num) {
    if (num < 0) {
        return -1;
    }
    int left = 0;
    int right = num;

    /*@
      loop invariant num == \at(num,Pre);
      loop invariant 0 <= left;
      loop invariant right <= num;
      loop invariant left <= right + 1;
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
