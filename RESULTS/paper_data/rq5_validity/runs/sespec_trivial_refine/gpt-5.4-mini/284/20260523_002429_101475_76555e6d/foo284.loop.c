
/*@
 logic integer imax(integer a, integer b) = a > b ? a : b;
*/

int foo284(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant result == 0 || result >= min;
          loop invariant \exists integer j; 0 <= j < i && min == arr[j];
          loop assigns i, result, min;
            */
            for (int i = 1; i < arr_len; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
            
        return result;
}
