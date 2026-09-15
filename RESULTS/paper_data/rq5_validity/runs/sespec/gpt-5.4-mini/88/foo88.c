
/*@
  logic integer fourth_sum(integer n) =
    n <= 0 ? 0 : fourth_sum(n - 1) + n * n * n * n;
*/

        

        
void foo88(int k){

    int y=0;
    int x=0;
    int c=0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant c == y;
          loop invariant x == fourth_sum(c);
          loop invariant (0 < \at(k,Pre)) ==> (c <= \at(k,Pre));

          loop invariant (0 < \at(k,Pre)) ==> (x == fourth_sum(c) && c == y && 0 <= c <= \at(k,Pre));
          loop invariant (0 < \at(k,Pre)) ==> (c == y);
          loop invariant (0 < \at(k,Pre)) ==> (x == fourth_sum(c));
          loop invariant (0 < \at(k,Pre)) ==> (0 <= c <= \at(k,Pre));
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
