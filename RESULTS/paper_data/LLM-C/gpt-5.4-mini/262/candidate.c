/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
*/
int leftInsertion(int * a, int a_len, int x);

 /*@
    requires a_len >= 0;
    requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= a_len;
*/
int leftInsertion(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        /*@
            loop invariant 0 <= left <= a_len;
            loop invariant -1 <= right < a_len;
            loop invariant left <= right + 1;
            loop assigns left, right;
            loop variant right - left + 1;
        */
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
}
