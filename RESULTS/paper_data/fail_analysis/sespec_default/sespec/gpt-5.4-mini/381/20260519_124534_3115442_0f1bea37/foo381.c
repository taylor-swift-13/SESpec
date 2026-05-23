






/*@ logic integer gcd_count(integer x, integer y, integer i) =
      i <= 0 ? 0 :
      gcd_count(x, y, i - 1) + ((x % i == 0 && y % i == 0) ? 1 : 0); */
/*@
  requires x >= 0;
  requires y >= 0;
  assigns \nothing;
  ensures \true;
*/
int foo381(int x, int y) {

        int count = 0;
        
            
        /*@
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
