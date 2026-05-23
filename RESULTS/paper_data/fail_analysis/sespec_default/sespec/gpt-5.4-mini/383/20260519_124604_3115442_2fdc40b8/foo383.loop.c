
/*@ predicate is_divisor(integer n, integer i) = i != 0 && n % i == 0; */
        
int foo383(int n) {

        int count = 0;
        
            
        /*@
          loop invariant 1 <= i;
          loop invariant count >= 0;
          loop invariant n == \at(n,Pre);
          loop assigns i, count;
        */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        return count;
}
