
/*@
  logic integer sum_xor(int *arr, integer lo, integer hi, integer i) =
    lo >= hi ? 0 :
    (arr[i] ^ arr[lo]) + sum_xor(arr, lo + 1, hi, i);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == (\sum integer i; 0 <= i < arr_len; (\sum integer j; i + 1 <= j < arr_len; arr[i] ^ arr[j]));
*/
int foo155(int * arr, int arr_len, int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i < \at(arr_len,Pre)) ==> (sum == (\sum integer p; 0 <= p < i; (\sum integer q; p + 1 <= q < \at(arr_len,Pre); \at(arr,Pre)[p] ^ \at(arr,Pre)[q])));
          loop invariant (!(i < \at(arr_len,Pre))) ==> ((sum == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid(&arr[0] + (0..\at(arr_len,Pre)-1));
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> 0 <= arr[k] <= 100;
          loop assigns i, j, sum;
            */
            for (int i = 0; i < arr_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= arr_len;
              loop invariant sum >= 0;
              loop invariant sum == (\sum integer p; 0 <= p < i; (\sum integer q; p + 1 <= q < arr_len; arr[p] ^ arr[q]));
              loop assigns i, sum;
              loop variant arr_len - i;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
            
        }
            
        return sum;
}
