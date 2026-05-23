/*@ 
    requires \valid(a + (0..a_len-1));
    requires a_len >= 0;
    requires \forall integer k; 0 <= k < a_len-1 ==> a[k] <= a[k+1];
    ensures 0 <= \result <= a_len;
    ensures \result == a_len || a[\result] >= x;
    ensures \result == 0 || a[\result-1] < x;
    assigns \nothing;
*/
int rightInsertion(int * a, int a_len, int x);

int rightInsertion(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        /*@
        loop invariant 0 <= i <= a_len;
        loop invariant -1 <= j < a_len;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] < x;
        loop invariant \forall integer k; j < k < a_len ==> a[k] >= x;
        loop assigns i, j;
        loop variant j - i;
        */
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}
