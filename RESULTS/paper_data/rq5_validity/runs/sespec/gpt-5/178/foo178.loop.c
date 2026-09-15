
int foo178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 0;
          loop invariant j >= 0;
          loop invariant (m >= 0) ==> (i <= m);
          loop invariant i + j == count;
          loop invariant \forall integer t; 0 <= t < i ==> 0 <= t;
          loop invariant \forall integer t; 0 <= t < j ==> 0 <= t;
          loop invariant (i < m && j < n) ==> (arr1[i] <= arr2[j] || arr2[j] < arr1[i]);
          loop invariant count >= 0;
          loop invariant (\at(k,Pre) >= 0) ==> (count <= \at(k,Pre));
          loop invariant \forall integer t; 0 <= t < arr1_len ==> arr1[t] == \at(arr1[t], Pre);
          loop invariant \forall integer t; 0 <= t < arr2_len ==> arr2[t] == \at(arr2[t], Pre);

          loop invariant (count < \at(k,Pre)) ==> (i >= 0) ;
          loop invariant (count < \at(k,Pre)) ==> (j >= 0) ;
          loop invariant (!(count < \at(k,Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k,Pre))&&(n == \at(n,Pre))&&(m == \at(m,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop assigns count, i, j;
            */
            for (int count = 0; count < k; count++) {
            if (i < m && (j >= n || arr1[i] <= arr2[j])) {
                if (count == k - 1) {
                    return arr1[i];
                }
                i++;
            } else {
                if (count == k - 1) {
                    return arr2[j];
                }
                j++;
            }
        }
            
        return -1;
}
