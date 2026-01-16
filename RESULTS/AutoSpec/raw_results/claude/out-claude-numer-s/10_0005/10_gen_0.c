//svcomp_const_1-1
int hoo10(){

    //pre-condition
    int x = 1;
    int y = 0;
    
    //loop-body
    /*@
    loop invariant 0 <= y <= 1024;
    loop invariant x == 0;
    loop assigns x, y;
    */
    while (y < 1024) {
        x = 0;
        y = y + 1;
    }

    //post-condition
    /*@ assert x == 0; */
}