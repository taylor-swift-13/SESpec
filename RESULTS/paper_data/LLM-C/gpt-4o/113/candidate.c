/*@ 
    requires \valid(arr + (0..arr_len-1));
    requires arr_len >= 0;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < arr_len-1 ==> arr[i] < arr[i+1]);
    ensures \result == 0 <==> (\exists integer i; 0 <= i < arr_len-1 && arr[i] >= arr[i+1]);
    assigns \nothing;
*/
int isAscending(int * arr, int arr_len);

int isAscending(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        /*@
            loop invariant 0 <= i <= n-1;
            loop invariant \forall integer j; 0 <= j < i ==> arr[j] < arr[j+1];
            loop assigns i;
            loop variant n-1-i;
        */
        for (int i = 0; i < n-1; i++) {
            if(arr[i] >= arr[i+1])
                return 0;
        }
        return 1;
}
