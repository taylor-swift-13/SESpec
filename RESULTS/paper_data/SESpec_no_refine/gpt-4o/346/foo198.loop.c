
/*@
  predicate is_prime_factor(integer n, integer k) = 
    (k > 1 && n % k == 0);
*/

/*@
  requires n > 0;
  ensures \result >= 0;
  ensures \forall integer k; k > 1 && k <= n ==> (n % k != 0 || \result >= k);
*/
int foo198(int n) {

    int max = 0;
    
    /*@
      loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || max >= k);
      loop assigns i, max, n;
    */
    for (int i = 2; i <= n; i++) {
        
        /*@
          loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || max >= k);
          loop assigns i, max, n;
        */
        while (n % i == 0) {
            max = i;
            n /= i;
        }
        
    }
            
    return max;
}
