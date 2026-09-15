
int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@

          loop invariant n == \at(n,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre);
          loop invariant \forall integer k; 0 <= k < arr2_len ==> arr2[k] == \at(arr2[k], Pre);

          loop invariant (i < arr1_len && j < arr2_len) ==> (arr1[i] != arr2[j] ==> (arr1[i] < arr2[j] || arr2[j] < arr1[i]));

          loop invariant (!(0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre))) ==> (i == 0 && j == 0);
          
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
