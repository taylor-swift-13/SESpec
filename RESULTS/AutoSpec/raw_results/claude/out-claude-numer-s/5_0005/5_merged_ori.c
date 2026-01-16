//svcomp_eq1
/*@
  requires x > 0;
  requires y > 0;
  requires z > 0;
  requires w > 0;
*/
int hoo5(int a,int w,int x,int y,int z) {
    //pre-condition
    x = w;
    z = y;
 
    /*@
    loop invariant y >= 0 && z >= 0;
    loop invariant y == z;
    loop invariant x - w == 0;
    loop invariant w <= x;
    loop assigns z;
    loop assigns y;
    loop assigns x;
    loop assigns w;
    loop assigns \nothing;
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
    /*@ assert y == z; */
}