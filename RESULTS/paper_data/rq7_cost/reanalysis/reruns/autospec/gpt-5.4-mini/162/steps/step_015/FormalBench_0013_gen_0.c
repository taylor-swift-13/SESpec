/*@
    requires \valid(arr + (0 .. n-1));
    requires 0 <= n <= arr_len;
    assigns arr[0 .. n-1];
    ensures 1 <= \result <= n + 1;
*/
int firstMissingPositive(int * arr, int arr_len, int n);

 /*@
    requires \valid(arr + (0 .. n-1));
    requires 0 <= n <= arr_len;
    assigns arr[0 .. n-1];
    ensures 1 <= \result <= n + 1;
 */
int firstMissingPositive(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant \valid(arr + (0 .. n-1));
            loop assigns i, arr[0 .. n-1];
            loop variant n - i;
        */
        while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
        /*@
            loop invariant 0 <= i <= n;
            loop invariant \valid(arr + (0 .. n-1));
            loop assigns i;
            loop variant n - i;
        */
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
}