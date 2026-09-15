
/*@ 
  logic integer divs_seen(integer n, integer i) =
    i <= 0 ? 0 :
    divs_seen(n, i-1) + ((n % i == 0) ? 1 : 0);
*/

/*@
  requires n == \at(n,Pre);
  requires n >= 0;
  assigns \nothing;   
  ensures divs_seen(n,n) == \result; 
  ensures \result == divs_seen(n,n);  
*/
int foo383(int n) {

        int count = 0;
        
            
        /*@
          loop invariant 1 <= i && i <= \at(n,Pre) + 1;
          loop invariant 0 <= count && count <= i-1;
          loop invariant count == divs_seen(n, i-1);
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
