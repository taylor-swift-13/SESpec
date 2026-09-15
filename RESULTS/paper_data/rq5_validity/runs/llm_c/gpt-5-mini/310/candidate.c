int sqrtRoot(int num);

/*@
    requires num < 0 || num <= 46340;
    assigns \nothing;
    behavior negative:
        assumes num < 0;
        ensures \result == -1;
    behavior non_negative:
        assumes num >= 0;
        ensures 0 <= \result <= num;
        ensures \result * \result <= num;
        ensures (\result + 1) * (\result + 1) > num;
    complete behaviors negative, non_negative;
    disjoint behaviors negative, non_negative;
*/
int sqrtRoot(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        /*@
            loop invariant num >= 0 ==> 0 <= left <= num + 1;
            loop invariant num >= 0 ==> -1 <= right <= num;
            loop invariant num >= 0 ==> left <= right + 1;
            loop invariant num >= 0 ==> \forall integer k; 0 <= k < left ==> k * k <= num;
            loop invariant num >= 0 ==> \forall integer k; right < k <= num ==> k * k > num;
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
