int search(int * arr, int arr_len, int n);

/*@
    requires n >= 1;
    requires arr_len >= n;
    requires \valid(arr + (0 .. n-1));
    assigns \nothing;
    ensures \exists integer k; 0 <= k < n &&
            ((k == n-1) || arr[k] != arr[k+1]) &&
            (\forall integer j; 0 <= j < k ==> arr[j] == arr[j+1]) &&
            \result == arr[k];
*/
int search(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant i % 2 == 0;
            loop invariant \forall integer j; 0 <= j < i ==> (j % 2 == 0 ==> arr[j] == arr[j+1]);
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
