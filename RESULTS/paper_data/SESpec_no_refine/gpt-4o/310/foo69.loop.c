
/*@
  logic integer square(integer x) = x * x;
*/

/*@
  requires \at(num,Pre) >= 0;
  ensures \result * \result <= num && (num < (\result + 1) * (\result + 1));
*/
int foo69(int num) {

    if (num < 0) {
        return -1;
    }
    int left = 0;
    int right = num;

    /*@
      loop invariant 0 <= left && left <= right + 1 && right <= num;
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
