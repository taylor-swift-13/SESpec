
/*@
  predicate all_equal_prefix(int *arr, integer n, integer i, int v) =
    \forall integer k; 0 <= k < i ==> arr[k] == v;
*/

const char * foo272(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant firstElement == arr[0];
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
          loop invariant (!(i < n)) ==> (\forall integer k; 0 <= k < n ==> arr[k] == firstElement);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
            */
            for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
            
        return "YES";
}
