/*@
    requires \valid_read(arr1+(0..arr1_len-1));
    requires \valid_read(arr2+(0..arr2_len-1));
    requires arr1_len == n && arr2_len == n-1;
    ensures \result >= 0 && \result < arr1_len;
    ensures \forall integer k; 0 <= k < \result ==> arr1[k] == arr2[k];
    ensures \result == arr1_len-1 || arr1[\result] != arr2[\result];
    assigns \nothing;
*/
int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        /*@
            loop invariant 0 <= i <= arr1_len;
            loop invariant 0 <= j <= arr2_len;
            loop invariant \forall integer k; 0 <= k < i ==> arr1[k] == arr2[k];
            loop assigns i, j;
            loop variant arr1_len - i + arr2_len - j;
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
