
/*@ 
  logic integer square(integer n) = n * n;
  logic integer triangle(integer n) = n * (n + 1) / 2;
  logic integer cube_sum(integer n) = square(triangle(n)); 
*/


        
void foo87(int k){

    int y=0;
    int x=0;
    int c=0;

            
        /*@
          loop invariant (0 < \at(k,Pre)) ==> (c >= 0 && c <= \at(k,Pre));
          loop invariant (0 < \at(k,Pre)) ==> (y == c);
          
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
