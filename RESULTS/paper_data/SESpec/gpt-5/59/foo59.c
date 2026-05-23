
#include <limits.h>

int unknown();

/*@ 
  requires \true;
*/
void foo59() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
      loop invariant 0u <= y <= 1u;
      loop invariant y == 1 || y == 0;
      loop invariant x % 3 == 0 || x % 3 == 1 || x % 3 == 2;
      loop invariant x >= 0u;
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
