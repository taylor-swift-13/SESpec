//svcomp_odd
int hoo9(){

    //pre-condition
    int x = 1;

    //loop-body
    /*@
    loop invariant x % 2 == 1;
    loop assigns x;
    */
    while(unknown()){
        x = x + 2;
    }

    //post-condition
    /*@ assert x % 2 == 1; */
    
}