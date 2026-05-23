
/*@
  requires n >= 1;
  assigns \nothing;
  ensures \result == A_seq(n);
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
          loop invariant 2 <= i <= n+1 || i == 2;
          loop invariant \forall integer k; 0 <= k < i ==> A[k] == A_seq(k);
          loop invariant \forall integer k; 0 <= k < i ==> B[k] == B_seq(k);
          loop assigns i, A[..], B[..];
            */
            for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
            
        return A[n];
}
