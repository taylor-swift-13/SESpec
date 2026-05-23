/*@ 
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result * \result <= num;
    ensures (\result + 1) * (\result + 1) > num;
*/
int sqrtRoot(int num);

 /*@ 
    requires num < 0 || num >= 0;
    assigns \nothing;
    ensures num < 0 ==> \result == -1;
    ensures num >= 0 ==> \result >= 0;
    ensures num >= 0 ==> \result * \result <= num;
    ensures num >= 0 ==> (\result + 1) * (\result + 1) > num;
*/
int sqrtRoot(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        /*@
            loop invariant 0 <= left;
            loop invariant -1 <= right <= num;
            loop invariant left <= num + 1;
            loop invariant right >= -1;
            loop invariant right < num + 1;
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
