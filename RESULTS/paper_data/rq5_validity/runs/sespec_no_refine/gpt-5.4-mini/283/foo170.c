
/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  assigns i;
  ensures (n <= 1 ==> \result == arr[n - 1]) && (n > 1 && (\forall integer k; 0 <= k < n - 1 ==> arr[k] == arr[k + 1]) ==> \result == arr[n - 1]) && (n > 1 && (\exists integer k; 0 <= k < n - 1 && arr[k] != arr[k + 1]) ==> (\exists integer k; 0 <= k < n - 1 && arr[k] != arr[k + 1] && \result == arr[k]));
*/
int foo170(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /*@
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((i == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns i;
            */
            while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
            
        return arr[n - 1];
}
