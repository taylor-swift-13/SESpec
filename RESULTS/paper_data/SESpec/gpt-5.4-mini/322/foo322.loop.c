
int foo322(int x, int y) {

        int gcd = 1;
        int foo322 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        
            
        /*@
          loop invariant 1 <= i;
          loop invariant (i <= x + 1) || (x < 0);
          loop invariant gcd >= 1;
          loop invariant gcd <= i;
          loop invariant foo322 == 1;
          loop invariant gcd == 1 || (x % gcd == 0 && y % gcd == 0);
          loop invariant \forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd;
          loop invariant gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k);
          loop assigns i, gcd;
            */
            for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
            
        foo322 = (x * y) / gcd;
        return foo322;
}
