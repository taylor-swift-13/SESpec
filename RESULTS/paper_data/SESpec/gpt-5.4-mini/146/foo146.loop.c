
int foo146(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant 1 <= n;
          loop invariant n % 4 == 0 ==> n % 2 == 0;
          loop invariant n % 4 == 0 ==> n > 0;
          loop invariant n >= 1;
          loop invariant n % 4 == 0 || n % 4 == 1 || n % 4 == 2 || n % 4 == 3;
          loop invariant (n % 4 == 0) ==> (n == 4 * (n / 4));
          loop invariant (n % 4 == 0) ==> (n % 2 == 0);
          loop assigns n;
        */
        while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
