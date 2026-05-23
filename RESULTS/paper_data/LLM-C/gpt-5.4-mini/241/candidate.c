/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int countPairs(int * arr, int arr_len, int n);

 /*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        /*@
            loop invariant 0 <= i <= length - 1;
            loop invariant count >= 0;
            loop assigns i, count;
            loop variant length - 1 - i;
        */
        for (int i = 0; i < length - 1; i++) {
            /*@
                loop invariant i + 1 <= j <= length;
                loop invariant count >= 0;
                loop assigns j, count;
                loop variant length - j;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
        }
        return count;
}
