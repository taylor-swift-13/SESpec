/*@ 
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures \result == \sum(integer i, integer j) (0 <= i < j < arr_len) ? (arr[i] ^ arr[j]) : 0;
*/
int pairOrSum(int * arr, int arr_len, int n);

 /*@ 
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
*/
int pairOrSum(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@
            loop invariant 0 <= i <= arr_len;
            loop invariant sum == \sum(integer a, integer b) (0 <= a < b < i) ? (arr[a] ^ arr[b]) : 0;
            loop assigns i, sum, j;
            loop variant arr_len - i;
        */
        for (int i = 0; i < arr_len; i++) {
            /*@
                loop invariant i + 1 <= j <= arr_len;
                loop invariant sum == \sum(integer a, integer b) (0 <= a < i && a < b < arr_len) ? (arr[a] ^ arr[b]) : 0;
                loop assigns j, sum;
                loop variant arr_len - j;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
}
