/*@ 
  logic integer count_divs(integer x, integer n) =
    n <= 0 ? 0 : count_divs(x, n-1) + ((x % n) == 0 ? 1 : 0);
*/

int findDivisor(int x, int y);

 /*@ 
   requires y != -2147483647 - 1;
   assigns \nothing;
   ensures \result == count_divs(x, \abs(\old(y)));
   ensures 0 <= \result <= \abs(\old(y));
 */
int findDivisor(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        /*@ 
          loop invariant y >= 0;
          loop invariant 1 <= i <= y + 1;
          loop invariant 0 <= count <= i - 1;
          loop invariant count == count_divs(x, i - 1);
          loop assigns count, i;
          loop variant y - i + 1;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}
