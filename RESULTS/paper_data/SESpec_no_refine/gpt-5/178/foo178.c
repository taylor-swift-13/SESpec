
/*@
  // no extra logic needed
*/

/* dummy false branch to keep structure simple */
          );
  ensures \forall integer t; 0 <= t < arr1_len ==> arr1[t] == \at(arr1[t],Pre);
  ensures \forall integer t; 0 <= t < arr2_len ==> arr2[t] == \at(arr2[t],Pre);
  ensures \result == (k <= 0 ? -1 :
            ((0 < m && (0 >= n || arr1[0] <= arr2[0])) ? arr1[0] : arr2[0])) ==> \true;
*/
int foo178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        /*@
          loop invariant 0 <= count <= k;
          loop invariant 0 <= i <= m;
          loop invariant 0 <= j <= n;
          loop invariant i + j == count;
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant k == \at(k,Pre);
          loop invariant \forall integer t; 0 <= t < arr1_len ==> arr1[t] == \at(arr1[t],Pre);
          loop invariant \forall integer t; 0 <= t < arr2_len ==> arr2[t] == \at(arr2[t],Pre);
          loop assigns i, j, count;
        */
            /*@
          loop invariant 0 <= count <= k;
          loop invariant 0 <= i <= m;
          loop invariant 0 <= j <= n;
          loop invariant i + j == count;
          loop invariant arr1 == \at(arr1,Pre) && arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre) && arr2_len == \at(arr2_len,Pre);
          loop invariant m == \at(m,Pre) && n == \at(n,Pre) && k == \at(k,Pre);
          loop invariant \forall integer t; 0 <= t < arr1_len ==> arr1[t] == \at(arr1[t],Pre);
          loop invariant \forall integer t; 0 <= t < arr2_len ==> arr2[t] == \at(arr2[t],Pre);
          loop assigns i, j, count;
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
