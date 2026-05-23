
/*@
  predicate foo86_y(integer kpre, integer c, integer y) = y == c;
  predicate foo86_x(integer kpre, integer c, integer x) = x == c * (c + 1) * (2 * c + 1) / 6;
  predicate foo86_c(integer kpre, integer c) = c >= 0;
  predicate foo86_goal(integer kpre, integer c, integer x, integer y) = x >= y * y;
*/

void foo86(int k){

    int y=0;
    int x=0;
    int c=0;

    
            
        /*@
          loop invariant (0 < \at(k,Pre)) ==> (foo86_goal(\at(k,Pre), c, x, y));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_y(\at(k,Pre), c, y));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_x(\at(k,Pre), c, x));
          loop invariant (0 < \at(k,Pre)) ==> (foo86_c(\at(k,Pre), c));
          loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns c, y, x;
        */
        while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }
            
}
