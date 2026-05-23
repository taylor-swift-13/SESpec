
/*@
  // No additional predicate or logic function is needed for this program.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == pairwise_xor_sum{Pre}(arr, arr_len);
*/
int foo155(int * arr, int arr_len, int n) {

    int sum = 0;
    
    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant sum == \sum(0, i, \lambda integer k; \sum(k + 1, arr_len, \lambda integer l; arr[k] ^ arr[l]));
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, sum;
      loop variant arr_len - i;
    */
    for (int i = 0; i < arr_len; i++) {
        
        /*@
          loop invariant i + 1 <= j <= arr_len;
          loop invariant sum == \sum(0, i, \lambda integer k; \sum(k + 1, arr_len, \lambda integer l; arr[k] ^ arr[l]))
                                + \sum(i + 1, j, \lambda integer l; arr[i] ^ arr[l]);
          loop assigns j, sum;
          loop variant arr_len - j;
        */
        for (int j = i + 1; j < arr_len; j++) {
            sum += arr[i] ^ arr[j];
        }
    }
            
    return sum;
}
