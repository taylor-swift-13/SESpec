
/*@ 
  logic integer sum5(integer n) =
    n <= 0 ? 0 : sum5(n - 1) + n*n*n*n*n;
*/

void foo89(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant 0 <= c;
      loop invariant (k < 0) || (c <= k);
      loop invariant 0 <= y <= (k < 0 ? 0 : k);
      loop invariant 0 <= x;
      loop invariant (y == c);
      loop invariant x == sum5(y);
      loop invariant x * 12 == (y*y) * ((y + 1)*(y + 1)) * (2*y*y + 2*y - 1) ==> (y >= 0);
      loop invariant (0 < \at(k,Pre)) ==> (c <= \at(k,Pre));
      loop invariant (0 < \at(k,Pre)) ==> (y <= \at(k,Pre));
      loop invariant (0 < \at(k,Pre)) ==> (x >= 0);
      loop invariant (0 < \at(k,Pre)) ==> (c == y);
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
