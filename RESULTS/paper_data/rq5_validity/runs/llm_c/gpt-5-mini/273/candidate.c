int sumOfSubarrayProd(int * arr, int arr_len, int n);

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires 0 <= n <= arr_len;
    requires \valid(arr + (0 .. n-1));
    assigns \nothing;
    ensures \result == \sum integer i; 0 <= i < n; \sum integer j; i <= j < n; \product integer k; i <= k <= j; arr[k];
*/
int sumOfSubarrayProd(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant sum == (\sum integer u; 0 <= u < i; \sum integer v; u <= v < n; \product integer k; u <= k <= v; arr[k]);
            loop assigns i, sum;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            int product = 1;
            /*@
                loop invariant i <= j <= n;
                loop invariant product == (\product integer k; i <= k < j; arr[k]);
                loop invariant sum == (\sum integer u; 0 <= u < i; \sum integer v; u <= v < n; \product integer k; u <= k <= v; arr[k]) + (\sum integer v; i <= v < j; \product integer k; i <= k <= v; arr[k]);
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
