//svcomp_benchmark47_linear
int unknown();
/*@
  requires x < y;
  requires y <= 20000001;
*/
int hoo17(int x,int y){
    

    //pre-condition
    //loop-body
    /*@
    loop invariant x < y;
    loop invariant x < y + 16;
    loop assigns y;
    loop assigns x;
    */
    while (x < y) {
        if (x < 0){
            x = x + 7; 
        }
        else {
            x = x + 10;
        }
        if (y < 0){
            y = y - 10;
        } 
        else {
            y = y + 3;
        }

    }

    //post-condition
    /*@ assert x <= y + 16; */
}