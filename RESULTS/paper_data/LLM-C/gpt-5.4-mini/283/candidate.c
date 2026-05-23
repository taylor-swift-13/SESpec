/*@
    requires n > 0;
    requires \valid_read(arr + (0 .. n - 1));
    assigns \nothing;
    ensures \result == arr[n - 1] || (\exists integer i; 0 <= i < n - 1 && arr[i] != arr[i + 1] && \result == arr[i]);
*/
int search(int * arr, int arr_len, int n);

int search(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
            loop invariant 0 <= i <= n - 1;
            loop invariant \valid_read(arr + (0 .. n - 1));
            loop assigns i;
            loop variant n - 1 - i;
        */
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
        return arr[n - 1];
}
