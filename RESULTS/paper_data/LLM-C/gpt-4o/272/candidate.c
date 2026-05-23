/*@ 
    requires \valid_read(arr + (0..arr_len-1));
    requires 0 <= n <= arr_len;
    ensures \result == "YES" || \result == "NO";
    ensures n == 0 ==> \result == "NO";
    ensures n > 0 ==> (\forall integer i; 0 <= i < n ==> arr[i] == arr[0]) ==> \result == "YES";
    ensures n > 0 ==> (\exists integer i; 0 <= i < n && arr[i] != arr[0]) ==> \result == "NO";
    assigns \nothing;
*/
const char * uniqueElement(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        /*@
        loop invariant 1 <= i <= n;
        loop invariant \forall integer j; 1 <= j < i ==> arr[j] == firstElement;
        loop assigns i;
        loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
        return "YES";
}
