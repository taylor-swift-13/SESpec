
/*@
  logic integer square(integer x) = x * x;
*/

/*@
  requires \at(num,Pre) >= 0;
  ensures \result * \result <= \at(num,Pre);
  ensures (\result + 1) * (\result + 1) > \at(num,Pre);
*/
int foo69(int num) {

    if (num < 0) {
        return -1;
    }
    int left = 0;
    int right = num;

    /*@
      loop invariant (0 <= \at(num,Pre)) ==> 
        (((right == \at(num,Pre)) && (left == 0) && (num == \at(num,Pre))) || 
         (left * left <= \at(num,Pre) && (right + 1) * (right + 1) > \at(num,Pre)));
      loop invariant (0 <= \at(num,Pre)) ==> 
        (((right == \at(num,Pre)) && (left == 0) && (num == \at(num,Pre))) || 
         (square(left - 1) < \at(num,Pre) && square(right + 1) > \at(num,Pre)));
      loop invariant (!(0 <= \at(num,Pre))) ==> 
        ((right == \at(num,Pre)) && (left == 0) && (num == \at(num,Pre)));
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
