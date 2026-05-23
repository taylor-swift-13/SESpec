int unknown();

/*@
    assigns \nothing;
    ensures \true; // No specific postcondition since the function behavior is unknown.
*/
int unknown();

void foo188() {

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
        loop invariant y >= 0;
        loop invariant z >= 0;
        loop invariant w >= 0;
        loop assigns x, y, z, w;
        loop variant w; // Assuming w increases monotonically.
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
