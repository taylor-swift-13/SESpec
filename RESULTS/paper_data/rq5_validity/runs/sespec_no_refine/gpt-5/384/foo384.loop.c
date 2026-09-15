
/*@
  logic integer binom(integer n, integer k) =
    (k <= 0 ? 1 :
     k > n ? 0 :
     (k > 0 && k <= n ?
        // iterative definition via recurrence: C(n,i) = C(n,i-1) * (n - i + 1) / i
        // Here we define it recursively to match the loop update.
        // Base: C(n,0) = 1
        // Step: C(n,i) = C(n,i-1) * (n - i + 1) / i
        // This logic function will be used with i as the second argument.
        // For general k, it unfolds k times.
        (k == 1 ? n :
         (binom(n, k - 1) * (n - k + 1)) / k)
     : 0));
*/

int foo384(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        
            
        /*@
          loop invariant 1 <= i <= k ==> i <= \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns i, c;
        */
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
            
        return c;
}
