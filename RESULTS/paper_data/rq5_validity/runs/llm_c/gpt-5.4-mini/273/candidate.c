/*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0 || \result <= 0;
*/
int sumOfSubarrayProd(int * arr, int arr_len, int n);

 /*@
    requires arr_len >= 0;
    requires n >= 0;
    requires n <= arr_len;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
*/
int sumOfSubarrayProd(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant \true;
            loop assigns i, sum, product, j;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            int product = 1;
            /*@
                loop invariant i <= j <= n;
                loop invariant \true;
                loop assigns j, product, sum;
                loop variant n - j;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
}
