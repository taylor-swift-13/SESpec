
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer count_min(int* a, integer lo, integer hi, integer m) =
    lo >= hi ? 0
             : count_min(a, lo, hi - 1, m) + (a[hi - 1] == m ? 1 : 0);
*/

/*@ 
        requires \at(n,Pre) != 0 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo189(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant count >= 1;
          loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
          loop invariant \exists integer k; 0 <= k < i && arr[k] == min;
          loop assigns i, min, count;
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
