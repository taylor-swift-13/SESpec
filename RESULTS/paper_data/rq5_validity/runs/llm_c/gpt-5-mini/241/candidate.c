int countPairs(int * arr, int arr_len, int n);

/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures 0 <= \result <= arr_len*(arr_len-1)/2;
    ensures \result == (\sum integer i; 0 <= i < arr_len-1;
                           (\sum integer j; i+1 <= j < arr_len; (arr[i] != arr[j]) ? 1 : 0));
*/
int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        /*@
            loop invariant 0 <= length;
            loop invariant 0 <= i <= length;
            loop invariant count >= 0;
            loop invariant count == (\sum integer ii; 0 <= ii < i;
                                        (\sum integer jj; ii+1 <= jj < length; (arr[ii] != arr[jj]) ? 1 : 0));
            loop assigns i, count;
            loop variant length - i;
        */
        for (int i = 0; i < length - 1; i++) {
            /*@
                loop invariant i+1 <= j <= length;
                loop invariant count >= 0;
                loop invariant count == (\sum integer ii; 0 <= ii < i;
                                            (\sum integer jj; ii+1 <= jj < length; (arr[ii] != arr[jj]) ? 1 : 0))
                                 + (\sum integer jj; i+1 <= jj < j; (arr[i] != arr[jj]) ? 1 : 0);
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
