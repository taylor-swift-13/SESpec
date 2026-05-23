
/*@
  // Count equal pairs between positions of two pointers that have moved
  // from (0,1) to (i,j) following the scan rules in the loop: pointers
  // start at p=0,q=1 and at each step either both advance (when arr[p]==arr[q]),
  // or one of them advances depending on comparison.
  //
  // We capture the number of times arr[p]==arr[q] would have been true
  // along the executed sequence by modeling the unique sequence of visited
  // index pairs. For simplicity we define eqcount_prefix(arr, n, i, j)
  // as the number of k from 0..t-1 such that in the k-th comparison the
  // compared pair had equal elements, where t is the number of comparisons
  // needed to reach pointers (i,j) from (0,1) under the deterministic rules.
  //
  // The following recursive definition mirrors the step behavior:
  logic integer eqcount_prefix(int *arr, integer n, integer i, integer j) =
    // base: at starting state (0,1) there have been 0 comparisons
    (i == 0 && j == 1) ? 0
    // if j <= i then invalid state for our scan; treat as 0 (won't be used)
    : j <= i ? 0
    // otherwise, the predecessor state depends on how (i,j) were reached:
    : (
        // predecessor was (i-1,j-1) because last step both advanced (equal case)
        (i > 0 && j > 0 && arr[i-1] == arr[j-1] && eqcount_prefix(arr,n,i-1,j-1) >= 0 && (i-1 >= 0) && (j-1 > (i-1))) ? eqcount_prefix(arr,n,i-1,j-1) + 1
        // predecessor was (i-1,j) because last step advanced i (arr[i-1] > arr[j])
        : (i > 0 && j > 0 && arr[i-1] > arr[j-1] && eqcount_prefix(arr,n,i-1,j) >= 0 && (i-1 >= 0) && j > (i-1)) ? eqcount_prefix(arr,n,i-1,j)
        // predecessor was (i,j-1) because last step advanced j (arr[i] < arr[j-1])
        : (i >= 0 && j > 1 && arr[i] < arr[j-1] && eqcount_prefix(arr,n,i,j-1) >= 0 && j-1 > i) ? eqcount_prefix(arr,n,i,j-1)
        // fallback (should not occur for reachable states)
        : 0
      );
*/

/*@
  requires \valid(arr + (0 .. arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires n == \at(n,Pre);
  requires arr_len == \at(arr_len,Pre);
  requires arr == \at(arr,Pre);
*/
int foo70_c211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        
            
        /*@
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (1 <= j && j <= n);
          loop invariant (!(0 < \at(n,Pre) && 1 < \at(n,Pre))) ==> ((j == 1)&&(i == 0)&&(count == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid(arr + (0 .. arr_len-1));
          loop assigns i, j, count;
        */
            while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }
            

        return count;
}
