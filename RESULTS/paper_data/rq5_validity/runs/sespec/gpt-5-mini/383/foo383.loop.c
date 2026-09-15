
/*@ 
  logic integer divs_seen(integer n, integer i) =
    i <= 0 ? 0 :
    divs_seen(n, i-1) + ((n % i == 0) ? 1 : 0);
*/

/*@
  
  requires n == \at(n,Pre);
*/
int foo383(int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i <= \at(n,Pre)) ==> (0 <= count && count <= i);
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
