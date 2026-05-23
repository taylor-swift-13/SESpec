
/*@
  logic integer divcount(integer n, integer lo, integer hi) =
    lo > hi ? 0 :
    divcount(n, lo, hi - 1) + (n % hi == 0 ? 1 : 0);
*/

const char * foo285(int n) {

        int count = 0;
        
        /*@
          loop invariant n == \at(n,Pre);
          loop invariant 0 <= count <= i - 1;
          loop invariant count == divcount(n, 1, i - 1);
          loop assigns i, count;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}
