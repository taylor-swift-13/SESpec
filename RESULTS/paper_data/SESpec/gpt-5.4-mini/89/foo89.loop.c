
/*@
  logic integer pow5(integer v) = v * v * v * v * v;

  logic integer sum_pow5(integer n) =
    n <= 0 ? 0 : sum_pow5(n - 1) + pow5(n);
*/

void foo89(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant (0 < \at(k,Pre)) ==> (x == sum_pow5(c));
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (c <= k);
      loop invariant (0 < \at(k,Pre)) ==> (c >= 0);
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
