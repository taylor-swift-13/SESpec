
#include <stdlib.h>

/*@
  logic integer fib_like_A(integer i) =
    i == 0 ? 1 :
    i == 1 ? 0 :
    fib_like_A(i-2) + 2 * fib_like_B(i-1);

  logic integer fib_like_B(integer i) =
    i == 0 ? 0 :
    i == 1 ? 1 :
    fib_like_A(i-1) + fib_like_B(i-2);
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
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= n+1;
          loop invariant \valid(A + (0..A_len-1));
          loop invariant \valid(B + (0..B_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> A[k] == fib_like_A(k);
          loop invariant \forall integer k; 0 <= k < i ==> B[k] == fib_like_B(k);
          loop assigns i, A[..], B[..];
            */
            for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
            
        return A[n];
}
