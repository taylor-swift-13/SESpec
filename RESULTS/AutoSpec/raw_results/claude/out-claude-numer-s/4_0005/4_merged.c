//svcomp_eq1
int unknown();
/*@
  requires x > 0;
  requires y > 0;
  requires z > 0;
  requires w > 0;
*/
int hoo4(int a,int w,int x,int y,int z) {

    //pre-condition
    x = w;
    z = y;
   

    /*@
    loop invariant z == y;
    loop invariant y >= 0 && z >= 0;
    loop invariant w >= 0 && x >= 0 && y >= 0 && z >= 0;
    loop invariant w == x;
    loop assigns z;
    loop assigns y;
    loop assigns x;
    loop assigns w;
    */
    while(unknown()) {
        if (unknown()) {
            w = w + 1; 
            x = x + 1;
        } 
        else {
            y = y - 1; 
            z = z - 1;
        }
    }

    //post-condition
    /*@ assert w == x; */
}