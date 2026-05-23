
/*@
  logic integer prefix_sorted(int* arr, integer lo, integer hi) =
    hi - lo <= 1 ? 1 :
    (prefix_sorted(arr, lo, hi - 1) && arr[hi - 2] <= arr[hi - 1]);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (\old(arr_len) < 2 && \result == 1) || (\old(arr_len) >= 2 && (\result == 0 || \result == 1));
  ensures \result == 0 ==> (\exists integer i; 0 <= i < \old(arr_len) - 1 && \old(arr[i]) > \old(arr[i+1]));
  ensures \result == 1 ==> (\forall integer i; 0 <= i < \old(arr_len) - 1 ==> \old(arr[i]) <= \old(arr[i+1]));
*/
int foo42(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(i < n)) ==> ();
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
