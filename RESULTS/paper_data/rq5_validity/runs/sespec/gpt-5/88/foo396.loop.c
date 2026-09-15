
/*@
  logic integer sum_pow4(integer n) =
    (n <= 0) ? 0 : n*n*n*n + sum_pow4(n-1);
*/

void foo396(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant 0 <= c;
      loop invariant 0 <= y;
      loop invariant y == c;
      loop invariant x == sum_pow4(y);
      loop invariant (0 < \at(k,Pre)) ==> (sum_pow4(y) == x);
      loop invariant (0 < \at(k,Pre)) ==> (y == c && 0 <= y && y <= k);
      loop invariant (0 < \at(k,Pre)) ==> (x == sum_pow4(c));
      loop invariant (0 < \at(k,Pre)) ==> (c >= 0 && c <= k);
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;
    */
    while(c < k){
      c = c +1 ;
      y = y +1;
      x = y*y*y*y+x;
    }
}
