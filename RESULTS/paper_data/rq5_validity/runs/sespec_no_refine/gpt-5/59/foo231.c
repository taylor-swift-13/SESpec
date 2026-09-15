
#include <limits.h>

int unknown();

/*@ 
    predicate undef_data_at{L}(unsigned int *p) = \true; 
*/

/*@
  logic integer imod3(integer v) = v - 3 * (v / 3);
*/

/*@
  requires \true;
*/
void foo231() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
      loop invariant y == 0 || y == 1;
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
