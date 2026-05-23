int bigDiff(int * arr, int arr_len);

/*@
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result == (\max integer i; 0 <= i < arr_len; arr[i]) - (\min integer i; 0 <= i < arr_len; arr[i]);
    ensures \result >= 0;
*/
int bigDiff(int * arr, int arr_len) {

        int result = arr[0];
        int num = arr[0];
        /*@
            loop invariant 1 <= n <= arr_len;
            loop invariant result == (\max integer j; 0 <= j < n; arr[j]);
            loop invariant num == (\min integer j; 0 <= j < n; arr[j]);
            loop assigns n, result, num;
            loop variant arr_len - n;
        */
        for (int n = 1; n < arr_len; n++) {
            if (arr[n] > result) {
                result = arr[n];
            }
            if (arr[n] < num) {
                num = arr[n];
            }
        }
        return result - num;
}
