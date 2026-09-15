
/*@
  requires \true;
  assigns \nothing;
*/
int foo346(int n) {

        int max = 0;
        
        /*@
          loop invariant 2 <= i;
          loop invariant 0 <= max;
          loop invariant n <= \at(n,Pre);
          loop assigns i, max, n;
        */
        for (int i = 2; i <= n; i++) {
        
            /*@
              loop invariant 2 <= i;
              loop invariant 0 <= max;
              loop invariant n <= \at(n,Pre);
              
              loop assigns max, n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
            
        return max;
}
