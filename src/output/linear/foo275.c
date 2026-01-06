
/*@
    requires y > 0 || x > 0;
    */
    
void foo275(int x, int y) {

        /*@
          loop invariant (\at(x,Pre) + \at(y,Pre) <= -2) ==> (x >= \at(x,Pre) && y >= \at(y,Pre));
          loop invariant (\at(x,Pre) + \at(y,Pre) <= -2) ==> (x > 0 || y > 0);
          loop invariant (!(\at(x,Pre) + \at(y,Pre) <= -2)) ==> ((y == \at(y,Pre))&&(x == \at(x,Pre)));
          loop assigns x, y;
            */
            while (x + y <= -2) {
       if (x > 0) {
       x++;
      }
       else {
       y++;
      }
      }
            

    /*@ assert x > 0 || y > 0; */

  }
