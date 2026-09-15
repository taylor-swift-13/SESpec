
/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr_len >= 0;
*/
int foo119(int * arr, int arr_len) {

    int n = arr_len;
    if (n < 2) {
        return 1;
    }

    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= n;
      loop invariant \valid_read(arr + (0 .. n-1));
      loop invariant (i < n-1) ==> (0 <= i && i+1 < n);
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
      loop invariant (!(i < n)) ==> (\forall integer k; 0 <= k < n-1 ==> arr[k] > arr[k+1]);
      loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
      loop assigns i;
    */
    for (int i = 0; i < n; i++) {
        if(arr[i] <= arr[i+1])
            return 0;
    }

    return 1;
}
