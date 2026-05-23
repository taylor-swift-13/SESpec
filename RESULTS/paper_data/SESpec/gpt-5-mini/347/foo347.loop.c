
/*@
  logic integer divisors_prefix(integer x, integer m) =
    m <= 0 ? 0 : divisors_prefix(x, m-1) + ((x % m == 0) ? 1 : 0);
*/

/*@
  requires \at(y,Pre) >= 0;
*/
int foo347(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        
        /*@
          loop invariant 1 <= i && i <= y + 1;
          loop invariant 0 <= count && count <= i - 1;
          loop invariant count == divisors_prefix(x, i - 1);
          loop invariant (i <= \at(y,Pre)) ==> (count >= 0);
          loop invariant (!(i <= \at(y,Pre))) ==> ((count == divisors_prefix(x, \at(y,Pre))) && (y == \at(y,Pre)) && (x == \at(x,Pre)));
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop assigns i, count;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
            
        return count;
}
