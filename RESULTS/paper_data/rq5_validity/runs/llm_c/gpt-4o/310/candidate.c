/*@
    requires num >= 0;
    ensures \result >= 0;
    ensures \result * \result <= num < (\result + 1) * (\result + 1);
    assigns \nothing;
*/
int sqrtRoot(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        /*@
        loop invariant 0 <= left && left <= right + 1 && right <= num;
        loop invariant \forall integer x; 0 <= x < left ==> x * x <= num;
        loop invariant \forall integer x; right < x <= num ==> x * x > num;
        loop assigns left, right;
        loop variant right - left;
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
