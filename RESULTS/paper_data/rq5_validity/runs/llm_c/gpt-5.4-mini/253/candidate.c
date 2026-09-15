/*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * arr, int arr_len, int n);

 /*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * arr, int arr_len, int n) {

        int invCount = 0;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant invCount >= 0;
            loop assigns i, invCount, j;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
                loop invariant i + 1 <= j <= n;
                loop invariant invCount >= 0;
                loop assigns j, invCount;
                loop variant n - j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }
        return invCount;
}
