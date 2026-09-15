/*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int findMinSwaps(int * arr, int arr_len, int n);

 /*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int findMinSwaps(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant 1 <= j <= n;
            loop invariant 0 <= count <= n;
            loop assigns i, j, count;
            loop variant (n - i) + (n - j);
        */
        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}
