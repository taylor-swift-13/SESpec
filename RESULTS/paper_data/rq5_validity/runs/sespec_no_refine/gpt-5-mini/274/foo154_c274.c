
/*@ 
  logic integer sum_even_evenpos(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_evenpos(arr, lo, hi - 1)
               + (( (hi-1) % 2 == 0 && arr[hi-1] % 2 == 0) ? arr[hi-1] : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires 0 <= n <= arr_len;
  assigns \nothing;   
  ensures \result == sum_even_evenpos(arr, 0, n); 
*/
int foo154_c274(int * arr, int arr_len, int n) {

    int count = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant (i <= \at(n,Pre)) ==> (count == sum_even_evenpos(arr, 0, i));
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre) ;
      loop assigns i, count;
    */
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] % 2 == 0) {
                count += arr[i];
            }
        }
    }
        
    return count;
}
