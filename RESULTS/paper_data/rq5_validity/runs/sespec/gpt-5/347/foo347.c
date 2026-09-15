
/*@
  assigns \nothing;
  ensures y >= 0 ==> \result >= 0 && \result <= y;
  ensures y < 0 ==> \result >= 0 && \result <= -\at(y,Pre);
*/
int foo347(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        
        /*@
          loop invariant 1 <= i && i <= y + 1;
          loop invariant y >= 0;
          loop invariant y == (\at(y,Pre) >= 0 ? \at(y,Pre) : -\at(y,Pre));
          loop invariant x == \at(x,Pre);
          loop invariant \forall integer k; 1 <= k < i ==> k <= y;
          loop invariant 0 <= count;
          loop invariant count <= i - 1;
          loop invariant (count == 0) || (\exists integer k; 1 <= k < i && x % k == 0);
          loop assigns i, count;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
            
        return count;
}
