
/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/

int foo167(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        
            
        /*@
          loop invariant max1 >= arr[0];
          loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max1;
          loop invariant (i < \at(n,Pre)) ==> (max1 >= arr[0]);
          loop invariant (i < \at(n,Pre)) ==> ((k == \at(k,Pre))&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant (!(i < \at(n,Pre))) ==> ((k == \at(k,Pre))&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre);
          loop assigns i, max1;
            */
            for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
            
        int res = 0;
        
            
        /*@
          loop invariant \forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0;
          loop invariant \forall integer j; 0 <= j < n ==> arr[j] == \at(arr[j],Pre);
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns i, res;
            */
            for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
            
        return res;
}
