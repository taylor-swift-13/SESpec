
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
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
