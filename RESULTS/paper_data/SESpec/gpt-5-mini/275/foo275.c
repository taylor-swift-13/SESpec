
/*@
  requires arr_len >= 0;
  requires arr_len == 0 || \valid(arr + (0 .. arr_len-1));
  requires \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
  assigns \nothing;
  ensures n == \at(n,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures arr == \at(arr,Pre);
*/
int foo275(int * arr, int arr_len, int n) {

        int sum = 0;
        
        /*@
          loop invariant 0 <= i && i <= arr_len;
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns i, sum;
        */
        for (int i = 0; i < arr_len; i++) {
            
            /*@
              loop invariant i >= 0 && i <= arr_len;
              loop invariant i+1 <= j && j <= arr_len;
              loop assigns j, sum;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
            
        }
            
        return sum;
}
