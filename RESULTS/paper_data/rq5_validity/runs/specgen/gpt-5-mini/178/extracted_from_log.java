import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindKth {

    /*@ 
      @ requires arr1 != null && arr2 != null;
      @ requires 0 <= m && m <= arr1.length;
      @ requires 0 <= n && n <= arr2.length;
      @ requires 1 <= k && k <= m + n;
      @ // arrays are sorted in non-decreasing order
      @ requires (\forall int p; 0 <= p && p+1 < m; arr1[p] <= arr1[p+1]);
      @ requires (\forall int p; 0 <= p && p+1 < n; arr2[p] <= arr2[p+1]);
      @ 
      @ // The result is the k-th smallest element in the multiset union of arr1[0..m-1] and arr2[0..n-1].
      @ // We express this by saying there are strictly less than k elements strictly smaller than the result,
      @ // and there are at least k elements less than or equal to the result.
      @ ensures \result != -1;
      @ ensures (
      @    (\exists int p; 0 <= p && p < m;
      @        \result == arr1[p] &&
      @        (\num_of int u; 0 <= u && u < m; arr1[u] < \result)
      @        + (\num_of int v; 0 <= v && v < n; arr2[v] < \result) < k
      @        &&
      @        (\num_of int u; 0 <= u && u < m; arr1[u] <= \result)
      @        + (\num_of int v; 0 <= v && v < n; arr2[v] <= \result) >= k
      @    )
      @    ||
      @    (\exists int q; 0 <= q && q < n;
      @        \result == arr2[q] &&
      @        (\num_of int u; 0 <= u && u < m; arr1[u] < \result)
      @        + (\num_of int v; 0 <= v && v < n; arr2[v] < \result) < k
      @        &&
      @        (\num_of int u; 0 <= u && u < m; arr1[u] <= \result)
      @        + (\num_of int v; 0 <= v && v < n; arr2[v] <= \result) >= k
      @    )
      @ );
      @*/
    public static int findKth(int[] arr1, int[] arr2, int m, int n, int k) {
        int i = 0;
        int j = 0;

        /*@ 
          @ // loop invariants
          @ maintaining 0 <= i && i <= m;
          @ maintaining 0 <= j && j <= n;
          @ maintaining 0 <= (\lbl count; /* implicit count variable equals loop iteration count */ 0) ;
          @ // count is the number of elements taken so far; since we don't have an explicit count variable
          @ // in the invariant we assert the relation count == i + j conceptually. For the actual loop,
          @ // the following invariant captures that i+j equals the number of iterations executed so far:
          @ maintaining i + j <= k;
          @ // consumed elements (arr1[0..i-1] and arr2[0..j-1]) are each <= all remaining elements
          @ maintaining (\forall int p; 0 <= p && p < i; (\forall int r; i <= r && r < m; arr1[p] <= arr1[r]) && (\forall int s; j <= s && s < n; arr1[p] <= arr2[s]));
          @ maintaining (\forall int q; 0 <= q && q < j; (\forall int r; i <= r && r < m; arr2[q] <= arr1[r]) && (\forall int s; j <= s && s < n; arr2[q] <= arr2[s]));
          @ // the combined count of consumed elements equals i+j and decreases the remaining work
          @ decreasing k - (i + j);
          @*/
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
}