/*@
    requires \valid(arr + (0..arrSize-1));
    requires arr_len == arrSize;
    ensures \exists integer i; 0 <= i < arrSize && arr[i] % 2 != 0 ==> \result == arr[i];
    ensures \result == 0 || (\exists integer i; 0 <= i < arrSize && arr[i] % 2 != 0 && \result == arr[i]);
    assigns \nothing;
*/
int getOddOccurrence(int * arr, int arr_len, int arrSize);

int getOddOccurrence(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        /*@
            loop invariant 0 <= i <= arrSize;
            loop invariant count >= 0;
            loop invariant \forall integer j; 0 <= j < i ==> (arr[j] % 2 != 0 ==> count >= 1);
            loop assigns i, count, result;
            loop variant arrSize - i;
        */
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count % 2 != 0) {
                    result = arr[i];
                }
            }
        }
        return result;
}
