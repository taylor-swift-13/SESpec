
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
          loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || A[k] == A[k]);
          loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || B[k] == B[k]);
          loop assigns i, A[0..n], B[0..n];
            */
            for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
            
        return A[n];
}
