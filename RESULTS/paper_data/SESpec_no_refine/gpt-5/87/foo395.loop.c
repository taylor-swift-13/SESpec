
/*@
  // closed form for sum_{i=1..n} i^3
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : (n * n * (n + 1) * (n + 1)) / 4;
*/

void foo395(int k){

    int y=0;
    int x=0;
    int c=0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(k,Pre)) ==> (0 <= c && c <= \at(k,Pre) && y == c && x == sum_cubes(y));
          loop invariant (0 < \at(k,Pre)) ==> (0 <= y && y <= \at(k,Pre));
          loop invariant (0 < \at(k,Pre)) ==> (x == (y * y * (y + 1) * (y + 1)) / 4 && x >= 0);
          loop invariant (0 < \at(k,Pre)) ==> (0 <= c && c == y);
          loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0)&&(x == 0)&&(y == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns c, y, x;
            */
            while(c < k){
     c = c +1 ;
     y = y +1;
     x=y*y*y+x;
    }
            

}
