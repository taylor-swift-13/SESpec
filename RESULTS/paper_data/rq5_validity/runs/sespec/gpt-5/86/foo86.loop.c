


void foo86(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant 0 <= x;
      loop invariant y == c;
      loop invariant x >= c;
      loop invariant x >= y;
      loop invariant c == 0 ==> x == 0;
      loop invariant c == 0 ==> y == 0;
      loop invariant c > 0 ==> x >= c*c;
      loop invariant c > 0 ==> y > 0;
      loop invariant c == \at(k,Pre) ==> !(c < \at(k,Pre));
      loop invariant (0 < \at(k,Pre)) ==> (c <= \at(k,Pre));
      loop invariant (0 < \at(k,Pre)) ==> (c <= y <= \at(k,Pre));
      loop invariant (0 < \at(k,Pre)) ==> (x >= c && x >= y);
      loop invariant (0 < \at(k,Pre)) ==> (c < \at(k,Pre) ==> y < \at(k,Pre));
      loop invariant (0 < \at(k,Pre)) ==> (c < \at(k,Pre) ==> x < (\at(k,Pre)+1)*(\at(k,Pre)+1) + x);
      loop invariant (0 < \at(k,Pre)) ==> (y == c) ;
      loop invariant (0 < \at(k,Pre)) ==> (0 <= x) ;
      loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre)) ;
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
