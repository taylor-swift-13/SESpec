/*@
    requires \valid(arr+(0..arr_len-1));
    requires 0 <= n <= arr_len;
    ensures \result >= 0;
*/
int sumOfSubarrayProd(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant sum >= 0;
            loop assigns i, sum;
        */
        for (int i = 0; i < n; i++) {
            int product = 1;
            /*@
                loop invariant i <= j <= n;
                loop invariant product >= 1;
                loop invariant sum >= 0;
                loop assigns j, product, sum;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
}
