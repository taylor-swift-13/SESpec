
/*@
  logic integer count_value(integer i) = i;
*/

int foo294(int n) {

        int count = 0;
        
            
        /*@
          loop invariant 0 <= count;
          loop invariant n == \at(n,Pre);
          loop invariant (i <= \at(n,Pre)) ==> (count <= i - 1);
          loop assigns i, count;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        return count;
}
