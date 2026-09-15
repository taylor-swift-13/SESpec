int unknown();

/*@ 
  assigns \nothing;
*/
void foo187() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

    /*@
      loop assigns x, y, z, w;
      loop invariant w >= 0;
      loop invariant z == 10 * w;
      loop invariant x >= 0;
      loop invariant x <= w;
      loop variant 0;
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
