
/*@
  assigns \nothing;
  ensures \result ==
            binom(\old(n),
                  (\old(k) > \old(n) - \old(k)) ? (\old(n) - \old(k)) : \old(k));
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
