
/*@ 
  logic integer divcnt(integer n, integer a, integer b) =
    a > b ? 0 :
    (n % a == 0 ? 1 : 0) + divcnt(n, a + 1, b);
*/

/*@
  assigns \nothing;
  ensures n == \old(n);
  ensures \result != \null;
  ensures \result == \null ==> \false;
*/
const char * foo285(int n) {

        int count = 0;
        
        /*@
          loop invariant n == \at(n,Pre);
          loop invariant (i == 1) || (1 <= i <= n + 1);
          loop invariant 0 <= count <= (i - 1);
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
