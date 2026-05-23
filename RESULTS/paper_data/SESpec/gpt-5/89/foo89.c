
/*@ 
  logic integer pow5(integer t) = t * t * t * t * t;
*/

/*@ 
  logic integer sum5(integer n) = 
    n <= 0 ? 0 : sum5(n - 1) + pow5(n);
*/

void foo89(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant (0 <= \at(k,Pre)) ==> (0 <= c <= \at(k,Pre));
      loop invariant 0 <= y;
      loop invariant y == c;
      loop invariant x == sum5(c);
      loop invariant \forall integer t; 1 <= t <= c ==> pow5(t) >= 0;
      loop invariant c == 0 ==> x == 0;
      loop invariant (0 <= \at(k,Pre)) ==> (c < \at(k,Pre) ==> y < \at(k,Pre));
      loop invariant (0 <= \at(k,Pre)) ==> (y <= \at(k,Pre));
      loop invariant x >= 0;
      loop invariant (0 <= \at(k,Pre)) ==> (c == \at(k,Pre) ==> (y == \at(k,Pre) && x == sum5(\at(k,Pre))));
      loop invariant (0 < \at(k,Pre)) ==> (x == sum5(c));
      loop invariant (0 < \at(k,Pre)) ==> (0 <= y <= \at(k,Pre) && y == c) ;
      loop invariant (0 < \at(k,Pre)) ==> (0 <= x && x <= sum5(c)) ;
      loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre)) ;
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;
    */
    while(c < k){
      c = c + 1 ;
      y = y + 1;
      x=y*y*y*y*y+x;
    }
}
