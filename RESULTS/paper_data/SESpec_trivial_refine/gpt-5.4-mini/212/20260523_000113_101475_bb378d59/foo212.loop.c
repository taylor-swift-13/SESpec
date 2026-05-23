
/*@
requires arr1_len >= 0;
requires arr2_len >= 0;
*/

int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 0 <= i <= arr1_len;
          loop invariant 0 <= j <= arr2_len;
          loop assigns i, j;
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
