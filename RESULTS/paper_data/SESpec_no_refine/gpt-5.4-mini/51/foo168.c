
/*@
  logic integer pow10(integer n) =
    n <= 0 ? 1 : 10 * pow10(n - 1);
*/

void foo168() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

    /*@
      loop invariant z == 10 * w;
      loop assigns x, y, w, z;
    */
    while(unknown()){
       if(x >= 4){
       x = x + 1;
       y = y + 2;

      }
       else if(y > 10 * w && z >= 100 * x){
       y = 0 - y;
      }
       else{
       x = x + 1;
       y = y + 100;
      }
       w = w + 1;
       z = z + 10;
      }

  }
