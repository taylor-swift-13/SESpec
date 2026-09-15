/*@
    requires \valid(arr+(0..arr_len-1));
    requires n >= 0 && n <= arr_len;
    ensures \result >= 0;
    assigns \nothing;
*/
int findMinSwaps(int * arr, int arr_len, int n);

int findMinSwaps(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant 1 <= j <= n;
            loop invariant count >= 0;
            loop assigns i, j, count;
            loop variant n - i;
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
