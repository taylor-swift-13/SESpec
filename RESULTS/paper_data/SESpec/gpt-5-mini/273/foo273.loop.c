
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/
int foo273(int * arr, int arr_len, int n) {

    int sum = 0;
    
    /*@ 
      loop invariant 0 <= n;
      loop invariant n == \at(n,Pre);
      loop invariant 0 <= arr_len;
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant 0 <= i <= \at(n,Pre);
      loop invariant (i < \at(n,Pre)) ==> (0 <= sum && sum <= 100 * (i*(i+1)/2));
      loop invariant (i < \at(n,Pre)) ==> (\exists int p; 0 <= p < i);
      loop invariant (!(i < \at(n,Pre))) ==> (sum == 0 && n == \at(n,Pre) && arr_len == \at(arr_len,Pre) && arr == \at(arr,Pre));
      loop assigns i, sum, product, j;
    */
    for (int i = 0; i < n; i++) {
        int product = 1;
        
        /*@
          loop invariant i >= 0 && n >= 0;
          loop invariant i <= n;
          loop invariant j >= i && j <= n;
          loop invariant \forall int k; j <= k && k < n ==> \valid(&arr[k]);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns j, product, sum;
        */
        for (int j = i; j < n; j++) {
            product *= arr[j];
            sum += product;
        }
    }
    return sum;
}
