
/*@
  requires \valid(arr + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires n >= 0;
  requires arr_len >= 0;
  requires n <= arr_len;
  assigns \nothing;
  ensures \result == 0 ==> (\forall integer t; 0 <= t < arr_len ==> arr[t] == \at(arr[t],Pre));
*/
int foo273(int * arr, int arr_len, int n) {

    int sum = 0;
    
    /*@ 
      loop invariant 0 <= n;
      loop invariant n == \at(n,Pre);
      loop invariant 0 <= arr_len;
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
      loop invariant 0 <= i <= \at(n,Pre);
      loop invariant (!(i < \at(n,Pre))) ==> (n == \at(n,Pre) && arr_len == \at(arr_len,Pre) && arr == \at(arr,Pre));
      loop assigns i, sum;
    */
    for (int i = 0; i < n; i++) {
        int product = 1;
        
        /*@
          loop invariant i >= 0 && n >= 0;
          loop invariant i <= n;
          loop invariant j >= i && j <= n;
          loop invariant \forall integer k; j <= k && k < n ==> \valid(&arr[k]);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns j, product, sum;
        */
        for (int j = i; j < n; j++) {
            product *= arr[j];
            sum += product;
        }
    }
    return sum;
}
