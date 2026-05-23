
/*@
  logic integer pell_seq(integer i) =
    i == 0 ? 0 :
    i == 1 ? 1 :
    (2 * pell_seq(i - 1) + pell_seq(i - 2)) % 1000000000;
*/

int foo304(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i, pell[0..n];
            */
            for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
            
        return pell[n];
}
