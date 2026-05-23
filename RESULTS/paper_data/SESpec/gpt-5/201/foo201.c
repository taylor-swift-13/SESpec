
#include <stdlib.h>

/*@
  requires n >= 1;
  ensures \true;
*/
int foo201(int n) {

    int *A = (int *)malloc(sizeof(int) * (n+1));
    int A_len = n+1;
    int *B = (int *)malloc(sizeof(int) * (n+1));
    int B_len = n+1;
    A[0] = 1;
    A[1] = 0;
    B[0] = 0;
    B[1] = 1;
        
    /*@
      loop invariant 2 <= i <= n + 1;
      loop invariant A_len == n + 1;
      loop invariant B_len == n + 1;
      loop invariant 0 <= n;
      loop invariant \forall integer k; 2 <= k < i ==> (0 <= k && k < A_len && 0 <= k && k < B_len);
      loop invariant (i <= n) ==> (0 <= i-2 && i-2 < A_len && 0 <= i-1 && i-1 < A_len &&
                                   0 <= i-2 && i-2 < B_len && 0 <= i-1 && i-1 < B_len);
      loop assigns i, A[0..n], B[0..n];
    */
    for(int i = 2; i <= n; i++) {
        A[i] = A[i-2] + 2 * B[i-1];
        B[i] = A[i-1] + B[i-2];
    }
        
    return A[n];
}
