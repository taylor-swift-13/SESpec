/*@
    requires \valid(arr+(0..arr_len-1));
    requires arr_len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int pairOrSum(int * arr, int arr_len, int n);

int pairOrSum(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@
            loop invariant 0 <= i <= arr_len;
            loop invariant sum >= 0;
            loop assigns i, sum;
        */
        for (int i = 0; i < arr_len; i++) {
            /*@
                loop invariant i + 1 <= j <= arr_len;
                loop invariant sum >= 0;
                loop assigns j, sum;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
}
