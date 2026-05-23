/*@
    requires \valid(arr+(0..arr_len-1));
    requires n > 0 && n <= arr_len;
    requires k > 0;
    ensures \result >= -1;
    ensures \result == -1 ==> \exists integer i; 0 <= i < n && (arr[\max(0, \max_index(arr, n))] - arr[i]) % k != 0;
    ensures \result != -1 ==> \forall integer i; 0 <= i < n ==> (arr[\max(0, \max_index(arr, n))] - arr[i]) % k == 0;
    assigns \nothing;
*/
int minOps(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        /*@
        loop invariant 1 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> max1 >= arr[j];
        loop assigns i, max1;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int res = 0;
        /*@
        loop invariant 0 <= i <= n;
        loop invariant res >= 0;
        loop assigns i, res;
        */
        for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
        return res;
}
