
/*@ 
  logic integer sumsq(integer n) = n <= 0 ? 0 : sumsq(n-1) + n * n;
*/

/* Require k non-negative so that invariants like 0 <= c <= k hold at loop entry. */
 /*@ requires k >= 0; */
void foo86(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant 0 <= c <= k;
      loop invariant 0 <= y;
      loop invariant 0 <= x;
      loop invariant y == c;
      loop invariant x == sumsq(c);
      loop invariant (c > 0) ==> (sumsq(c) == sumsq(c-1) + y * y);
      loop invariant (0 < \at(k,Pre)) ==> (c <= \at(k,Pre) && x == sumsq(c));
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (0 <= x);
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0) && (x == 0) && (y == 0) && (k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;
    */
    while(c < k){
      c = c + 1;
      y = y + 1;
      x = y * y + x;
    }
}
