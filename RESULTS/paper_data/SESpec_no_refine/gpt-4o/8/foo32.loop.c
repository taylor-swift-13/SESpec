
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \at(arr1_len,Pre) > 0 && \at(arr1_len,Pre) < 100;
  requires \at(arr2_len,Pre) > 0 && \at(arr2_len,Pre) < 100;
  requires \valid(arr1 + (0 .. arr1_len - 1));
  requires \valid(arr2 + (0 .. arr2_len - 1));
  ensures \result == -1 || (\exists integer idx; 0 <= idx < k && \result == arr1[idx]) || (\exists integer idx; 0 <= idx < k && \result == arr2[idx]);
*/
int foo32(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        /*@
          loop invariant (count < \at(k,Pre)) ==> (i + j == count);
          loop invariant (!(count < \at(k,Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k,Pre))&&(n == \at(n,Pre))&&(m == \at(m,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop assigns count, i, j;
        */
        for (int count = 0; count < k; count++) {
            if (i < m && (j >= n || arr1[i] <= arr2[j])) {
                if (count == k - 1) {
                    return arr1[i];
                }
                i++;
            } else {
                if (count == k - 1) {
                    return arr2[j];
                }
                j++;
            }
        }
            
        return -1;
}
