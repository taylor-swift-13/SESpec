int foo310(int num);


/*@
ensures \exists integer left_59; (0 <= left_59) && (left_59 <= num) && (num >= 0) ==> (left_59 > \result) && (0 <= \result) && (\result <= num) && (left_59 <= \result + 1);
ensures \exists integer left_59, right_58; ((left_59 + (right_58 - left_59) / 2) * (left_59 + (right_58 - left_59) / 2) == num) && (left_59 <= right_58) && (0 <= left_59) && (left_59 <= num) && (0 <= right_58) && (right_58 <= num) && (left_59 <= right_58 + 1) && (num >= 0) ==> (\result == left_59 + (right_58 - left_59) / 2);
ensures (num < 0) ==> (\result == -1);

assigns \nothing;
*/

int foo310(int num) 
{
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