int sqrtRoot(int num);

/*@ 
  requires num < 0 || (0 <= num && num <= 46340);
  assigns \nothing;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> 0 <= \result && \result <= num;
  ensures num >= 0 ==> (\result * \result <= num) && ((\result + 1) * (\result + 1) > num);
*/
int sqrtRoot(int num) {

        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        /*@
          loop invariant 0 <= left && left <= num + 1;
          loop invariant -1 <= right && right <= num;
          loop invariant forall integer k; 0 <= k < left ==> k*k <= num;
          loop invariant forall integer k; (right < k && k <= num) ==> k*k > num;
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
