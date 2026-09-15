


/*@
  requires \valid_read(arr + (0..arr_len-1));
  requires arr_len >= 0;
  assigns \nothing;
  ensures \result != \null ==> \true;
  ensures \result == \null ==> \false;
*/
const char * foo272(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        
        /*@
          loop invariant firstElement == arr[0];
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (i < n) ==> (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
          loop invariant (!(i < n)) ==> (\forall integer k; 0 <= k < n ==> arr[k] == firstElement);
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop assigns i;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
            
        return "YES";
}
