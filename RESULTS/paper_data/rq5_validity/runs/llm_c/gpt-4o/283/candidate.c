/*@
    requires \valid(arr + (0..arr_len-1));
    requires arr_len > 0;
    ensures \exists integer i; 0 <= i < arr_len && \result == arr[i];
    assigns \nothing;
*/
int search(int * arr, int arr_len, int n);

int search(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
            loop invariant 0 <= i <= n - 1;
            loop invariant \forall integer j; 0 <= j < i ==> arr[j] != arr[j + 1];
            loop assigns i;
            loop variant n - i;
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
