
/*@
*/
        


/*@
  assigns \nothing;
  ensures \true;
*/
int foo184(int n) {

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
int sumOfPrimeDivisors_len = n + 1;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant \forall integer k; 0 <= k < 2 ==> sumOfPrimeDivisors[k] == 0;
          loop invariant \forall integer k; 2 <= k < i ==> sumOfPrimeDivisors[k] >= 0;
          loop invariant \forall integer k; i <= k <= n ==> sumOfPrimeDivisors[k] >= 0;
          loop assigns i, j, sumOfPrimeDivisors[..];
            */
            for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 2 && i <= n;
          loop invariant j >= i && j <= n + 1;
          loop invariant (j - i) % i == 0;
          loop invariant \forall integer k; i <= k < j && (k - i) % i == 0 ==> sumOfPrimeDivisors[k] >= i;
          loop assigns sumOfPrimeDivisors[..], j;
            */
            for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            
            }
        }
            

        return sumOfPrimeDivisors[n];
}
