#include <stdlib.h>

/*@ axiomatic Recurrence {
  logic integer A_logic(integer n);
  logic integer B_logic(integer n);

  axiom A_init0: A_logic(0) == 1;
  axiom A_init1: A_logic(1) == 0;
  axiom B_init0: B_logic(0) == 0;
  axiom B_init1: B_logic(1) == 1;

  axiom A_rec: \forall integer k; k >= 2 ==> A_logic(k) == A_logic(k-2) + 2 * B_logic(k-1);
  axiom B_rec: \forall integer k; k >= 2 ==> B_logic(k) == A_logic(k-1) + B_logic(k-2);
} */

int countWays(int n);

/*@ 
  requires n >= 1;
  ensures \result == A_logic(n);
*/
int countWays(int n) {

        int *A = (int *)malloc(sizeof(int) * (n+1));
/*@ assert A != \null; */
/*@ assert \valid(A + (0..n)); */
int A_len = n+1;
        int *B = (int *)malloc(sizeof(int) * (n+1));
/*@ assert B != \null; */
/*@ assert \valid(B + (0..n)); */
int B_len = n+1;
        A[0] = 1;
        A[1] = 0;
        B[0] = 0;
        B[1] = 1;
/*@ assert A[0] == A_logic(0) && A[1] == A_logic(1); */
/*@ assert B[0] == B_logic(0) && B[1] == B_logic(1); */
/*@ 
  loop invariant 2 <= i <= n + 1;
  loop invariant \valid(A + (0..n)) && \valid(B + (0..n));
  loop invariant A[0] == A_logic(0) && A[1] == A_logic(1);
  loop invariant B[0] == B_logic(0) && B[1] == B_logic(1);
  loop invariant \forall integer k; 0 <= k < i ==> A[k] == A_logic(k) && B[k] == B_logic(k);
  loop invariant \forall integer k; 2 <= k < i ==> (A[k] == A[k-2] + 2 * B[k-1] && B[k] == A[k-1] + B[k-2]);
  loop assigns i, A[2..n], B[2..n];
  loop variant n - i + 1;
*/
        for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
/*@ assert \forall integer k; 0 <= k <= n ==> A[k] == A_logic(k) && B[k] == B_logic(k); */
        return A[n];
}
