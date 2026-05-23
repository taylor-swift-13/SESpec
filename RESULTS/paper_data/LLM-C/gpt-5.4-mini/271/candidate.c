/*@
    requires arrSize >= 0;
    requires arr_len >= arrSize;
    requires \valid_read(arr + (0 .. arrSize - 1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < arrSize && arr[i] == \result && arr[i] % 2 != 0);
*/
int getOddOccurrence(int * arr, int arr_len, int arrSize);

 /*@
    requires arrSize >= 0;
    requires arr_len >= arrSize;
    requires \valid_read(arr + (0 .. arrSize - 1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < arrSize && arr[i] == \result && arr[i] % 2 != 0);
*/
int getOddOccurrence(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        /*@
            loop invariant 0 <= i <= arrSize;
            loop invariant count >= 0;
            loop invariant result == 0 || (\exists integer j; 0 <= j < i && arr[j] == result && arr[j] % 2 != 0);
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
