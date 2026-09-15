
/*@ 
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == 0 || divisible_common(\old(x), \old(y), 1);
  ensures \result <= (\old(x) < \old(y) ? \old(x) : \old(y));
*/
int foo290(int x, int y) {

        int count = 0;
        
            
        /*@
          loop invariant count >= 0;
          loop invariant count <= i - 1;
          loop invariant (i <= \at(x,Pre) && i <= \at(y,Pre)) ==> (count == 0 || count <= i - 1);
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop assigns i, count;
            */
            for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
            
        return count;
}
