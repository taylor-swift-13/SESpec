
/*@ logic integer prod_pref(int* a, integer lo, integer hi) =
      lo >= hi ? 1 : prod_pref(a, lo, hi - 1) * a[hi - 1]; */
        
/*@
  assigns \nothing;
  ensures n == \old(n);
  ensures arr_len == \old(arr_len);
  ensures arr == \old(arr);
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
*/
int foo273(int * arr, int arr_len, int n) {

        int sum = 0;

        /*@ 
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, sum;
         */
        for (int i = 0; i < n; i++) {
            int product = 1;

            /*@
              loop invariant i <= j <= n;
              loop invariant product == prod_pref(arr, i, j);
              loop assigns j, product, sum;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }

        }

        return sum;
}
