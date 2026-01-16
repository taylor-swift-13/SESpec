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