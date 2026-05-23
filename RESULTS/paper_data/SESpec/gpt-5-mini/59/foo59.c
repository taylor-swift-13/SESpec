
#include <stdbool.h>

int unknown();

/*@
  predicate undef_data_at(unsigned int *p) = \true;
*/

/*@
  predicate mod3_relation(unsigned int x, unsigned int y) =
    (y == 0 && x % 3 == 0) ||
    (y == 1 && x % 3 == 1) ||
    (y == 2 && x % 3 == 2);
*/

void foo59() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
      loop invariant 0 <= y <= 2;
      loop invariant  (y == 0 || y == 1) ;
      loop invariant  ((y == 1)) || (y == 0 || y == 2) ;
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
