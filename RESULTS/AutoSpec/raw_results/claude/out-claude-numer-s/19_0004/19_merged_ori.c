//svcomp_Mono4_1
int unknown();

int hoo19(){
    int x = 0;
    int y = 500000;

    //loop-body
    /*@
    loop invariant y == 500000 || y == 500000 + (x - 500000 < 0 ? 0 : x - 500000);
    loop invariant x <= 1000000;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while(x < 1000000) {
	    if (x < 500000) {
	        x = x + 1;
	    } 
        else {
            x = x + 1;
            y = y + 1;
	    }
    }

    //post-condition
    /*@ assert y == x; */
}