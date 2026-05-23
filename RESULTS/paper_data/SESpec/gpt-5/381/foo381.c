
/*@
  assigns \nothing;
    ensures \result >= 0;
  ensures x == \old(x) && y == \old(y);
*/
int foo381(int x, int y) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i <= \at(x,Pre) && i <= \at(y,Pre)) ==> (i >= 1);
          loop invariant (i <= \at(x,Pre) && i <= \at(y,Pre)) ==> (i <= \at(x,Pre) && i <= \at(y,Pre));
          loop invariant 0 <= count;
          loop invariant (i <= \at(x,Pre) && i <= \at(y,Pre)) ==> (count <= i - 1);
          loop invariant \forall integer k; 1 <= k < i ==> ((\at(x,Pre) % k == 0 && \at(y,Pre) % k == 0) ==> count >= 1 || i == 1);
          loop invariant \forall integer k; 1 <= k < i ==> ((\at(x,Pre) % k != 0 || \at(y,Pre) % k != 0) || count <= i - 1);
          loop invariant \forall integer k; 1 <= k < i && (\at(x,Pre) % k == 0 && \at(y,Pre) % k == 0) ==> 1 <= count;
          loop invariant (i == 1) ==> (count == 0);
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
