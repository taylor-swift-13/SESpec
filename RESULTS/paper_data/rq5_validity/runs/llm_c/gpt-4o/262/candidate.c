/*@ 
    requires \valid(a + (0..a_len-1));
    requires a_len >= 0;
    requires \forall integer i; 0 <= i < a_len-1 ==> a[i] <= a[i+1];
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || a[\result] >= x;
    ensures \result == 0 || a[\result-1] < x;
    assigns \nothing;
*/
int leftInsertion(int * a, int a_len, int x);

int leftInsertion(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        /*@
        loop invariant 0 <= left && right < a_len;
        loop invariant -1 <= right && left <= a_len;
        loop invariant \forall integer i; 0 <= i < left ==> a[i] < x;
        loop invariant \forall integer i; right < i < a_len ==> a[i] >= x;
        loop assigns left, right;
        loop variant right - left;
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
