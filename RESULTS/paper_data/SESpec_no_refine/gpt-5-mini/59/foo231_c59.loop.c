
/*@
  predicate mod3_zero(unsigned int x, unsigned int y) =
    (y == 1 <==> x % 3 == 0);
*/

int unknown();

void foo231_c59() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
      loop invariant (y == 1) || (y == 0);
      loop assigns x, y;
    */
    while(unknown()){
       if(x % 3 == 1){
         x = x + 2;
         y = 0;
       }
       else{
         if(x % 3 == 2){
           x = x + 1;
           y = 0;
         }
         else{
           if(unknown()){
             x = x + 4;
             y = 1;
           }
           else{
             x = x + 5;
             y = 1;
           }
         }
       }
    }

}
