/*@
    requires arr1_len >= 0;
    requires arr2_len >= 0;
    requires \valid_read(arr1 + (0 .. arr1_len - 1));
    requires \valid_read(arr2 + (0 .. arr2_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= arr1_len + arr2_len;
*/
int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n);

 /*@
    requires arr1_len >= 0;
    requires arr2_len >= 0;
    requires \valid_read(arr1 + (0 .. arr1_len - 1));
    requires \valid_read(arr2 + (0 .. arr2_len - 1));
    assigns \nothing;
*/
int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        /*@
            loop invariant 0 <= i <= arr1_len;
            loop invariant 0 <= j <= arr2_len;
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
