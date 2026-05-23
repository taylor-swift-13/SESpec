/*@
    requires \valid(arr+(0..arr_len-1));
    requires arr_len > 0;
    ensures \forall integer i; 0 <= i < arr_len ==> arr[i] >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int getGcd(int * arr, int arr_len);

int getGcd(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        /*@
            loop invariant 1 <= i <= arr_len;
            loop invariant \forall integer j; 0 <= j < i ==> arr[j] >= 0;
            loop invariant result >= 0;
            loop invariant min == \min(arr+(0..i-1));
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
