/*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getPairsCount(int * arr, int arr_len, int n, int sum);

 /*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getPairsCount(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant count >= 0;
            loop assigns i, count, j;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
                loop invariant i + 1 <= j <= n;
                loop invariant count >= 0;
                loop assigns j, count;
                loop variant n - j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
}
