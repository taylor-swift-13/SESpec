int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n);

/*@
    requires arr1_len >= 0 && arr2_len >= 0;
    requires arr1_len == 0 || \valid(arr1 + (0 .. arr1_len-1));
    requires arr2_len == 0 || \valid(arr2 + (0 .. arr2_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer t; 0 <= t < \result && t < arr1_len && t < arr2_len ==> arr1[t] == arr2[t];
    ensures (\result < arr1_len && \result < arr2_len) ==> arr1[\result] != arr2[\result];
*/
int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        /*@
            loop invariant 0 <= i <= arr1_len;
            loop invariant 0 <= j <= arr2_len;
            loop invariant \forall integer t; 0 <= t < i && 0 <= t < j ==> arr1[t] == arr2[t];
            loop assigns i, j;
            loop variant (arr1_len - i) + (arr2_len - j);
        */
        while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1_len ? i : j;
}
