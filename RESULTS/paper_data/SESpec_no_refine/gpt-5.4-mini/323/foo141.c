
/*@
  ensures \result == 1;
  assigns \nothing;
*/
int foo141(int n) {

        int count = 0;
        if (n == 1) return 1;
        
        /*@
          loop invariant 2 <= i;
          loop invariant i <= n / i + 1;
          loop invariant count >= 0;
          loop assigns i, count;
        */
            /*@
          loop invariant (!(i <= n / i)) ==> ();
          loop assigns i, count;
            */
            for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
            
        return count;
}
