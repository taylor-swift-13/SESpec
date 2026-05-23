
/*@
  logic integer odd_sum(integer n) = n <= 0 ? 0 : odd_sum(n - 1) + (n % 2 != 0 ? n : 0);
  logic integer odd_count(integer n) = n <= 0 ? 0 : odd_count(n - 1) + (n % 2 != 0 ? 1 : 0);
*/

int foo263(int n) {

        int sum = 0;
        int count = 0;
        
            
        /*@
          loop invariant n == \at(n,Pre);
          loop assigns i, sum, count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
