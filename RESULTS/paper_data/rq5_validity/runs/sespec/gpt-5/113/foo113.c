

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < arr_len - 1 ==> arr[k] < arr[k+1]);
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
  ensures \result == 1 || \result == 0;
*/
int foo113(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < i && k + 1 < n ==> arr[k] < arr[k+1];
          loop invariant \forall integer a, b; 0 <= a < b && b <= i && b < n ==> arr[a] < arr[b];
          loop invariant i == 0 || (\exists integer t; 0 <= t < i && t + 1 < n && arr[t] < arr[t+1]);
          loop invariant (i < n) ==> (\forall integer k; 0 <= k < i && k + 1 < n ==> arr[k] < arr[k+1]);
          loop invariant !(i < n) ==> (\forall integer k; 0 <= k < n - 1 ==> arr[k] < arr[k+1]);
          loop assigns i;
        */
        for (int i = 0; i < n; i++) {
            if(arr[i] >= arr[i+1])
                return 0;
        }
            
        return 1;
}
