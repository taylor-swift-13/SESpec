/*@
    requires n >= 0;
    requires arr_len >= n;
    requires n == 0 || \valid_read(arr + (0 .. n - 1));
    assigns \nothing;
    ensures n == 0 ==> \result == 0;
    ensures n > 0 ==> 1 <= \result <= n;
*/
int frequencyOfSmallest(int n, int * arr, int arr_len);

 /*@
    requires n >= 0;
    requires arr_len >= n;
    requires n == 0 || \valid_read(arr + (0 .. n - 1));
    assigns \nothing;
    ensures n == 0 ==> \result == 0;
    ensures n > 0 ==> 1 <= \result <= n;
*/
int frequencyOfSmallest(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
            loop invariant 1 <= i <= n;
            loop invariant 1 <= count <= i;
            loop assigns i, min, count;
            loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }
        return count;
}
