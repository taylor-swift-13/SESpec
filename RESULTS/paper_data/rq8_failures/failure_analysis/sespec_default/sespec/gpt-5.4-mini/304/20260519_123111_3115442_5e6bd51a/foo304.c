
/*@
  requires n >= 0;
  assigns \nothing;
  
*/
int foo304(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        
            
        /*@
          loop invariant \forall integer k; 2 <= k < i ==> pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000;
          loop assigns i, pell[0..n];
        */
            for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
            
        return pell[n];
}
