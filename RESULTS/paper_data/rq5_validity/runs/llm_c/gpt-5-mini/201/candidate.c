#include <stdlib.h>
#include <limits.h>

/*@
    logic integer A_seq(integer i) =
        (i == 0 ? 1 :
         i == 1 ? 0 :
         A_seq(i-2) + 2 * B_seq(i-1));
    logic integer B_seq(integer i) =
        (i == 0 ? 0 :
         i == 1 ? 1 :
         A_seq(i-1) + B_seq(i-2));
*/

/*@
    requires n >= 1;
    requires n <= INT_MAX/2; // avoid overflow in allocation size computation
    assigns \nothing; // does not modify caller-visible memory (allocates and uses internal heap)
    ensures \result == A_seq(n);
*/
int countWays(int n);

int countWays(int n) {

        int *A = (int *)malloc(sizeof(int) * (n+1));
int A_len = n+1;
        int *B = (int *)malloc(sizeof(int) * (n+1));
int B_len = n+1;
        A[0] = 1;
        A[1] = 0;
        B[0] = 0;
        B[1] = 1;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant \forall integer j; 0 <= j < i ==> A[j] == A_seq(j) && B[j] == B_seq(j);
            loop assigns i, A[0..n], B[0..n];
            loop variant n - i + 1;
        */
        for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
        return A[n];
}
