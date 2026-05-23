/*@
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires 0 < n <= arr_len;
    requires k > 0;
    assigns \nothing;
    ensures \result == -1 || \result >= 0;
*/
int minOps(int * arr, int arr_len, int n, int k);

 /*@
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires 0 < n <= arr_len;
    requires k > 0;
    assigns \nothing;
    ensures \result == -1 || \result >= 0;
 */
int minOps(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        /*@
            loop invariant 1 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> max1 >= arr[j];
            loop assigns i, max1;
            loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int res = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> ((max1 - arr[j]) % k == 0);
            loop invariant res >= 0;
            loop assigns i, res;
            loop variant n - i;
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
