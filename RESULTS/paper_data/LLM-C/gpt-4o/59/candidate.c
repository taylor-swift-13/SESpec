int unknown();

/*@
    assigns x, y;
    ensures \true; // No specific postcondition can be derived due to the unknown() function.
*/
void foo243() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
        loop invariant y == 0 || y == 1;
        loop assigns x, y;
        loop variant unknown(); // The loop variant cannot be precisely defined due to the unknown() function.
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
