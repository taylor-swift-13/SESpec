
/*@
  predicate all_zero(int x, int y, int z, int w) = (x == 0) && (y == 0) && (z == 0) && (w == 0);
*/

int unknown();

void foo168_c51() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

    /*@
      loop invariant 0 <= w;
      loop invariant 0 <= x <= w;        // x increments by at most 1 per iteration, starts at 0
      loop invariant z == 10 * w;        // z increases by 10 each iteration, starts at 0
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
