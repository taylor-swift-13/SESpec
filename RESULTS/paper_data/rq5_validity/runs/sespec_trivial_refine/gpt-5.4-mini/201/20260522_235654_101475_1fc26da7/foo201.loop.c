
        /*@
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
          loop invariant \true;
          loop invariant 2 <= i <= n + 1;
          loop assigns i, A[2 .. n], B[2 .. n];
            */
            for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
            
        return A[n];
}
