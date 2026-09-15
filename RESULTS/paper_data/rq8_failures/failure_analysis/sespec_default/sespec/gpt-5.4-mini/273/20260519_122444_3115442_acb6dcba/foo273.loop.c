
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo273(int * arr, int arr_len, int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (i < \at(n,Pre)) ==> (sum >= 0);
          loop invariant (!(i < \at(n,Pre))) ==> ((sum == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop assigns i, product, j, sum;
            */
            for (int i = 0; i < n; i++) {
            int product = 1;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i <= j <= n;
              loop invariant product >= 1 || product <= -1 || product == 0;
              loop assigns j, product, sum;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
            
        }
            
        return sum;
}
