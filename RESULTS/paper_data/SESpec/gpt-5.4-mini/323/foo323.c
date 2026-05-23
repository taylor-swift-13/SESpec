
/*@
  assigns \nothing;
  ensures n == 1 ==> \result == 1;
  ensures n != 1 && n < 4 ==> \result >= 0;
  ensures n > 1 && (\forall integer d; 2 <= d <= n / 2 ==> n % d != 0) ==> \result >= 0;
  ensures n > 1 && (\exists integer d; 2 <= d <= n / 2 && n % d == 0) ==> \result >= 0;
  ensures \result >= 0;
*/
int foo323(int n) {

        int count = 0;
        if (n == 1) return 1;
        
        /*@
          loop invariant 2 <= i;
          loop invariant count >= 0;
          loop invariant count <= i - 2;
          loop invariant i >= 2;
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
