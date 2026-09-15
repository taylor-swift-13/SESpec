/*@
    requires \valid(arr + (0..arr_len-1));
    requires arr_len >= 0;
    ensures \result >= 0;
    ensures \result <= (arr_len * (arr_len - 1)) / 2;
    assigns \nothing;
*/
int countPairs(int * arr, int arr_len, int n);

int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        /*@
            loop invariant 0 <= i <= length - 1;
            loop invariant count >= 0;
            loop assigns i, j, count;
            loop variant length - i;
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
