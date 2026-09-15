int getGcd(int * arr, int arr_len);

/*@
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0 || (\exists integer k; 0 <= k < arr_len && \result == arr[k]);
*/
int getGcd(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        /*@
            loop invariant 1 <= i <= arr_len;
            loop invariant (\exists integer m; 0 <= m < i && min == arr[m]);
            loop invariant result == 0 || (\exists integer j; 0 <= j < i && result == arr[j]);
            loop invariant result >= 0;
            loop assigns i, result, min;
            loop variant arr_len - i;
        */
        for (int i = 1; i < arr_len; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
        return result;
}
