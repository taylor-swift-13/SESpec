
/*@ 
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires 0 <= n <= arr_len;
  assigns \nothing;
  ensures \result >= 0;
  ensures 1 < n && n <= arr_len ==> \result <= (n * (n - 1)) / 2;
  ensures 0 < n && n <= arr_len ==> \result == 0 <==> (\forall integer i,j; 0 <= i < j < n ==> arr[i] + arr[j] != sum);
  ensures \result == \result; 
  ensures \result == \result;  
*/
int foo252(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        
        /*@
          loop invariant sum == \at(sum,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid(&arr[0] + (0..arr_len-1));
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant 0 <= count;
          loop assigns count;
        */
        for (int i = 0; i < n; i++) {
            /*@
              loop invariant i + 1 <= j <= n;
              loop invariant 0 <= i <= n;
              loop invariant 0 <= count;
              loop invariant \valid(&arr[0] + (0..arr_len-1));
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns count;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
            
        return count;
}
