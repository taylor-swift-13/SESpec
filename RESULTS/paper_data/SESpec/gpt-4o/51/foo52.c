
void foo52() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

    /*@
      loop invariant x >= 0;
      loop invariant y >= -100 * w; // Adjusted to account for possible negative values of y
      loop invariant z >= 0;
      loop invariant w >= 0;
      loop invariant z == 10 * w;
      loop invariant x <= w + 1; // x increases by 1 per iteration
      loop invariant y <= 100 * w; // y increases by at most 100 per iteration
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
