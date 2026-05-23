
/*@ 
  logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n-1) + n*n*n*n;
*/


void foo88(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant (0 < \at(k,Pre)) ==> (x == sum4(c) && y == c && 0 <= c && c <= k);
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (x == sum4(c));
      loop invariant (0 < \at(k,Pre)) ==> (c == c); 
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
