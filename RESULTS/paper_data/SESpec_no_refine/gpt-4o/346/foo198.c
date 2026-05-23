
/*@
  predicate is_prime_factor(integer n, integer k) = 
    (k > 1 && n % k == 0);
*/

/*@
  requires n > 0;
  assigns \nothing;
*/
int foo198(int n) {

    int max = 0;
    
    /*@
      loop assigns i, max, n;
      loop variant n;
    */
    for (int i = 2; i <= n; i++) {
        
        /*@
          loop assigns max, n;
          loop variant n;
        */
        while (n % i == 0) {
            max = i;
            n /= i;
        }
        
    }
            
    return max;
}
