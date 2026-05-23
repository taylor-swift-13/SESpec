int findMinSwaps(int * arr, int arr_len, int n);

/*@
    requires arr_len >= 0;
    requires 0 <= n <= arr_len;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int findMinSwaps(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant 0 <= j <= n;
            loop invariant 0 <= count <= n;
            loop assigns i, j, count;
            loop variant 2*n - i - j;
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
