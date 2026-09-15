
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  requires 0 <= arr_len;
  requires 0 <= n <= arr_len;
  requires n == 0 || \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures n == 0 ==> \result == "NO";
  ensures n > 0 && (\forall integer k; 1 <= k < n ==> arr[k] == arr[0]) ==> \result == "YES";
  ensures n > 0 && (\exists integer k; 1 <= k < n && arr[k] != arr[0]) ==> \result == "NO";
  ensures \result == \null ==> \false;
  ensures \result == "YES" || \result == "NO";
*/
const char * foo272(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
          loop assigns i;
            */
            for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
            
        return "YES";
}
