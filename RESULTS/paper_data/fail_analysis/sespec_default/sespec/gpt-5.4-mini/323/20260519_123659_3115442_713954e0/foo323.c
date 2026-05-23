

/*@
  ensures n == 1 ==> \result == 1;
  ensures n != 1 ==> \result >= 0;
  assigns \nothing;
*/
int foo323(int n) {

        int count = 0;
        if (n == 1) return 1;
        
        /*@
          loop invariant 2 <= i;
          loop invariant count >= 0;
          loop invariant count <= i - 2;
          loop invariant (i <= n / i) ==> (count <= n);
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
