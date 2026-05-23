/*@ 
    requires \valid(arr + (0..arr_len-1));
    requires 0 <= n <= arr_len;
    ensures \result == \sum(0, n-1, (i % 2 == 0 && arr[i] % 2 == 0) ? arr[i] : 0);
    assigns \nothing;
*/
int sumEvenAndEvenIndex(int * arr, int arr_len, int n) {

        int count = 0;
        /*@
        loop invariant 0 <= i <= n;
        loop invariant count == \sum(0, i-1, (j % 2 == 0 && arr[j] % 2 == 0) ? arr[j] : 0);
        loop assigns i, count;
        loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    count += arr[i];
                }
            }
        }
        return count;
}
