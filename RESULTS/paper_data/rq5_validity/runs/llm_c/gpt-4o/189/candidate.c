/*@
    requires n > 0;
    requires \valid(arr + (0..n-1));
    requires arr_len >= n;
    ensures \result >= 1;
    ensures \exists integer min; 
             (\forall integer i; 0 <= i < n ==> arr[i] >= min) &&
             (\result == \sum(0, n-1, \lambda integer i; arr[i] == min ? 1 : 0));
    assigns \nothing;
*/
int frequencyOfSmallest(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
            loop invariant 1 <= i <= n;
            loop invariant \exists integer min; 
                           (\forall integer j; 0 <= j < i ==> arr[j] >= min) &&
                           (count == \sum(0, i-1, \lambda integer j; arr[j] == min ? 1 : 0));
            loop assigns i, min, count;
            loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }
        return count;
}
