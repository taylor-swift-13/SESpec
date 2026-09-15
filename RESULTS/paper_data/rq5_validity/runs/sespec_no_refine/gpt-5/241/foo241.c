
/*@
  logic integer cnt_neq_suffix(int* a, integer i, integer j, integer hi) =
    j >= hi ? 0 : (a[i] != a[j] ? 1 : 0) + cnt_neq_suffix(a, i, j+1, hi);
*/

/*@ logic integer total_neq_pairs(int* a, integer n, integer i) =
      i >= n - 1 ? 0 : cnt_neq_suffix(a, i, i + 1, n) + total_neq_pairs(a, n, i + 1);
*/
/*@
  requires \valid(arr + (0 .. arr_len-1));
  requires arr_len >= 0;
  requires n == n;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == total_neq_pairs(arr, \old(arr_len), 0);
  ensures arr == \old(arr);
  ensures arr_len == \old(arr_len);
  ensures n == \old(n);
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
*/
int foo241(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant length == \at(arr_len,Pre);
              loop invariant n == \at(n,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant arr == \at(arr,Pre);
              loop invariant \forall integer k; 0 <= k < length ==> arr[k] == \at(arr[k],Pre);
              loop invariant 0 <= i <= (length >= 1 ? length - 1 : 0);
              loop invariant (i < length - 1) ==> (count == cnt_neq_suffix(arr, i, i+1, length));
              loop assigns i, j, count;
            */
            for (int i = 0; i < length - 1; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= length - 1 ==> 0 <= i;
              loop invariant 0 <= i <= length - 1 ==> i + 1 <= length;
              loop invariant count >= 0;
              loop assigns count, j;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
            
        }
            
        return count;
}
